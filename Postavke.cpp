//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Postavke.h"
#include "Postavke_ini.h"
#include "Postavke_reg.h"
#include "Glavna.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "siComp"
#pragma link "siLngLnk"
#pragma resource "*.dfm"
TFPostavke *FPostavke;
//---------------------------------------------------------------------------
__fastcall TFPostavke::TFPostavke(TComponent* Owner)
	: TForm(Owner)
{

}
//---------------------------------------------------------------------------
void __fastcall TFPostavke::SetKorisnik(Korisnik *k)
{

	trenutniKorisnik = k;

	Postavke_ini ini;
	Postavke_reg reg;

	ini.UcitajIni(trenutniKorisnik);
	reg.UcitajReg(trenutniKorisnik);

	CBDark->Checked = ini.GetdarkMode();
	CBFullScreen->Checked = ini.GetfullScreen();

		switch (reg.GetFontSize())
	{
		case 8:
			ComboFont->ItemIndex = 0;
			Font->Size = 8;
			break;

		case 10:
			ComboFont->ItemIndex = 1;
			Font->Size = 10;
			break;

		case 12:
			ComboFont->ItemIndex = 2;
			Font->Size = 12;
			break;

		default:
			ComboFont->ItemIndex = -1;
			break;
	}
	CBZapamtiDatum->Checked = reg.GetZapamtiDatum();
}
//---------------------------------------------------------------------------
void __fastcall TFPostavke::BSpremiPostavkeClick(TObject *Sender)
{
	Postavke_ini ini;
	ini.SpremiPostavke(trenutniKorisnik, CBDark->Checked, CBFullScreen->Checked);

	if (CBFullScreen->Checked)
	{
		FGlavna->WindowState = wsMaximized;
		FGlavna->Position = poScreenCenter;
	}

	else
	{
		FGlavna->WindowState = wsNormal;
		FGlavna->Position = poScreenCenter;
	}


	ini.UcitajIni(trenutniKorisnik);


	Postavke_reg reg;
	int velicina;
	if (ComboFont->ItemIndex == 0)
	{
		velicina = 8;
	}
	else if (ComboFont->ItemIndex == 1)
		{
			velicina = 10;
		 }
	else if (ComboFont->ItemIndex == 2)
		{
			velicina = 12;
		 }

	reg.SpremiPostavke(trenutniKorisnik, velicina, CBZapamtiDatum->Checked, FGlavna->MCkalendar->Date);
	FGlavna->Font->Size = velicina;
	BringToFront();
}
//---------------------------------------------------------------------------




