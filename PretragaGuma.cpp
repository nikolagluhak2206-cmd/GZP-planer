//---------------------------------------------------------------------------
// potrebno se registrirati na https://tire.vdim.app i dobiti besplatni api kljuc i onda ga ubaciti u NetHTTPClient1->CustomHeaders["x-api-key"]
//inace api ključ ne smije biti u kodu ali za potrebe demonstracije je dovoljno
#include <vcl.h>
#pragma hdrstop

#include "PretragaGuma.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "siComp"
#pragma link "siLngLnk"
#pragma resource "*.dfm"
TFPretragaGuma *FPretragaGuma;
//---------------------------------------------------------------------------
__fastcall TFPretragaGuma::TFPretragaGuma(TComponent* Owner)
	: TForm(Owner)
{
	//ubaci api kljuc
	NetHTTPClient1->CustomHeaders["x-api-key"] = "";
	String url = "https://tire.vdim.app/api/v1/search_allyear";

	auto response = NetHTTPClient1->Get(url);
	String json = response->ContentAsString();

	// Parsiranje JSON objekta
	TJSONObject* obj = (TJSONObject*)TJSONObject::ParseJSONValue(json);
	TJSONArray* arr = (TJSONArray*)obj->GetValue("data");

	ComboGodinaProizvodnje->Items->Clear();

	for (int i = 0; i < arr->Count; i++)
	{
		// svaki element objekt, rucno castati
		TJSONObject* yearObj = (TJSONObject*)arr->Items[i];

		String year = yearObj->GetValue("year")->Value();

		ComboGodinaProizvodnje->Items->Add(year);
	}

	delete obj;
}
//---------------------------------------------------------------------------
void __fastcall TFPretragaGuma::ComboGodinaProizvodnjeChange(TObject *Sender)
{
    String year = ComboGodinaProizvodnje->Text;
		//ubaci api kljuc
	NetHTTPClient1->CustomHeaders["x-api-key"] ="";

    String url = "https://tire.vdim.app/api/v1/search_allmake?year=" + year;

    auto response = NetHTTPClient1->Get(url);
	String json = response->ContentAsString();
    TJSONObject* obj = (TJSONObject*)TJSONObject::ParseJSONValue(json);
    TJSONArray* arr = (TJSONArray*)obj->GetValue("data");

    ComboMake->Items->Clear();

    for (int i = 0; i < arr->Count; i++)
    {
        TJSONObject* makeObj = (TJSONObject*)arr->Items[i];
        String make = makeObj->GetValue("make")->Value();
		ComboMake->Items->Add(make);
	}

	delete obj;
}
//---------------------------------------------------------------------------
void __fastcall TFPretragaGuma::ComboMakeChange(TObject *Sender)
{
	String year = ComboGodinaProizvodnje->Text;
    String make = ComboMake->Text;
		//ubaci api kljuc
	NetHTTPClient1->CustomHeaders["x-api-key"] = "";

	String url = "https://tire.vdim.app/api/v1/by_vehicle/model?year=" + year +
				 "&make=" + make;

	auto response = NetHTTPClient1->Get(url);
	String json = response->ContentAsString();

    TJSONObject* obj = (TJSONObject*)TJSONObject::ParseJSONValue(json);
	if (!obj) return;


    TJSONValue* dataVal = obj->GetValue("data");
	if (!dataVal)
	{
		delete obj;
		return;
	}

	TJSONObject* dataObj = (TJSONObject*)dataVal;

	ComboModel->Items->Clear();

	for (int i = 0; i < dataObj->Count; i++)
	{
		TJSONPair* pair = dataObj->Pairs[i];

		TJSONObject* modelObj = (TJSONObject*)pair->JsonValue;
		if (!modelObj) continue;

		TJSONValue* modelVal = modelObj->GetValue("model");
		if (!modelVal) continue;

		ComboModel->Items->Add(modelVal->Value());
	}

	delete obj;
}
//---------------------------------------------------------------------------
void __fastcall TFPretragaGuma::ComboModelChange(TObject *Sender)
{
	String year = ComboGodinaProizvodnje->Text;
	String make = ComboMake->Text;
	String model = ComboModel->Text;
		//ubaci api kljuc
	NetHTTPClient1->CustomHeaders["x-api-key"] = "";

	String url = "https://tire.vdim.app/api/v1/by_vehicle/trim?year=" + year +
				 "&make=" + make + "&model=" + model;

	auto response = NetHTTPClient1->Get(url);
	String json = response->ContentAsString();

	TJSONObject* obj = (TJSONObject*)TJSONObject::ParseJSONValue(json);
	if (!obj) return;

	TJSONValue* dataVal = obj->GetValue("data");
	if (!dataVal) {
		delete obj;
		return;
	}

	TJSONObject* dataObj = (TJSONObject*)dataVal;

	ComboTrim->Items->Clear();

	for (int i = 0; i < dataObj->Count; i++)
	{
		TJSONPair* pair = dataObj->Pairs[i];

		TJSONObject* trimObj = (TJSONObject*)pair->JsonValue;
		if (!trimObj) continue;

		TJSONValue* trimVal = trimObj->GetValue("trim");
		if (!trimVal) continue;

		ComboTrim->Items->Add(trimVal->Value());
	}

	delete obj;
}

//---------------------------------------------------------------------------
void __fastcall TFPretragaGuma::ComboTrimChange(TObject *Sender)
{
    String year = ComboGodinaProizvodnje->Text;
	String make = ComboMake->Text;
	String model = ComboModel->Text;
	String trim = ComboTrim->Text;
    	//ubaci api kljuc
	NetHTTPClient1->CustomHeaders["x-api-key"] = "";
	String url = "https://tire.vdim.app/api/v1/by_vehicle/tiresize?year=" + year + "&make=" + make + "&model=" + model + "&trim=" + trim;

	auto response = NetHTTPClient1->Get(url);
	String json = response->ContentAsString();



	TJSONObject* obj = (TJSONObject*)TJSONObject::ParseJSONValue(json);
	if (!obj) return;

	TJSONValue* dataVal = obj->GetValue("data");
	if (!dataVal)
	{
		delete obj;
		return;
	}

	TJSONObject* dataObj = (TJSONObject*)dataVal;

	Memo1->Lines->Clear();
	for (int i = 0; i < dataObj->Count; i++)
	{
		TJSONPair* pair = dataObj->Pairs[i];

		TJSONObject* tireObj = (TJSONObject*)pair->JsonValue;
		if (!tireObj) continue;

		TJSONValue* tireVal = tireObj->GetValue("tiresize");
		if (!tireVal) continue;

		Memo1->Lines->Add(tireVal->Value());
	}

	delete obj;
}
//---------------------------------------------------------------------------
void __fastcall TFPretragaGuma::BResetClick(TObject *Sender)
{
	ComboModel->Clear();
	ComboMake->Clear();
	ComboTrim->Clear();
    Memo1->Clear();
}
//---------------------------------------------------------------------------
