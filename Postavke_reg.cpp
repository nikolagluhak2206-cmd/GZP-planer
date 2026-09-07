#pragma hdrstop

#include "Postavke_reg.h"

#pragma package(smart_init)


static const UnicodeString VRIJEDNOST_FONT = "FontSize";
static const UnicodeString VRIJEDNOST_ZAPAMTI_DATUM = "ZapamtiDatum";
static const UnicodeString VRIJEDNOST_ZADNJI_DATUM = "ZadnjiDatum";


static const int DEFAULT_FONT_SIZE = 10;


//---------------------------------------------------------------------------

Postavke_reg::Postavke_reg()
{
    fontSize = DEFAULT_FONT_SIZE;
    zapamtiDatum = false;
    zadnjiDatum = Date();
}


//---------------------------------------------------------------------------

void Postavke_reg::puniKljuc(Korisnik *k)
{
    kljuc = "Software\\GZP\\" + k->GetKor_ime();
}


//---------------------------------------------------------------------------

UnicodeString Postavke_reg::getKljuc()
{
    return kljuc;
}


//---------------------------------------------------------------------------

void Postavke_reg::UcitajReg(Korisnik *k)
{
	puniKljuc(k);


	TRegistry *reg = new TRegistry();
	reg->RootKey = HKEY_CURRENT_USER;


	if(reg->OpenKey(kljuc, true))
	{

		if(reg->ValueExists(VRIJEDNOST_FONT))
			fontSize = reg->ReadInteger(VRIJEDNOST_FONT);
		else
			fontSize = DEFAULT_FONT_SIZE;



		if(reg->ValueExists(VRIJEDNOST_ZAPAMTI_DATUM))
			zapamtiDatum = reg->ReadBool(VRIJEDNOST_ZAPAMTI_DATUM);
		else
            zapamtiDatum = false;



        if(reg->ValueExists(VRIJEDNOST_ZADNJI_DATUM))
            zadnjiDatum = reg->ReadDateTime(VRIJEDNOST_ZADNJI_DATUM);
		else
            zadnjiDatum = Date();


        reg->CloseKey();
	}


	delete reg;
}


//---------------------------------------------------------------------------

void Postavke_reg::SpremiPostavke(Korisnik *k, int font, bool zapamti, TDateTime datum)
{
	puniKljuc(k);


	TRegistry *reg = new TRegistry();
	reg->RootKey = HKEY_CURRENT_USER;


	if(reg->OpenKey(kljuc, true))
	{

		reg->WriteInteger(VRIJEDNOST_FONT, font);
		reg->WriteBool(VRIJEDNOST_ZAPAMTI_DATUM, zapamti);

		if(zapamti)
		{
			reg->WriteDateTime(VRIJEDNOST_ZADNJI_DATUM, datum);
        }


		reg->CloseKey();
    }


	fontSize = font;
	zapamtiDatum = zapamti;
	zadnjiDatum = datum;


	delete reg;
}


//---------------------------------------------------------------------------

int Postavke_reg::GetFontSize()
{
    return fontSize;
}


//---------------------------------------------------------------------------

bool Postavke_reg::GetZapamtiDatum()
{
    return zapamtiDatum;
}


//---------------------------------------------------------------------------

TDateTime Postavke_reg::GetZadnjiDatum()
{
    return zadnjiDatum;
}
