//---------------------------------------------------------------------------

#ifndef HotelGumeH
#define HotelGumeH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ComCtrls.hpp>
#include "siComp.h"
#include "siLngLnk.h"
#include "frCoreClasses.hpp"
#include "frxClass.hpp"
#include "uTPLb_BaseNonVisualComponent.hpp"
#include "uTPLb_Codec.hpp"
#include "uTPLb_CryptographicLibrary.hpp"
#include <System.SysUtils.hpp>
//---------------------------------------------------------------------------
class TFHotelGume : public TForm
{
__published:	// IDE-managed Components
	TListView *Lista;
	TEdit *EVlasnik;
	TEdit *EBrojMobitela;
	TEdit *EMarkaDimenzija;
	TEdit *ELokacija;
	TEdit *ENapomena;
	TDateTimePicker *DatumZaprimanja;
	TLabel *LVlasnik;
	TLabel *LBrojMobitela;
	TLabel *LMarkaDimenzija;
	TLabel *LLokacija;
	TLabel *LNapomena;
	TLabel *LDatumZaprimanja;
	TButton *BReset;
	TButton *BDodaj;
	TButton *BUpdate;
	TEdit *EPretraga;
	TButton *BObrisi;
	TsiLangLinked *siLangLinked_FHotelGume;
	TButton *BPotvrda;
	TfrxReport *frxReport1;
	TfrxUserDataSet *frxUserDataSet1;
	TCodec *SimetricniCodec;
	TCryptographicLibrary *CryptographicLibrary1;
	void __fastcall ListaChange(TObject *Sender, TListItem *Item, TItemChange Change);
	void __fastcall BResetClick(TObject *Sender);
	void __fastcall BDodajClick(TObject *Sender);
	void __fastcall BUpdateClick(TObject *Sender);
	void __fastcall BObrisiClick(TObject *Sender);
	void __fastcall EPretragaChange(TObject *Sender);
	void __fastcall BPotvrdaClick(TObject *Sender);
	void __fastcall frxUserDataSet1First(TObject *Sender);
	void __fastcall frxUserDataSet1CheckEOF(TObject *Sender, bool &Eof);
	void __fastcall frxUserDataSet1GetValue(const UnicodeString VarName, Variant &Value);
	void __fastcall frxUserDataSet1Next(TObject *Sender);

private:	// User declarations
public:		// User declarations
	__fastcall TFHotelGume(TComponent* Owner);
	void ucitajJSON();
    void spremiJSON();
	void odaberiRed();
	void updateJSON();
	void obrisiJSON();
    void pretraga(String tekst);
};
//---------------------------------------------------------------------------
extern PACKAGE TFHotelGume *FHotelGume;
//---------------------------------------------------------------------------
#endif
