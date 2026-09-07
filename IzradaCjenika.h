//---------------------------------------------------------------------------

#ifndef IzradaCjenikaH
#define IzradaCjenikaH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Xml.XMLDoc.hpp>
#include <Xml.xmldom.hpp>
#include <Xml.XMLIntf.hpp>
#include "frCoreClasses.hpp"
#include "frxClass.hpp"
#include "siComp.h"
#include "siLngLnk.h"
//---------------------------------------------------------------------------
class TFIzradaCjenika : public TForm
{
__published:	// IDE-managed Components
	TXMLDocument *XMLDokument;
	TListView *Lista;
	TEdit *ENaziv;
	TEdit *EKategorija;
	TEdit *ECijena;
	TComboBox *ComboAktivno;
	TLabel *LNaziv;
	TLabel *LKategorija;
	TLabel *LCijena;
	TLabel *Label4;
	TButton *BResetiraj;
	TButton *BDodaj;
	TButton *BUpdate;
	TButton *BObrisi;
	TfrxReport *frxReport1;
	TfrxUserDataSet *frxUserDataSet1;
	TButton *BIzvjesce;
	TCheckBox *CBAktivno;
	TsiLangLinked *siLangLinked_FIzradaCjenika;
	void __fastcall ListaChange(TObject *Sender, TListItem *Item, TItemChange Change);
	void __fastcall BResetirajClick(TObject *Sender);
	void __fastcall BDodajClick(TObject *Sender);
	void __fastcall BObrisiClick(TObject *Sender);
	void __fastcall BUpdateClick(TObject *Sender);
	void __fastcall frxUserDataSet1First(TObject *Sender);
	void __fastcall frxUserDataSet1Next(TObject *Sender);
	void __fastcall frxUserDataSet1CheckEOF(TObject *Sender, bool &Eof);
	void __fastcall frxUserDataSet1GetValue(const UnicodeString VarName, Variant &Value);
	void __fastcall BIzvjesceClick(TObject *Sender);
	void __fastcall CBAktivnoClick(TObject *Sender);


private:	// User declarations
public:		// User declarations
	__fastcall TFIzradaCjenika(TComponent* Owner);
	void ucitajXML();
	void odaberiRed();

};
//---------------------------------------------------------------------------
extern PACKAGE TFIzradaCjenika *FIzradaCjenika;
//---------------------------------------------------------------------------
#endif
