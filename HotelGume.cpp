//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "HotelGume.h"
#include <System.JSON.hpp>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "siComp"
#pragma link "siLngLnk"
#pragma link "frCoreClasses"
#pragma link "frxClass"
#pragma link "uTPLb_BaseNonVisualComponent"
#pragma link "uTPLb_Codec"
#pragma link "uTPLb_CryptographicLibrary"
#pragma resource "*.dfm"
TFHotelGume *FHotelGume;
//---------------------------------------------------------------------------
__fastcall TFHotelGume::TFHotelGume(TComponent* Owner)
	: TForm(Owner)
{
	SimetricniCodec->Password = "ovojejednajakkodugaitajnaporukakojunikonemozeprobitinaovomsvijetu";
	ucitajJSON();
	DatumZaprimanja->Date = Date();
}
//---------------------------------------------------------------------------
void __fastcall TFHotelGume::ListaChange(TObject *Sender, TListItem *Item, TItemChange Change)

{
	odaberiRed();
}
//---------------------------------------------------------------------------
 void TFHotelGume::ucitajJSON()
 {

	TStringStream* json = new TStringStream;
	json->LoadFromFile("HotelGume.json");

	TJSONObject* jsonDatoteka = (TJSONObject*)TJSONObject::ParseJSONValue(json->DataString);
	TJSONArray* jsonNiz = (TJSONArray*)TJSONObject::ParseJSONValue(jsonDatoteka->GetValue("HotelGume")->ToString());

	Lista->Items->Clear();
	for (int i=0; i <jsonNiz->Count; i++)
	{
	String dekriptiraniVlasnik;
	String dekriptiraniMobitel;

	String enkriptiraniVlasnik = jsonNiz->Items[i]->GetValue<UnicodeString>("vlasnik");
	String enkriptiraniMobitel = jsonNiz->Items[i]->GetValue<UnicodeString>("broj_mobitela");

	SimetricniCodec->DecryptString(dekriptiraniVlasnik, enkriptiraniVlasnik, TEncoding::UTF8);
	SimetricniCodec->DecryptString(dekriptiraniMobitel, enkriptiraniMobitel, TEncoding::UTF8);

	Lista->Items->Add();
	Lista->Items->Item[i]->Caption = dekriptiraniVlasnik;
	Lista->Items->Item[i]->SubItems->Add(dekriptiraniMobitel);
	Lista->Items->Item[i]->SubItems->Add(jsonNiz->Items[i]->GetValue<UnicodeString>("marka_dimenzije"));
	Lista->Items->Item[i]->SubItems->Add(jsonNiz->Items[i]->GetValue<UnicodeString>("lokacija"));
	Lista->Items->Item[i]->SubItems->Add(jsonNiz->Items[i]->GetValue<UnicodeString>("napomena"));
	Lista->Items->Item[i]->SubItems->Add(jsonNiz->Items[i]->GetValue<UnicodeString>("datum_zaprimanja"));
	}
	delete json;
	delete jsonDatoteka;
 }
 //---------------------------------------------------------------------------
 void TFHotelGume::odaberiRed()
 {
	 TListItem* red = Lista->Selected;

	 if(red)
	 {
		 EVlasnik->Text = red->Caption;
		 EBrojMobitela->Text = red->SubItems->Strings[0];
		 EMarkaDimenzija->Text = red->SubItems->Strings[1];
		 ELokacija->Text = red->SubItems->Strings[2];
		 ENapomena->Text = red->SubItems->Strings[3];
		 TDate datum = StrToDate(red->SubItems->Strings[4]);
		 DatumZaprimanja->Date = datum;
	 }

 }

//---------------------------------------------------------------------------

void __fastcall TFHotelGume::BResetClick(TObject *Sender)
{
	EVlasnik->Clear();
	EBrojMobitela->Clear();
	EMarkaDimenzija->Clear();
	ELokacija->Clear();
	ENapomena->Clear();
	DatumZaprimanja->Date = Date();
	Lista->ItemIndex = -1;
}
//---------------------------------------------------------------------------

