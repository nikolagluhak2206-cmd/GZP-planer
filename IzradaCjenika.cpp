//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "IzradaCjenika.h"
#include "cjenik.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "frCoreClasses"
#pragma link "frxClass"
#pragma link "siComp"
#pragma link "siLngLnk"
#pragma resource "*.dfm"
TFIzradaCjenika *FIzradaCjenika;
//---------------------------------------------------------------------------
__fastcall TFIzradaCjenika::TFIzradaCjenika(TComponent* Owner)
	: TForm(Owner)
{
	ucitajXML();
}
//---------------------------------------------------------------------------
void TFIzradaCjenika::ucitajXML()
{
    _di_IXMLCjenikType Cjenik = GetCjenik(XMLDokument);

    Lista->Items->Clear();

    for (int i = 0; i < Cjenik->Count; i++)
	{
        if (CBAktivno->Checked && Cjenik->Usluga[i]->Get_Aktivno() != "DA")
			continue;

        TListItem* item = Lista->Items->Add();
        item->Caption = Cjenik->Usluga[i]->Get_Naziv();
        item->SubItems->Add(Cjenik->Usluga[i]->Get_Kategorija());
        item->SubItems->Add(Cjenik->Usluga[i]->Get_Cijena());
        item->SubItems->Add(Cjenik->Usluga[i]->Get_Aktivno());
	}
}

void TFIzradaCjenika::odaberiRed()
{
	TListItem* red = Lista->Selected;

	if (red)
	{
		ENaziv->Text = red->Caption;
		EKategorija->Text = red->SubItems->Strings[0];
		ECijena->Text = red->SubItems->Strings[1];

		if (red->SubItems->Strings[2] == "DA")
			ComboAktivno->ItemIndex = 0;
		else
            ComboAktivno->ItemIndex = 1;
	}

}
void __fastcall TFIzradaCjenika::ListaChange(TObject *Sender, TListItem *Item, TItemChange Change)

{
	odaberiRed();
}
//---------------------------------------------------------------------------
void __fastcall TFIzradaCjenika::BResetirajClick(TObject *Sender)
{
	ENaziv->Clear();
	EKategorija->Clear();
	ECijena->Clear();
	ComboAktivno->ItemIndex = -1;
    Lista->ItemIndex = -1;
}
//---------------------------------------------------------------------------
void __fastcall TFIzradaCjenika::BDodajClick(TObject *Sender)
{
	_di_IXMLCjenikType Cjenik = GetCjenik(XMLDokument);

	if (ENaziv->Text.Trim().IsEmpty() || EKategorija->Text.Trim().IsEmpty() || ECijena->Text.Trim().IsEmpty() || ComboAktivno->Text.Trim().IsEmpty() )
	{
		ShowMessage(siLangLinked_FIzradaCjenika->GetText("SVA_POLJA"));
		return;
	}
	_di_IXMLUslugaType Usluga = Cjenik->Add();

	Usluga->Naziv = ENaziv->Text;
	Usluga->Kategorija = EKategorija->Text;
	Usluga->Cijena = StrToFloat(ECijena->Text);
	Usluga->Aktivno = ComboAktivno->Text;

	XMLDokument->SaveToFile(XMLDokument->FileName);
	ucitajXML();
}
//---------------------------------------------------------------------------

void __fastcall TFIzradaCjenika::BObrisiClick(TObject *Sender)
{
	TListItem *red = Lista->Selected;

	if (!red)
	{
		ShowMessage(siLangLinked_FIzradaCjenika->GetText("BRISANJE"));
		return;
	}

	_di_IXMLCjenikType Cjenik = GetCjenik(XMLDokument);
	int index = red->Index;
	if (index >= 0 && index < Cjenik->Count)
    {
		Cjenik->Delete(index);
		XMLDokument->SaveToFile(XMLDokument->FileName);
		ucitajXML();
	}
}
//---------------------------------------------------------------------------

void __fastcall TFIzradaCjenika::BUpdateClick(TObject *Sender)
{
	TListItem* red = Lista->Selected;
    if (!red)
    {
		ShowMessage(siLangLinked_FIzradaCjenika->GetText("UREÐIVANJE"));
		return;
    }

	if (ENaziv->Text.Trim().IsEmpty() || EKategorija->Text.Trim().IsEmpty() || ECijena->Text.Trim().IsEmpty() || ComboAktivno->Text.Trim().IsEmpty())
	{
		ShowMessage(siLangLinked_FIzradaCjenika->GetText("SVA_POLJA"));
		return;
    }

    _di_IXMLCjenikType Cjenik = GetCjenik(XMLDokument);
    int index = red->Index;

    if (index >= 0 && index < Cjenik->Count)
    {
        _di_IXMLUslugaType Usluga = Cjenik->Usluga[index];

        Usluga->Naziv = ENaziv->Text;
        Usluga->Kategorija = EKategorija->Text;
        Usluga->Cijena = StrToFloat(ECijena->Text);
        Usluga->Aktivno = ComboAktivno->Text;

        XMLDokument->Options << doNodeAutoIndent;
        XMLDokument->SaveToFile(XMLDokument->FileName);

        ucitajXML();
	}
}
//---------------------------------------------------------------------------

int frIndex = 0;

void __fastcall TFIzradaCjenika::frxUserDataSet1First(TObject *Sender)
{
	frIndex = 0;
}
//---------------------------------------------------------------------------

void __fastcall TFIzradaCjenika::frxUserDataSet1Next(TObject *Sender)
{
	frIndex++;
}
//---------------------------------------------------------------------------

void __fastcall TFIzradaCjenika::frxUserDataSet1CheckEOF(TObject *Sender, bool &Eof)

{
	Eof = frIndex >= Lista->Items->Count;
}
//---------------------------------------------------------------------------

void __fastcall TFIzradaCjenika::frxUserDataSet1GetValue(const UnicodeString VarName,
		  Variant &Value)
{
	TListItem* item = Lista->Items->Item[frIndex];

    if (VarName == "Naziv")
        Value = item->Caption;

    else if (VarName == "Kategorija")
        Value = item->SubItems->Strings[0];

    else if (VarName == "Cijena")
        Value = item->SubItems->Strings[1];

    else if (VarName == "Aktivno")
		Value = item->SubItems->Strings[2];
}
//---------------------------------------------------------------------------

void __fastcall TFIzradaCjenika::BIzvjesceClick(TObject *Sender)
{
	frxReport1->ShowReport();
}
//---------------------------------------------------------------------------

void __fastcall TFIzradaCjenika::CBAktivnoClick(TObject *Sender)
{
	ucitajXML();
}
//---------------------------------------------------------------------------

