//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UpravljanjeCrnomListom.h"
#include <System.DateUtils.hpp>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "siComp"
#pragma link "siLngLnk"
#pragma link "frCoreClasses"
#pragma link "frxClass"
#pragma link "frxDBSet"
#pragma resource "*.dfm"
TFUpravljanjeCrnomListom *FUpravljanjeCrnomListom;
//---------------------------------------------------------------------------

__fastcall TFUpravljanjeCrnomListom::TFUpravljanjeCrnomListom(TComponent* Owner)
	: TForm(Owner)
{
	//postavljanje najstarijeg datuma iz crne liste na DateTimePicker
	ADOQuery1->SQL->Text = "SELECT MIN(datum) AS najstarijiDatum FROM crna_lista";
	ADOQuery1->Open();
	DTPOd->Date = ADOQuery1->FieldByName("najstarijiDatum")->AsDateTime;
}
//---------------------------------------------------------------------------
void __fastcall TFUpravljanjeCrnomListom::BSortirajClick(TObject *Sender)
{
	String sortiranje = "";

	if (RBid->Checked)
		sortiranje = "id";

	else if (RBtermin_id->Checked)
		sortiranje = "termin_id";

	else if (RBrazlog->Checked)
		sortiranje = "razlog";

	else if (RBdatum->Checked)
		sortiranje = "datum";

	if (CBSilazno->Checked)
		sortiranje += " DESC";

	ADOTCrnaLista->Sort = sortiranje;

}
//---------------------------------------------------------------------------
void __fastcall TFUpravljanjeCrnomListom::EidChange(TObject *Sender)
{
	 String id = Eid->Text.Trim();

	 if (id.IsEmpty())
	 {
		Eid->Text = "";
		ADOTCrnaLista->Filtered = false;
		return;
	 }

	ADOTCrnaLista->Filter = "id = " + id;
	ADOTCrnaLista->Filtered = true;
}
//---------------------------------------------------------------------------

void __fastcall TFUpravljanjeCrnomListom::Etermin_idChange(TObject *Sender)
{
	 String termin_id = Etermin_id->Text.Trim();

	 if (termin_id.IsEmpty())
	 {
		Etermin_id->Text = "";
		ADOTCrnaLista->Filtered = false;
		return;
	 }

	ADOTCrnaLista->Filter = "termin_id = " + termin_id;
	ADOTCrnaLista->Filtered = true;
}
//---------------------------------------------------------------------------

void __fastcall TFUpravljanjeCrnomListom::ErazlogChange(TObject *Sender)
{
	 String razlog = Erazlog->Text.Trim();

	 if (razlog.IsEmpty())
	 {
		Erazlog->Text = "";
		ADOTCrnaLista->Filtered = false;
		return;
	 }

	ADOTCrnaLista->Filter = "razlog LIKE '*" + razlog + "*'";
	ADOTCrnaLista->Filtered = true;
}
//---------------------------------------------------------------------------


void __fastcall TFUpravljanjeCrnomListom::DTPOdChange(TObject *Sender)
{
	ADOTCrnaLista->Filter =
		"datum >= #" + DTPOd->Date.FormatString("yyyy-mm-dd") +
		"# AND datum <= #" + DTPDo->Date.FormatString("yyyy-mm-dd") + "#";

	ADOTCrnaLista->Filtered = true;
}
//---------------------------------------------------------------------------

void __fastcall TFUpravljanjeCrnomListom::DTPDoChange(TObject *Sender)
{
	ADOTCrnaLista->Filter =
		"datum >= #" + DTPOd->Date.FormatString("yyyy-mm-dd") +
		"# AND datum <= #" + DTPDo->Date.FormatString("yyyy-mm-dd") + "#";

	ADOTCrnaLista->Filtered = true;
}
//---------------------------------------------------------------------------

void __fastcall TFUpravljanjeCrnomListom::BPonistiFiltereClick(TObject *Sender)
{
	ADOQuery1->SQL->Text = "SELECT MIN(datum) AS najstarijiDatum FROM crna_lista";
	ADOQuery1->Open();
	DTPOd->Date = ADOQuery1->FieldByName("najstarijiDatum")->AsDateTime;
	DTPDo->Date = Date();
	Eid->Clear();
	Etermin_id->Clear();
	Erazlog->Clear();

}
//---------------------------------------------------------------------------

void __fastcall TFUpravljanjeCrnomListom::ADOTCrnaListaCalcFields(TDataSet *DataSet)

{
	ADOTCrnaListaDananacrnojlisti->AsInteger =  DaysBetween(Date(), ADOTCrnaListadatum->AsDateTime);
}
//---------------------------------------------------------------------------


void __fastcall TFUpravljanjeCrnomListom::BIzvjesceClick(TObject *Sender)
{
	frxReport1->ShowReport();
}
//---------------------------------------------------------------------------

