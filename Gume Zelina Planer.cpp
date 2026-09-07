//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <tchar.h>
#include <memory>
#include "Login.h"
#include "Glavna.h"
#include "Korisnik.h"
#include "Postavke_ini.h"
//---------------------------------------------------------------------------
#include <Vcl.Styles.hpp>
#include <Vcl.Themes.hpp>
USEFORM("Glavna.cpp", FGlavna);

//---------------------------------------------------------------------------
int WINAPI _tWinMain(HINSTANCE, HINSTANCE, LPTSTR, int)
{
    try
    {
        Application->Initialize();

		std::unique_ptr<TFPrijava> FPrijava(new TFPrijava(NULL));

		if (FPrijava->ShowModal() == mrOk)
        {

		Application->CreateForm(__classid(TFGlavna), &FGlavna);

		Korisnik* k = new Korisnik();
			k->SetId(FPrijava->GetUserId());
			k->SetKor_ime(FPrijava->GetKorIme());
			k->SetLozinka(FPrijava->GetLozinka());
			k->SetRole(FPrijava->GetRole());
			FGlavna->SetKorisnik(k);


		Postavke_ini ini;
        ini.UcitajIni(k);
		if (ini.GetfullScreen() == true)
			FGlavna->WindowState = wsMaximized;
		else
			FGlavna->WindowState = wsNormal;

			Application->Run();
		}
    }
    catch (Exception &exception)
    {
        Application->ShowException(&exception);
    }
    return 0;
}
//---------------------------------------------------------------------------
