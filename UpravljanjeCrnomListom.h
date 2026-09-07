//---------------------------------------------------------------------------

#ifndef UpravljanjeCrnomListomH
#define UpravljanjeCrnomListomH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Data.DB.hpp>
#include <Data.Win.ADODB.hpp>
#include <Vcl.DBGrids.hpp>
#include <Vcl.Grids.hpp>
#include <Vcl.Buttons.hpp>
#include <Vcl.DBCtrls.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.CheckLst.hpp>
#include <Vcl.FileCtrl.hpp>
#include <Vcl.ComCtrls.hpp>
#include "siComp.h"
#include "siLngLnk.h"
#include "frCoreClasses.hpp"
#include "frxClass.hpp"
#include "frxDBSet.hpp"
//---------------------------------------------------------------------------
class TFUpravljanjeCrnomListom : public TForm
{
__published:	// IDE-managed Components
	TADOTable *ADOTCrnaLista;
	TDBGrid *DBGTablica;
	TDataSource *DSCrnaLista;
	TDBNavigator *DBNav;
	TADOTable *ADOTTermini;
	TDataSource *DSTermini;
	TDBGrid *DBGTablica1;
	TButton *BSortiraj;
	TRadioButton *RBid;
	TRadioButton *RBtermin_id;
	TRadioButton *RBrazlog;
	TRadioButton *RBdatum;
	TLabel *LSoritraj;
	TCheckBox *CBSilazno;
	TPanel *FilterPanel;
	TEdit *Eid;
	TLabel *Lid;
	TEdit *Erazlog;
	TEdit *Etermin_id;
	TLabel *Ltermin_id;
	TLabel *Lrazlog;
	TDateTimePicker *DTPOd;
	TDateTimePicker *DTPDo;
	TADOQuery *ADOQuery1;
	TLabel *LOd;
	TLabel *LDo;
	TButton *BPonistiFiltere;
	TAutoIncField *ADOTTerminiID;
	TDateTimeField *ADOTTerminidatum;
	TWideStringField *ADOTTerminiregistracija;
	TIntegerField *ADOTTerminikorisnik_id;
	TWideStringField *ADOTTerminivrijeme;
	TWideStringField *ADOTTerminiopis;
	TAutoIncField *ADOTCrnaListaID;
	TIntegerField *ADOTCrnaListatermin_id;
	TWideStringField *ADOTCrnaListarazlog;
	TDateTimeField *ADOTCrnaListadatum;
	TStringField *ADOTCrnaListaTerminRegistracija;
	TIntegerField *ADOTCrnaListaDananacrnojlisti;
	TsiLangLinked *siLangLinked_FUpravljanjeCrnomListom;
	TfrxReport *frxReport1;
	TfrxDBDataset *frxDBDatasetCrnaLista;
	TButton *BIzvjesce;
	TfrxDBDataset *frxDBDatasetTermini;
	void __fastcall BSortirajClick(TObject *Sender);
	void __fastcall EidChange(TObject *Sender);
	void __fastcall Etermin_idChange(TObject *Sender);
	void __fastcall ErazlogChange(TObject *Sender);
	void __fastcall DTPOdChange(TObject *Sender);
	void __fastcall DTPDoChange(TObject *Sender);
	void __fastcall BPonistiFiltereClick(TObject *Sender);
	void __fastcall ADOTCrnaListaCalcFields(TDataSet *DataSet);
	void __fastcall BIzvjesceClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TFUpravljanjeCrnomListom(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFUpravljanjeCrnomListom *FUpravljanjeCrnomListom;
//---------------------------------------------------------------------------
#endif
