//---------------------------------------------------------------------------

#ifndef KorisnikH
#define KorisnikH

class Korisnik
{
	private:
	//atributi klase Korisnik
	String kor_ime;
	String lozinka;
	int id;
	String role;

	public:
	//deklaracije metoda klase Korisnik
	void SetKor_ime (String _kor_ime);
	void SetLozinka (String _lozinka);
	void SetId (int value);
	void SetRole (String _role);

	String GetKor_ime();
	String GetLozinka();
	int GetId();
    String GetRole();


};
//---------------------------------------------------------------------------
#endif
