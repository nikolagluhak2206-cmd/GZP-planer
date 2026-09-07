//---------------------------------------------------------------------------

#ifndef UrediKorisnikeH
#define UrediKorisnikeH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Data.DB.hpp>
#include <Data.Win.ADODB.hpp>
#include "Korisnik.h"
#include "siComp.h"
#include "siLngLnk.h"
#include "uTPLb_BaseNonVisualComponent.hpp"
#include "uTPLb_CryptographicLibrary.hpp"
#include "uTPLb_Hash.hpp"
//---------------------------------------------------------------------------
class TFUrediKorisnike : public TForm
{
__published:	// IDE-managed Components
	TLabel *LNaslov;
	TListView *LVKorisnici;
	TButton *BOdaberiKorisnika;
	TButton *BIzbrisiKorisnika;
	TButton *BOdustaniKorisnik;
	TADOQuery *ADOQuery1;
	TEdit *EKor_ime;
	TEdit *ENovaPass;
	TEdit *ENovaPassPonovno;
	TLabel *LNoviKorisnik;
	TLabel *LPass;
	TLabel *LPonoviPass;
	TLabel *LRole;
	TComboBox *CBRole;
	TButton *BSpremi;
	TLabel *LPodudaranje;
	TsiLangLinked *siLangLinked_FUrediKorisnike;
	THash *Hash1;
	TCryptographicLibrary *CryptographicLibrary1;
	void __fastcall BOdustaniKorisnikClick(TObject *Sender);
	void __fastcall BIzbrisiKorisnikaClick(TObject *Sender);
	void __fastcall BSpremiClick(TObject *Sender);
	void __fastcall ENovaPassPonovnoChange(TObject *Sender);
	void __fastcall BOdaberiKorisnikaClick(TObject *Sender);

private:    // User declarations
	Korisnik* trenutniKorisnik;
	void __fastcall UcitajKorisnikeUListView();
public:		// User declarations
	void SetTrenutniKorisnik(Korisnik* k);
	__fastcall TFUrediKorisnike(TComponent* Owner);

};
//---------------------------------------------------------------------------
extern PACKAGE TFUrediKorisnike *FUrediKorisnike;
//---------------------------------------------------------------------------
#endif
