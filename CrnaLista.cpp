//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "CrnaLista.h"
#include "Postavke_reg.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "siComp"
#pragma link "siLngLnk"
#pragma resource "*.dfm"
TFCrnaListaDialog *FCrnaListaDialog;
//---------------------------------------------------------------------------
__fastcall TFCrnaListaDialog::TFCrnaListaDialog(TComponent* Owner)
    : TForm(Owner)
{
	FTerminId = -1;
    FRegistracija = "";
    LOpis->Caption = "Dodavanje registracije na crnu listu";
}
//---------------------------------------------------------------------------
void TFCrnaListaDialog::SetPodaci(int terminId, const String& registracija)
{
	FTerminId = terminId;
    FRegistracija  = registracija;
    LOpis->Caption = siLangLinked_FCrnaListaDialog->GetText("LOpis") + registracija;
}
//---------------------------------------------------------------------------
void __fastcall TFCrnaListaDialog::BDodajClick(TObject *Sender)
{
    if(ERazlog->Text.Trim().IsEmpty())
    {
		ShowMessage(siLangLinked_FCrnaListaDialog->GetText("LRazlog"));
        return;
    }

    if(FTerminId == -1)
    {
		ShowMessage(siLangLinked_FCrnaListaDialog->GetText("NIJE_POSTAVLJEN"));
		return;
    }

    try
    {   //INSERT za tablicu crna_lista
        ADOQuery1->Close();
        ADOQuery1->SQL->Text =
            "INSERT INTO crna_lista (termin_id, razlog, datum) "
			"VALUES (:tid, :r, :d)";

        ADOQuery1->Parameters->ParamByName("tid")->DataType = ftInteger;
		ADOQuery1->Parameters->ParamByName("tid")->Value = FTerminId;
		ADOQuery1->Parameters->ParamByName("r")->Value = ERazlog->Text.Trim();
		ADOQuery1->Parameters->ParamByName("d")->DataType = ftDate;
		ADOQuery1->Parameters->ParamByName("d")->Value = Date();

        ADOQuery1->ExecSQL();

        ShowMessage(siLangLinked_FCrnaListaDialog->GetText("REG") + FRegistracija + siLangLinked_FCrnaListaDialog->GetText("DODANA"));
        ModalResult = mrOk;
    }
    catch(Exception &e)
    {
		ShowMessage(siLangLinked_FCrnaListaDialog->GetText("ERR") + e.Message);
    }
}
//---------------------------------------------------------------------------
void __fastcall TFCrnaListaDialog::BOdustaniClick(TObject *Sender)
{
    ERazlog->Clear();
    ModalResult = mrCancel;
}
//---------------------------------------------------------------------------

