//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Postavke_ini.h"

#include <IniFiles.hpp>
#include <Vcl.Styles.hpp>
#include <Vcl.Themes.hpp>
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------

Postavke_ini::Postavke_ini()
{
	darkMode = false;
	fullScreen = false;
}
//---------------------------------------------------------------------------

void Postavke_ini::UcitajIni(Korisnik *k)
{
	TIniFile *ini = new TIniFile(GetCurrentDir() + "\\postavke.ini");
	String korisnik = k->GetKor_ime();

	darkMode = ini->ReadBool(korisnik, "darkMode", false);
	fullScreen = ini->ReadBool(korisnik, "FullScreen", false);

	if (GetdarkMode())
		TStyleManager::TrySetStyle("Windows10 Dark");
	else
		TStyleManager::TrySetStyle("Windows");

	delete ini;
}
//---------------------------------------------------------------------------

void Postavke_ini::SpremiPostavke(Korisnik *k, bool dark, bool fs)
{
	TIniFile *ini = new TIniFile(GetCurrentDir() + "\\postavke.ini");

	String korisnik = k->GetKor_ime();

	ini->WriteBool(korisnik, "darkMode", dark);
	ini->WriteBool(korisnik, "FullScreen", fs);

	darkMode = dark;
	fullScreen = fs;

	delete ini;
}
//---------------------------------------------------------------------------

bool Postavke_ini::GetdarkMode()
{
	return darkMode;
}
//---------------------------------------------------------------------------

bool Postavke_ini::GetfullScreen()
{
	return fullScreen;
}
//---------------------------------------------------------------------------
