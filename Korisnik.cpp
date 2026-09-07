//---------------------------------------------------------------------------

#pragma hdrstop

#include "Korisnik.h"

//implementacija metoda klase Korisnik, seteri i geteri
String Korisnik::GetKor_ime()
{
	return kor_ime;
}

String Korisnik::GetLozinka()
{
	return lozinka;
}

int Korisnik::GetId()
{
    return id;
}

String Korisnik::GetRole()
{
	return role;
}

void Korisnik::SetKor_ime(String _kor)
{
	kor_ime = _kor;
}

void Korisnik::SetLozinka(String _loz)
{
    lozinka = _loz;
}


void Korisnik::SetId(int value)
{
    id = value;
}

void Korisnik::SetRole(String _role)
{
	role = _role;
}
//---------------------------------------------------------------------------
#pragma package(smart_init)
