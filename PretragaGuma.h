//---------------------------------------------------------------------------

#ifndef PretragaGumaH
#define PretragaGumaH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <System.Net.HttpClient.hpp>
#include <System.Net.HttpClientComponent.hpp>
#include <System.Net.URLClient.hpp>
#include <System.JSON.hpp>
#include "siComp.h"
#include "siLngLnk.h"
//---------------------------------------------------------------------------
class TFPretragaGuma : public TForm
{
__published:	// IDE-managed Components
	TNetHTTPClient *NetHTTPClient1;
	TComboBox *ComboGodinaProizvodnje;
	TComboBox *ComboMake;
	TComboBox *ComboModel;
	TComboBox *ComboTrim;
	TMemo *Memo1;
	TButton *BReset;
	TsiLangLinked *siLangLinked_FPretragaGuma;
	void __fastcall ComboGodinaProizvodnjeChange(TObject *Sender);
	void __fastcall ComboMakeChange(TObject *Sender);
	void __fastcall ComboModelChange(TObject *Sender);
	void __fastcall ComboTrimChange(TObject *Sender);
	void __fastcall BResetClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TFPretragaGuma(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFPretragaGuma *FPretragaGuma;
//---------------------------------------------------------------------------
#endif
