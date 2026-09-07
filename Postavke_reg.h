#ifndef Postavke_regH
#define Postavke_regH

#include <Registry.hpp>
#include "Korisnik.h"

class Postavke_reg
{
private:

    int fontSize;
    bool zapamtiDatum;
	TDateTime zadnjiDatum;
	UnicodeString kljuc = "Software\\GZP\\";
    void puniKljuc(Korisnik *k);

public:

	Postavke_reg();
	void UcitajReg(Korisnik *k);
	void SpremiPostavke(Korisnik *k, int font, bool zapamti, TDateTime datum);
	int GetFontSize();
	bool GetZapamtiDatum();
	TDateTime GetZadnjiDatum();
    UnicodeString getKljuc();
};

#endif