void __fastcall TFHotelGume::BDodajClick(TObject *Sender)
{
	spremiJSON();
	ucitajJSON();
}
//---------------------------------------------------------------------------
void TFHotelGume::spremiJSON()
{
	if(!EVlasnik->Text.Trim().IsEmpty() && !EBrojMobitela->Text.Trim().IsEmpty())
	{
		TStringStream *stream = new TStringStream;
		stream->LoadFromFile("HotelGume.json");

		TJSONObject *root = (TJSONObject*)TJSONObject::ParseJSONValue(stream->DataString);
		TJSONArray *niz = (TJSONArray*)root->GetValue("HotelGume");
		TJSONObject *novi = new TJSONObject();

		String enkriptiraniVlasnik;
		String enkriptiraniMobitel;

		SimetricniCodec->EncryptString(EVlasnik->Text, enkriptiraniVlasnik, TEncoding::UTF8);
		SimetricniCodec->EncryptString(EBrojMobitela->Text, enkriptiraniMobitel, TEncoding::UTF8);

		novi->AddPair("vlasnik", enkriptiraniVlasnik);
		novi->AddPair("broj_mobitela", enkriptiraniMobitel);
		novi->AddPair("marka_dimenzije", EMarkaDimenzija->Text);
		novi->AddPair("lokacija", ELokacija->Text);
		novi->AddPair("napomena", ENapomena->Text);
		novi->AddPair("datum_zaprimanja", DateToStr(DatumZaprimanja->Date));

		niz->AddElement(novi);

		TStringList *izlaz = new TStringList;
		izlaz->Text = root->Format(2);
		izlaz->SaveToFile("HotelGume.json");

		delete izlaz;
		delete root;
		delete stream;
	}
	else
	{
		ShowMessage(siLangLinked_FHotelGume->GetText("UNESITE_OBAVEZNA_POLJA"));
		return;
	}

}
//---------------------------------------------------------------------------
void TFHotelGume::updateJSON()
{


	TStringStream *stream = new TStringStream;
    stream->LoadFromFile("HotelGume.json");

	TJSONObject *root = (TJSONObject*)TJSONObject::ParseJSONValue(stream->DataString);
	TJSONArray *niz = (TJSONArray*)root->GetValue("HotelGume");
	TJSONObject *obj = (TJSONObject*)niz->Items[Lista->ItemIndex];

	String enkriptiraniVlasnik;
	String enkriptiraniMobitel;
	SimetricniCodec->EncryptString(EVlasnik->Text, enkriptiraniVlasnik, TEncoding::UTF8);
	SimetricniCodec->EncryptString(EBrojMobitela->Text, enkriptiraniMobitel, TEncoding::UTF8);

    obj->RemovePair("vlasnik");
	obj->AddPair("vlasnik", enkriptiraniVlasnik);

    obj->RemovePair("broj_mobitela");
	obj->AddPair("broj_mobitela", enkriptiraniMobitel);

    obj->RemovePair("marka_dimenzije");
	obj->AddPair("marka_dimenzije", EMarkaDimenzija->Text);

    obj->RemovePair("lokacija");
    obj->AddPair("lokacija", ELokacija->Text);

    obj->RemovePair("napomena");
    obj->AddPair("napomena", ENapomena->Text);

    obj->RemovePair("datum_zaprimanja");
    obj->AddPair("datum_zaprimanja", DateToStr(DatumZaprimanja->Date));

    TStringList *izlaz = new TStringList;
    izlaz->Text = root->Format(2);
    izlaz->SaveToFile("HotelGume.json");

    delete izlaz;
    delete root;
	delete stream;
}
void __fastcall TFHotelGume::BUpdateClick(TObject *Sender)
{
	if(Lista->ItemIndex == -1)
	{
		ShowMessage(siLangLinked_FHotelGume->GetText("ODABERITE_ZAPIS"));
		return;
	}
	updateJSON();
	ucitajJSON();
}
//---------------------------------------------------------------------------
void TFHotelGume::obrisiJSON()
{

    TStringStream *stream = new TStringStream;
    stream->LoadFromFile("HotelGume.json");

	TJSONObject *root = (TJSONObject*)TJSONObject::ParseJSONValue(stream->DataString);
	TJSONArray *niz = (TJSONArray*)root->GetValue("HotelGume");

    niz->Remove(Lista->ItemIndex);

	TStringList *izlaz = new TStringList;
	izlaz->Text = root->Format(2);
	izlaz->SaveToFile("HotelGume.json");

    delete izlaz;
    delete root;
	delete stream;
}
void __fastcall TFHotelGume::BObrisiClick(TObject *Sender)
{
	if(Lista->ItemIndex == -1)
	{
		ShowMessage(siLangLinked_FHotelGume->GetText("ODABERITE_ZAPIS"));
		return;
	}
	obrisiJSON();
	ucitajJSON();

	EVlasnik->Clear();
	EBrojMobitela->Clear();
	EMarkaDimenzija->Clear();
	ELokacija->Clear();
	ENapomena->Clear();
	DatumZaprimanja->Date = Date();
	Lista->ItemIndex = -1;
}
//---------------------------------------------------------------------------
void TFHotelGume::pretraga(String tekst)
{
	for(int i = 0; i < Lista->Items->Count; i++)
	{
		TListItem* item = Lista->Items->Item[i];

		// prvo stupac (Caption)
		if(item->Caption.Pos(tekst) > 0)
		{
			Lista->ItemIndex = i;
			Lista->Selected->MakeVisible(true);
			return;
		}

		// zatim svi SubItems
		for(int s = 0; s < item->SubItems->Count; s++)
		{
			if(item->SubItems->Strings[s].Pos(tekst) > 0)
			{
				Lista->ItemIndex = i;
				Lista->Selected->MakeVisible(true);
				return;
			}
		}
	}

}

