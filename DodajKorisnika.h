//---------------------------------------------------------------------------

#ifndef DodajKorisnikaH
#define DodajKorisnikaH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Data.DB.hpp>
#include <Data.Win.ADODB.hpp>
#include "siComp.h"
#include "siLngLnk.h"
#include "uTPLb_BaseNonVisualComponent.hpp"
#include "uTPLb_CryptographicLibrary.hpp"
#include "uTPLb_Hash.hpp"
//---------------------------------------------------------------------------
class TFDodajKorisnika : public TForm
{
__published:	// IDE-managed Components
	TLabel *LUsername;
	TEdit *EUsername;
	TLabel *LPass;
	TEdit *EPass;
	TEdit *EPonoviPass;
	TLabel *LPodudaranje;
	TComboBox *CBRole;
	TLabel *LRole;
	TADOQuery *ADOQuery1;
	TButton *BDodajKorisnika;
	TButton *BOdustaniKorisnik;
	TsiLangLinked *siLangLinked_FDodajKorisnika;
	THash *Hash1;
	TCryptographicLibrary *CryptographicLibrary1;
	void __fastcall EPonoviPassChange(TObject *Sender);
	void __fastcall BOdustaniKorisnikClick(TObject *Sender);
	void __fastcall BDodajKorisnikaClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TFDodajKorisnika(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFDodajKorisnika *FDodajKorisnika;
//---------------------------------------------------------------------------
#endif
