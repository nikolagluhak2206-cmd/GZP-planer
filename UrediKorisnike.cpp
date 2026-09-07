//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UrediKorisnike.h"
#include "Korisnik.h"
#include "Glavna.h"
#include <uTPLb_Hash.hpp>
#include <uTPLb_HashDsc.hpp>
#include <uTPLb_StreamUtils.hpp>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "siComp"
#pragma link "siLngLnk"
#pragma link "uTPLb_BaseNonVisualComponent"
#pragma link "uTPLb_CryptographicLibrary"
#pragma link "uTPLb_Hash"
#pragma resource "*.dfm"
TFUrediKorisnike *FUrediKorisnike;
//---------------------------------------------------------------------------
__fastcall TFUrediKorisnike::TFUrediKorisnike(TComponent* Owner)
	: TForm(Owner)
{
    UcitajKorisnikeUListView();
}
//---------------------------------------------------------------------------
void __fastcall TFUrediKorisnike::BOdustaniKorisnikClick(TObject *Sender)
{
	EKor_ime->Clear();
	ENovaPass->Clear();
	ENovaPassPonovno->Clear();
	CBRole->Clear();
	LVKorisnici->Items->Clear();
	ModalResult = mrCancel;
}
//---------------------------------------------------------------------------
void __fastcall TFUrediKorisnike::UcitajKorisnikeUListView()
{
	//SELECT za tablicu korsinici
    LVKorisnici->Items->Clear();

    ADOQuery1->Close();
	ADOQuery1->SQL->Text = "SELECT kor_ime, role FROM korisnici";
	ADOQuery1->Open();

    while(!ADOQuery1->Eof)
    {
        TListItem *item = LVKorisnici->Items->Add();
        item->Caption = ADOQuery1->FieldByName("kor_ime")->AsString;
        item->SubItems->Add(ADOQuery1->FieldByName("role")->AsString);

        ADOQuery1->Next();
    }

	ADOQuery1->Close();
}
//---------------------------------------------------------------------------
void __fastcall TFUrediKorisnike::BIzbrisiKorisnikaClick(TObject *Sender)
{
    if(LVKorisnici->Selected == nullptr)
	{
		MessageDlg(siLangLinked_FUrediKorisnike->GetText("ODABERITE_KORISNIKA_BRISANJE"), mtError, TMsgDlgButtons() << mbOK, 0);
		return;
	}

	//dohavti ime iz lsit viewa
	String ime = LVKorisnici->Selected->Caption;

	//ne briši prijavljenog
	if(ime == trenutniKorisnik->GetKor_ime())
    {
		MessageDlg(siLangLinked_FUrediKorisnike->GetText("NE_BRISI_PRIJAVLJENOG"), mtError, TMsgDlgButtons() << mbOK, 0);
		return;
    }

	//potvrda brisanja
	int odgovor = Application->MessageBox(
	siLangLinked_FUrediKorisnike->GetText("POTVRDA").c_str(),
	siLangLinked_FUrediKorisnike->GetText("UPOZORENJE").c_str(),
	MB_YESNO | MB_ICONWARNING
	);

	if (odgovor != IDYES)
		return;

	//DELETE za tablicu korisnici
	ADOQuery1->Close();
	ADOQuery1->SQL->Text = "DELETE FROM korisnici WHERE kor_ime = :ime";
	ADOQuery1->Parameters->ParamByName("ime")->Value = ime;
	ADOQuery1->ExecSQL();

	//refresh za listview
	UcitajKorisnikeUListView();
	EKor_ime->Clear();
	ENovaPass->Clear();
	ENovaPassPonovno->Clear();

	ShowMessage(siLangLinked_FUrediKorisnike->GetText("KORISNIK") + ime + siLangLinked_FUrediKorisnike->GetText("USPJESNO_OBRISAN"));
}
//---------------------------------------------------------------------------
void TFUrediKorisnike::SetTrenutniKorisnik(Korisnik* k)
{
    trenutniKorisnik = k;
}



