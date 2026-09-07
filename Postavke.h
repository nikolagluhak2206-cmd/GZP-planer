//---------------------------------------------------------------------------

#ifndef PostavkeH
#define PostavkeH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include "Korisnik.h"
#include "siComp.h"
#include "siLngLnk.h"

//---------------------------------------------------------------------------
class TFPostavke : public TForm
{
__published:	// IDE-managed Components
	TCheckBox *CBDark;
	TButton *BSpremiPostavke;
	TCheckBox *CBFullScreen;
	TComboBox *ComboFont;
	TLabel *LPromjenaFonta;
	TCheckBox *CBZapamtiDatum;
	TsiLangLinked *siLangLinked_FPostavke;
	void __fastcall BSpremiPostavkeClick(TObject *Sender);
private:	// User declarations
	Korisnik *trenutniKorisnik;
public:		// User declarations
	__fastcall TFPostavke(TComponent* Owner);
	void __fastcall SetKorisnik(Korisnik *k);

};
//---------------------------------------------------------------------------
extern PACKAGE TFPostavke *FPostavke;
//---------------------------------------------------------------------------
#endif
