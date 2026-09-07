//---------------------------------------------------------------------------

#ifndef PodaciPrijavaH
#define PodaciPrijavaH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Dialogs.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.ExtDlgs.hpp>
#include <Data.DB.hpp>
#include <Data.Win.ADODB.hpp>
#include <Vcl.DBGrids.hpp>
#include <Vcl.Grids.hpp>
#include "Korisnik.h"
#include "siComp.h"
#include "siLngLnk.h"
#include "uTPLb_BaseNonVisualComponent.hpp"
#include "uTPLb_CryptographicLibrary.hpp"
#include "uTPLb_Hash.hpp"
//---------------------------------------------------------------------------
class TFPodaciPrijava : public TForm
{
__published:	// IDE-managed Components
	TImage *Slika;
	TADOQuery *ADOQuery1;
	TsiLangLinked *siLangLinked_FPodaciPrijava;
	TButton *BOdaberiSliku;
	TOpenPictureDialog *OtvoriSlikuDialog;
	TButton *BSpremiPostavke;
	TEdit *EKor_ime;
	TEdit *EPonoviPass;
	TLabel *LKor_ime;
	TLabel *LPass;
	TLabel *LPonoviPass;
	TEdit *EPass;
	TButton *BObrisiSliku;
	THash *Hash1;
	TCryptographicLibrary *CryptographicLibrary1;
	void __fastcall BOdaberiSlikuClick(TObject *Sender);
	void __fastcall BSpremiPostavkeClick(TObject *Sender);
	void __fastcall BObrisiSlikuClick(TObject *Sender);
private:	// User declarations
	Korisnik* trenutniKorisnik;
public:		// User declarations
	__fastcall TFPodaciPrijava(TComponent* Owner);
	void setKorisnik(Korisnik* k);
	void ucitajSliku();
	void spremiSliku();
    void spremiPodatke();
};
//---------------------------------------------------------------------------
extern PACKAGE TFPodaciPrijava *FPodaciPrijava;
//---------------------------------------------------------------------------
#endif
