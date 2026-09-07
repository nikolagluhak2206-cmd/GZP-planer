//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "DodajKorisnika.h"
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
TFDodajKorisnika *FDodajKorisnika;
//---------------------------------------------------------------------------
__fastcall TFDodajKorisnika::TFDodajKorisnika(TComponent* Owner)
	: TForm(Owner)
{

}


void __fastcall TFDodajKorisnika::EPonoviPassChange(TObject *Sender)
{
	LPodudaranje->Visible = true;

	if (EPonoviPass->Text.Trim().IsEmpty())
	{
		LPodudaranje->Visible = false;
	}

	if (EPass->Text.Trim() == EPonoviPass->Text.Trim())
	{
		LPodudaranje->Caption = siLangLinked_FDodajKorisnika->GetText("PODUDARANJE");
		LPodudaranje->Font->Color = clGreen;
	}
	else
	{
		LPodudaranje->Caption = siLangLinked_FDodajKorisnika->GetText("!PODUDARANJE");
        LPodudaranje->Font->Color = clRed;
    }
}
//---------------------------------------------------------------------------
void __fastcall TFDodajKorisnika::BOdustaniKorisnikClick(TObject *Sender)
{
	EUsername->Clear();
	EPass->Clear();
	EPonoviPass->Clear();
	ModalResult = mrCancel;
}
//---------------------------------------------------------------------------
void __fastcall TFDodajKorisnika::BDodajKorisnikaClick(TObject *Sender)
{
	if (EUsername->Text.Trim().IsEmpty() || EPass->Text.Trim().IsEmpty() ||
		EPonoviPass->Text.Trim().IsEmpty())
	{
		MessageDlg (siLangLinked_FDodajKorisnika->GetText("NEPOTPUNI_PODACI")
		,mtError, TMsgDlgButtons() << mbOK, 0);
		EPass->Clear();
		EPonoviPass->Clear();
		return;
	}

	//spremiti u varijable podatke iz forme
	//napraviti logiku spajanja na bazu, čupanja podatka i usporedivanjem s varijablama,
	//ako podaci se podaci ne podudaraju, tj ako su unique prolazi petlju i moze ic insert u bazu
	String username = EUsername->Text.Trim();

	ADOQuery1->SQL->Clear();
	ADOQuery1->SQL->Add(
		"SELECT kor_ime FROM korisnici WHERE kor_ime = :ime"
	);

	ADOQuery1->Parameters->ParamByName("ime")->Value = username;
	ADOQuery1->Open();

	if (!ADOQuery1->IsEmpty())
	{
		MessageDlg(siLangLinked_FDodajKorisnika->GetText("KORISNIK_POSTOJI"), mtError, TMsgDlgButtons() << mbOK, 0);
		return;
	}

	if (EPass->Text != EPonoviPass->Text)
	{
		MessageDlg(siLangLinked_FDodajKorisnika->GetText("!PODUDARANJE"), mtError, TMsgDlgButtons() << mbOK, 0);
		return;
	}
	else
	{
        //INSERT za tablicu korsnici

		String promjenjivaSol = EUsername->Text + IntToStr(EUsername->Text.Length()) + "GumeZelinaPlaner2026RINF";
		int papar = Random(101);
		String lozinka = EPonoviPass->Text.Trim();
		String podaciZaHash = promjenjivaSol + lozinka + IntToStr(papar);

		Hash1->HashString(podaciZaHash, TEncoding::UTF8);
		String hash_lozinka = Stream_To_Hex(Hash1->HashOutputValue);

		ADOQuery1->SQL->Clear();
		ADOQuery1->SQL->Add("INSERT INTO korisnici (kor_ime, lozinka, role) VALUES (:ime, :l, :r)");

		ADOQuery1->Parameters->ParamByName("ime")->Value = username;
		ADOQuery1->Parameters->ParamByName("l")->Value = hash_lozinka;
		ADOQuery1->Parameters->ParamByName("r")->Value = CBRole->Text;

		ADOQuery1->ExecSQL();

		int rez = MessageDlg
		(
			siLangLinked_FDodajKorisnika->GetText("KORISNIK") + username + siLangLinked_FDodajKorisnika->GetText("INSERT_DB"),
			mtInformation,
			TMsgDlgButtons() << mbOK,
			0
		);
		// ako je kliknut OK → zatvori formu
		if (rez == mrOk)
		{
			ModalResult = mrOk;   // zatvara formu
		}
	}
}
//---------------------------------------------------------------------------
