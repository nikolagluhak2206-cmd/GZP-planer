//---------------------------------------------------------------------------
#ifndef LoginH
#define LoginH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Data.DB.hpp>
#include <Data.Win.ADODB.hpp>
#include <Vcl.AppEvnts.hpp>
#include "siComp.h"
#include "siLangCombo.h"
#include "uTPLb_BaseNonVisualComponent.hpp"
#include "uTPLb_Hash.hpp"
#include "uTPLb_CryptographicLibrary.hpp"
//---------------------------------------------------------------------------
class TFPrijava : public TForm
{
__published:	// IDE-managed Components
	TGroupBox *GBPrijava;
	TLabel *LKor_ime;
	TLabel *LLozinka;
	TEdit *EKor_ime;
	TEdit *ELozinka;
	TButton *GPrijava;
	TADOConnection *ADOConnection1;
	TADOQuery *ADOQuery1;
	TsiLang *siLang_FPrijava;
	TsiLangDispatcher *siLangDispatcher1;
	TsiLangCombo *siLangCombo1;
	TCheckBox *CBPrikazi;
	THash *Hash1;
	TCryptographicLibrary *CryptographicLibrary1;
	void __fastcall GPrijavaClick(TObject *Sender);
	void __fastcall CBPrikaziClick(TObject *Sender);
	void __fastcall ELozinkaKeyPress(TObject *Sender, System::WideChar &Key);
private:
	int FUserId;
	String FKorIme;
	String FLozinka;
	String FRole;
public:
	__fastcall TFPrijava(TComponent* Owner);

	int    GetUserId()  { return FUserId;  }
	String GetKorIme()  { return FKorIme;  }
	String GetLozinka() { return FLozinka; }
    String GetRole() { return FRole; }
};
//---------------------------------------------------------------------------
extern PACKAGE TFPrijava *FPrijava;
//---------------------------------------------------------------------------
#endif
