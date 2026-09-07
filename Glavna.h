//---------------------------------------------------------------------------
#ifndef GlavnaH
#define GlavnaH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include "Korisnik.h"
#include <Vcl.ComCtrls.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Grids.hpp>
#include <Data.DB.hpp>
#include <Data.Win.ADODB.hpp>
#include <Vcl.Menus.hpp>
#include "siComp.h"
#include "siLngLnk.h"
#include "siLangCombo.h"
#include <functional>
#include <set>
//---------------------------------------------------------------------------
class TFGlavna : public TForm
{
__published:
	TMonthCalendar *MCkalendar;
	TStringGrid *StringGridTermini;
	TADOQuery *ADOQuery1;
	TPopupMenu *PopUpCrnaLista;
    TMenuItem *Dodajnacrnulistu1;
	TMainMenu *Meni;
	TMenuItem *Sustav1;
	TMenuItem *PromjenaKorisnika;
	TMenuItem *DodajKorisnika;
	TMenuItem *UrediKorisnika;
	TMenuItem *Urediprofil1;
	TMenuItem *Promjena1;
	TMenuItem *Postavkeaplikacije1;
	TMenuItem *Upravljanjecrnomlistom1;
	TsiLangLinked *siLangLinked_FGlavna;
	TsiLangCombo *siLangCombo1;
	TImage *Slika;
	TMenuItem *GZPadmin1;
	TMenuItem *Cjenik1;
	TMenuItem *HotelGume;
	TMenuItem *Pretragaguma1;
    void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall MCkalendarChange(TObject *Sender);
	void __fastcall StringGridTerminiKeyPress(TObject *Sender, char &Key);
    void __fastcall StringGridTerminiMouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
	void __fastcall DodajnacrnulistuClick(TObject *Sender);
	void __fastcall StringGridTerminiDrawCell(TObject *Sender, System::LongInt ACol,
		  System::LongInt ARow, TRect &Rect, TGridDrawState State);
	void __fastcall PromjenaKorisnikaClick(TObject *Sender);
	void __fastcall DodajKorisnikaClick(TObject *Sender);
	void __fastcall UrediKorisnikaClick(TObject *Sender);
	void __fastcall Upravljanjecrnomlistom1Click(TObject *Sender);
	void __fastcall Postavkeaplikacije1Click(TObject *Sender);
	void __fastcall siLangCombo1Change(TObject *Sender);
	void __fastcall Promjena1Click(TObject *Sender);
	void __fastcall HotelGumeClick(TObject *Sender);
	void __fastcall Cjenik1Click(TObject *Sender);
	void __fastcall Pretragaguma1Click(TObject *Sender);
private:
	Korisnik* trenutniKorisnik;
	std::set<String> crnaListaCache;
    void __fastcall UcitajTermine();
    void __fastcall UcitajCrnuListu();
    void __fastcall IzvrsiQuery(const String& sql,
        std::function<void()> postaviParametre, bool execSQL = false);
    bool __fastcall JeNaCrnojListi(const String& registracija);
public:
	__fastcall TFGlavna(TComponent* Owner);
	void __fastcall SetKorisnik(Korisnik* k);
    void ucitajSliku();
};
//---------------------------------------------------------------------------
extern PACKAGE TFGlavna *FGlavna;
//---------------------------------------------------------------------------
#endif