void __fastcall TFHotelGume::EPretragaChange(TObject *Sender)
{
	pretraga(EPretraga->Text);
}
//---------------------------------------------------------------------------

void __fastcall TFHotelGume::BPotvrdaClick(TObject *Sender)
{
	TListItem* red = Lista->Selected;

	if (!red)
	{
		ShowMessage(siLangLinked_FHotelGume->GetText("ODABERITE_ZAPIS"));
        return;
	}

    frxReport1->ShowReport();
}
//---------------------------------------------------------------------------

int frIndex = 0;


void __fastcall TFHotelGume::frxUserDataSet1First(TObject *Sender)
{
    frIndex = 0;
}
//---------------------------------------------------------------------------

void __fastcall TFHotelGume::frxUserDataSet1CheckEOF(TObject *Sender, bool &Eof)
{
    Eof = frIndex > 0;
}
//---------------------------------------------------------------------------

void __fastcall TFHotelGume::frxUserDataSet1GetValue(const UnicodeString VarName,
          Variant &Value)
{
	TListItem* red = Lista->Selected;
	if (!red) return;

    if (VarName == "Vlasnik")
		Value = red->Caption;

	else if (VarName == "Broj mobitela")
		Value = red->SubItems->Strings[0];

	else if (VarName == "Marka/dimenzije")
		Value = red->SubItems->Strings[1];

	else if (VarName == "Lokacija")
		Value = red->SubItems->Strings[2];

	else if (VarName == "Napomena")
		Value = red->SubItems->Strings[3];

	else if (VarName == "Datum zaprimanja")
	{
		Value = red->SubItems->Strings[4];
	}
}
//---------------------------------------------------------------------------

void __fastcall TFHotelGume::frxUserDataSet1Next(TObject *Sender)
{
	frIndex++;
}
//---------------------------------------------------------------------------