void __fastcall TFUrediKorisnike::BSpremiClick(TObject *Sender)
{
    if (LVKorisnici->Selected == nullptr)
    {
        MessageDlg(siLangLinked_FUrediKorisnike->GetText("ODABERITE_KORISNIKA"), mtError, TMsgDlgButtons() << mbOK, 0);
        return;
    }

    String originalnoIme = LVKorisnici->Selected->Caption;
    String novoIme = EKor_ime->Text.Trim();
    String novaPass = ENovaPass->Text.Trim();
    String novaPassPonovno = ENovaPassPonovno->Text.Trim();
    String role = CBRole->Text.Trim();

	//Unjeti sva polja
    if (novoIme.IsEmpty() || novaPass.IsEmpty() || novaPassPonovno.IsEmpty() || role.IsEmpty())
    {
        MessageDlg(siLangLinked_FUrediKorisnike->GetText("UNESITE_SVA_POLJA"), mtError, TMsgDlgButtons() << mbOK, 0);
        return;
    }

	//lozinke se moraju podudarati
    if (novaPass != novaPassPonovno)
    {
        MessageDlg(siLangLinked_FUrediKorisnike->GetText("!PODUDARANJE"), mtError, TMsgDlgButtons() << mbOK, 0);
        return;
    }

	//admin user sa admin role ne moze postati user role
    if (trenutniKorisnik->GetId() == 16 && originalnoIme == trenutniKorisnik->GetKor_ime() && role == "user")
    {
        MessageDlg(siLangLinked_FUrediKorisnike->GetText("ADMIN_!USER"), mtError, TMsgDlgButtons() << mbOK, 0);
        return;
    }

    int odgovor = Application->MessageBox(
        siLangLinked_FUrediKorisnike->GetText("JESTE_LI_SIGURNI").c_str(),
        siLangLinked_FUrediKorisnike->GetText("UPOZORENJE").c_str(),
        MB_YESNO | MB_ICONWARNING
    );

    if (odgovor != IDYES)
        return;

	//Provjera jel postoji već korsinčiko ime u bazi
    if (novoIme != originalnoIme)
    {
        ADOQuery1->Close();
        ADOQuery1->SQL->Text = "SELECT kor_ime FROM korisnici WHERE kor_ime = :ime";
        ADOQuery1->Parameters->ParamByName("ime")->Value = novoIme;
        ADOQuery1->Open();

        if (!ADOQuery1->IsEmpty())
        {
            MessageDlg(siLangLinked_FUrediKorisnike->GetText("KORISNIK_POSTOJI"), mtError, TMsgDlgButtons() << mbOK, 0);
            return;
        }
    }

	//HASH lozinke, isto ko i kod inserta
    String sol = novoIme + IntToStr(novoIme.Length()) + "GumeZelinaPlaner2026RINF";
    int papar = Random(101);
    String podaciZaHash = sol + novaPass + IntToStr(papar);

    Hash1->HashString(podaciZaHash, TEncoding::UTF8);
    String hash_lozinka = Stream_To_Hex(Hash1->HashOutputValue);

	//UPDATE za tablicu korisnici
    ADOQuery1->Close();
    ADOQuery1->SQL->Text =
        "UPDATE korisnici SET kor_ime = :novoIme, lozinka = :loz, role = :role "
        "WHERE kor_ime = :staroIme";

    ADOQuery1->Parameters->ParamByName("novoIme")->Value = novoIme;
    ADOQuery1->Parameters->ParamByName("loz")->Value = hash_lozinka;
    ADOQuery1->Parameters->ParamByName("role")->Value = role;
    ADOQuery1->Parameters->ParamByName("staroIme")->Value = originalnoIme;

    ADOQuery1->ExecSQL();

    ShowMessage(siLangLinked_FUrediKorisnike->GetText("USPJESNO_IZMJENJENO") + novoIme);

    UcitajKorisnikeUListView();
    EKor_ime->Clear();
    ENovaPass->Clear();
    ENovaPassPonovno->Clear();
    CBRole->ItemIndex = -1;

}



//---------------------------------------------------------------------------
void __fastcall TFUrediKorisnike::ENovaPassPonovnoChange(TObject *Sender)
{   //ux gluposoti
	LPodudaranje->Visible = true;

	if (ENovaPassPonovno->Text.Trim().IsEmpty())
	{
		LPodudaranje->Visible = false;
	}

	if (ENovaPass->Text.Trim() == ENovaPassPonovno->Text.Trim())
	{
		LPodudaranje->Caption = siLangLinked_FUrediKorisnike->GetText("PODUDARANJE");
        LPodudaranje->Font->Color = clGreen;
	}
	else
	{
		LPodudaranje->Caption = siLangLinked_FUrediKorisnike->GetText("!PODUDARANJE");
        LPodudaranje->Font->Color = clRed;
	}
}
//---------------------------------------------------------------------------

void __fastcall TFUrediKorisnike::BOdaberiKorisnikaClick(TObject *Sender)
{
	ENovaPass->Clear();
	ENovaPassPonovno->Clear();
    if (LVKorisnici->Selected == nullptr)
    {
        MessageDlg(siLangLinked_FUrediKorisnike->GetText("ODABERITE_KORISNIKA"), mtError, TMsgDlgButtons() << mbOK, 0);
        return;
    }

    String ime = LVKorisnici->Selected->Caption;

    ADOQuery1->Close();
    ADOQuery1->SQL->Text = "SELECT kor_ime, role FROM korisnici WHERE kor_ime = :ime";
    ADOQuery1->Parameters->ParamByName("ime")->Value = ime;
    ADOQuery1->Open();

    EKor_ime->Text = ADOQuery1->FieldByName("kor_ime")->AsString;



    String role = ADOQuery1->FieldByName("role")->AsString;
    int idx = CBRole->Items->IndexOf(role);
    CBRole->ItemIndex = idx;
}

//---------------------------------------------------------------------------
