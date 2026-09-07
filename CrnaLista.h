//---------------------------------------------------------------------------
#ifndef CrnaListaH
#define CrnaListaH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Data.DB.hpp>
#include <Data.Win.ADODB.hpp>
#include "siComp.h"
#include "siLngLnk.h"
//---------------------------------------------------------------------------
class TFCrnaListaDialog : public TForm
{
__published:
    TLabel *LOpis;
    TButton *BDodaj;
    TEdit *ERazlog;
    TButton *BOdustani;
    TADOQuery *ADOQuery1;
	TsiLangLinked *siLangLinked_FCrnaListaDialog;
    void __fastcall BDodajClick(TObject *Sender);
    void __fastcall BOdustaniClick(TObject *Sender);
private:
    int     FTerminId;
	String  FRegistracija;
public:
    __fastcall TFCrnaListaDialog(TComponent* Owner);
	void SetPodaci(int terminId, const String& registracija);
};
//---------------------------------------------------------------------------
extern PACKAGE TFCrnaListaDialog *FCrnaListaDialog;
//---------------------------------------------------------------------------
#endif
