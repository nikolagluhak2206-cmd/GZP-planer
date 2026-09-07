//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "PodaciPrijava.h"
#include <jpeg.hpp>
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
TFPodaciPrijava *FPodaciPrijava;
//---------------------------------------------------------------------------
__fastcall TFPodaciPrijava::TFPodaciPrijava(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void TFPodaciPrijava::setKorisnik(Korisnik* k)
{
	trenutniKorisnik = k;
	ucitajSliku();

	ADOQuery1->Close();
	ADOQuery1->SQL->Text = "SELECT kor_ime, lozinka, role FROM korisnici WHERE ID =:id";
	ADOQuery1->Parameters->ParamByName("id")->Value = trenutniKorisnik->GetId();
	ADOQuery1->Open();

	EKor_ime->Text = ADOQuery1->Fields->FieldByName("kor_ime")->AsString;

}

void TFPodaciPrijava::ucitajSliku()
{
	ADOQuery1->Close();
	ADOQuery1->SQL->Text = "SELECT slika_profila FROM korisnici WHERE id=:id";
	ADOQuery1->Parameters->ParamByName("id")->Value = trenutniKorisnik->GetId();
	ADOQuery1->Open();

	if (!ADOQuery1->FieldByName("slika_profila")->IsNull)
	{
		TBlobField *blob = static_cast<TBlobField*>(ADOQuery1->FieldByName("slika_profila"));
		TMemoryStream* stream = new TMemoryStream();

		blob->SaveToStream(stream);
		stream->Position = 0;

		Slika->Picture->LoadFromStream(stream);
		delete stream;
	}
	else
        Slika->Picture->LoadFromFile("gume_zelina.jpg");
}
void __fastcall TFPodaciPrijava::BOdaberiSlikuClick(TObject *Sender)
{
	if(OtvoriSlikuDialog->Execute())
	{
		Slika->Picture->LoadFromFile(OtvoriSlikuDialog->FileName);
	}
}
//---------------------------------------------------------------------------

void TFPodaciPrijava::spremiSliku()
{
    TMemoryStream* stream = new TMemoryStream();


        Slika->Picture->SaveToStream(stream);

        stream->Position = 0;

		ADOQuery1->Close();

        ADOQuery1->SQL->Text =
            "UPDATE korisnici SET slika_profila = :slika WHERE id = :id";

		ADOQuery1->Parameters->ParamByName("id")->Value =
			trenutniKorisnik->GetId();

		ADOQuery1->Parameters->ParamByName("slika")->LoadFromStream(
			stream,
			ftBlob
		);

		ADOQuery1->ExecSQL();
		delete stream;

}
//---------------------------------------------------------------------------
void TFPodaciPrijava::spremiPodatke()
{
    String staroIme = trenutniKorisnik->GetKor_ime();
    String novoIme = EKor_ime->Text.Trim();
    String novaLozinka = EPonoviPass->Text.Trim();

    if (novoIme.IsEmpty() || novaLozinka.IsEmpty())
    {
        ShowMessage(siLangLinked_FPodaciPrijava->GetText("UNESITE_PODATKE"));
        return;
    }

    if (EPass->Text != EPonoviPass->Text)
    {
        ShowMessage(siLangLinked_FPodaciPrijava->GetText("!PODUDARANJE"));
        return;
    }

    int odgovor = Application->MessageBox(
        siLangLinked_FPodaciPrijava->GetText("JESTE_LI_SIGURNI").c_str(),
        siLangLinked_FPodaciPrijava->GetText("UPOZORENJE").c_str(),
        MB_YESNO | MB_ICONWARNING
    );

    if (odgovor != IDYES)
        return;

    // Provjera da li novo korisnièko ime veæ postoji
    if (staroIme != novoIme)
    {
        ADOQuery1->Close();
        ADOQuery1->SQL->Text = "SELECT kor_ime FROM korisnici WHERE kor_ime = :ime";
        ADOQuery1->Parameters->ParamByName("ime")->Value = novoIme;
        ADOQuery1->Open();

        if (!ADOQuery1->IsEmpty())
        {
            ShowMessage(siLangLinked_FPodaciPrijava->GetText("KORISNICKO_IME_POSTOJI"));
            EKor_ime->Clear();
            return;
        }
    }

    // *** GENERIRANJE SOLI (identièno kao kod inserta) ***
    String promjenjivaSol = novoIme + IntToStr(novoIme.Length()) + "GumeZelinaPlaner2026RINF";

    // *** GENERIRANJE PAPRA ***
    int papar = Random(101);

	// *** HASHIRANJE ***
    String podaciZaHash = promjenjivaSol + novaLozinka + IntToStr(papar);

	Hash1->HashString(podaciZaHash, TEncoding::UTF8);
    String hash_lozinka = Stream_To_Hex(Hash1->HashOutputValue);

    // *** UPDATE BAZE ***
    ADOQuery1->Close();
    ADOQuery1->SQL->Text =
        "UPDATE korisnici SET kor_ime = :novoIme, lozinka = :hash WHERE ID = :id";

    ADOQuery1->Parameters->ParamByName("novoIme")->Value = novoIme;
    ADOQuery1->Parameters->ParamByName("hash")->Value = hash_lozinka;
    ADOQuery1->Parameters->ParamByName("id")->Value = trenutniKorisnik->GetId();
    ADOQuery1->ExecSQL();

    spremiSliku();

    ShowMessage(siLangLinked_FPodaciPrijava->GetText("USPJEH_PONOVNA_PRIJAVA"));

    EKor_ime->Clear();
    EPass->Clear();
    EPonoviPass->Clear();
    Application->Terminate();
}

//---------------------------------------------------------------------------
void __fastcall TFPodaciPrijava::BSpremiPostavkeClick(TObject *Sender)
{
	spremiPodatke();
}
//---------------------------------------------------------------------------

void __fastcall TFPodaciPrijava::BObrisiSlikuClick(TObject *Sender)
{
	Slika->Picture->Assign(nullptr);
	ADOQuery1->Close();
	ADOQuery1->SQL->Text = "UPDATE korisnici SET slika_profila = NULL WHERE id = :id_korisnika";
	ADOQuery1->Parameters->ParamByName("id_korisnika")->Value = trenutniKorisnik->GetId();
	ADOQuery1->ExecSQL();
}
//---------------------------------------------------------------------------

