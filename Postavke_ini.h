#ifndef Postavke_iniH
#define Postavke_iniH

#include "Korisnik.h"

class Postavke_ini
{
private:

    bool darkMode;
    bool fullScreen;

public:

    Postavke_ini();

    void UcitajIni(Korisnik *k);
    void SpremiPostavke(Korisnik *k, bool dark, bool fullscreen);

	bool GetdarkMode();
    bool GetfullScreen();
};

#endif
