//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Login.h"
#include "Glavna.h"
#include "Korisnik.h"
#include <uTPLb_Hash.hpp>
#include <uTPLb_HashDsc.hpp>
#include <uTPLb_StreamUtils.hpp>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "siComp"
#pragma link "siLangCombo"
#pragma link "uTPLb_BaseNonVisualComponent"
#pragma link "uTPLb_Hash"
#pragma link "uTPLb_CryptographicLibrary"
#pragma resource "*.dfm"

TFPrijava *FPrijava;
//---------------------------------------------------------------------------
__fastcall TFPrijava::TFPrijava(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFPrijava::GPrijavaClick(TObject *Sender)
{
	if (EKor_ime->Text.Trim().IsEmpty() || ELozinka->Text.Trim().IsEmpty())
	{
		ShowMessage(siLang_FPrijava->GetText("NISTE_UNJELI"));
        return;
    }

    try
    {
		// dohvati hash iz baze
        ADOQuery1->SQL->Clear();
        ADOQuery1->SQL->Add(
            "SELECT id, kor_ime, lozinka, role "
            "FROM korisnici "
            "WHERE kor_ime = :u"
        );

        ADOQuery1->Parameters->ParamByName("u")->Value = EKor_ime->Text;
        ADOQuery1->Open();

        if (ADOQuery1->RecordCount == 0)
        {
            ShowMessage(siLang_FPrijava->GetText("KRIVO"));
			return;
        }

        String hashIzBaze = ADOQuery1->FieldByName("lozinka")->AsString;

		// generiraj sol
        String korIme = EKor_ime->Text.Trim();
		String salt = korIme + IntToStr(korIme.Length()) + "GumeZelinaPlaner2026RINF";

		//prolazak kroz pepper dok se ne nade pravi
		bool ok = false;

        for (int p = 0; p <= 100; p++)
		{
            String podaciZaHash = salt + ELozinka->Text.Trim() + IntToStr(p);

            Hash1->HashString(podaciZaHash, TEncoding::UTF8);
            String testHash = Stream_To_Hex(Hash1->HashOutputValue);

            if (testHash == hashIzBaze)
			{
				ok = true;
                break;
            }
		}

		if (!ok)
		{
			ShowMessage(siLang_FPrijava->GetText("KRIVO"));
			return;
		}

		//ako je ispravna lozinak spremi podatke
		FUserId = ADOQuery1->FieldByName("id")->AsInteger;
		FKorIme = korIme;
		FLozinka = ELozinka->Text.Trim();
		FRole = ADOQuery1->FieldByName("role")->AsString;

		ADOQuery1->Close();
		ModalResult = mrOk;
	}
	catch (Exception &e)
	{
		ShowMessage("Greška: " + e.Message);
	}
}

//---------------------------------------------------------------------------


void __fastcall TFPrijava::CBPrikaziClick(TObject *Sender)
{
	if(CBPrikazi->Checked == true)
	{
		ELozinka->PasswordChar = '\0';
	}
	else
		ELozinka->PasswordChar = '*';
}
//---------------------------------------------------------------------------

void __fastcall TFPrijava::ELozinkaKeyPress(TObject *Sender, System::WideChar &Key)

{
	if (Key==13)
	{
		GPrijavaClick(GPrijava);
		Key = 0;
	}
}
//---------------------------------------------------------------------------


