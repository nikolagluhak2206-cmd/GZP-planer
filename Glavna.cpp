//---------------------------------------------------------------------------
#include <vcl.h>
#include <memory>
#include <functional>
#include <Vcl.Themes.hpp>
#include <Vcl.Styles.hpp>
#pragma hdrstop

#include "Glavna.h"
#include "Korisnik.h"
#include "Login.h"
#include "CrnaLista.h"
#include "DodajKorisnika.h"
#include "UrediKorisnike.h"
#include "UpravljanjeCrnomListom.h"
#include "Postavke.h"
#include "Postavke_ini.h"
#include "Postavke_reg.h"
#include "PodaciPrijava.h"
#include "HotelGume.h"
#include "IzradaCjenika.h"
#include "PretragaGuma.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "siComp"
#pragma link "siLngLnk"
#pragma link "siLangCombo"
#pragma resource "*.dfm"

TFGlavna *FGlavna;

//---------------------------------------------------------------------------
//kosntruktor forme, postalvjanje vremena u celije "Vrijeme"
__fastcall TFGlavna::TFGlavna(TComponent* Owner)
	: TForm(Owner)
{
	trenutniKorisnik = nullptr;

	StringGridTermini->Cells[0][0] = siLangLinked_FGlavna->GetText("IDS_0");
	StringGridTermini->Cells[1][0] = siLangLinked_FGlavna->GetText("IDS_1");
	StringGridTermini->Cells[2][0] = siLangLinked_FGlavna->GetText("IDS_2");
	StringGridTermini->Cells[3][0] = siLangLinked_FGlavna->GetText("IDS_3");

	const wchar_t* termini[] = {
		L"07:00 - 07:30", L"07:30 - 08:00", L"08:00 - 08:30", L"08:30 - 09:00",
		L"09:00 - 09:30", L"09:30 - 10:00", L"10:00 - 10:30", L"10:30 - 11:00",
		L"11:00 - 11:30", L"11:30 - 12:00", L"12:00 - 12:30", L"12:30 - 13:00",
		L"13:00 - 13:30", L"13:30 - 14:00", L"14:00 - 14:30", L"14:30 - 15:00",
		L"15:00 - 15:30", L"15:30 - 16:00", L"16:00 - 16:30", L"16:30 - 17:00",
		L"17:00 - 17:30"
	};
	for(int i = 0; i < 21; i++)
		StringGridTermini->Cells[0][i + 1] = termini[i];

}

//---------------------------------------------------------------------------
//pomocna metoda za izvrsavanje upita
void __fastcall TFGlavna::IzvrsiQuery(const String& sql,
	std::function<void()> postaviParametre, bool execSQL)
{
	ADOQuery1->Close();
	ADOQuery1->SQL->Text = sql;
	postaviParametre();
	if(execSQL)
		ADOQuery1->ExecSQL();
	else
		ADOQuery1->Open();
}

//---------------------------------------------------------------------------
void __fastcall TFGlavna::UcitajCrnuListu()
{
	crnaListaCache.clear();

	ADOQuery1->Close();
	ADOQuery1->SQL->Text =
		"SELECT DISTINCT t.registracija "
		"FROM crna_lista cl "
		"INNER JOIN termini t ON cl.termin_id = t.id";
	ADOQuery1->Open();

	while(!ADOQuery1->Eof)
	{
		crnaListaCache.insert(ADOQuery1->FieldByName("registracija")->AsString);
		ADOQuery1->Next();
	}
	ADOQuery1->Close();
}

//---------------------------------------------------------------------------
bool __fastcall TFGlavna::JeNaCrnojListi(const String& registracija)
{
	return crnaListaCache.count(registracija) > 0;
}

//---------------------------------------------------------------------------
//SELECT za tablicu termini
void __fastcall TFGlavna::UcitajTermine()
{
	UcitajCrnuListu();

	for(int i = 1; i <= 21; i++)
	{
		String vrijeme = StringGridTermini->Cells[0][i];

		IzvrsiQuery(
			"SELECT t.registracija, t.opis, k.kor_ime "
			"FROM (termini t INNER JOIN korisnici k ON t.korisnik_id = k.id) "
			"WHERE t.[datum] = :d AND t.vrijeme = :v",
			[&]() {
				ADOQuery1->Parameters->ParamByName("d")->DataType = ftDate;
				ADOQuery1->Parameters->ParamByName("d")->Value = MCkalendar->Date;
				ADOQuery1->Parameters->ParamByName("v")->Value = vrijeme;
			}
		);

		if(!ADOQuery1->Eof)
		{
			StringGridTermini->Cells[1][i] = ADOQuery1->FieldByName("kor_ime")->AsString;
			StringGridTermini->Cells[2][i] = ADOQuery1->FieldByName("registracija")->AsString;
			StringGridTermini->Cells[3][i] = ADOQuery1->FieldByName("opis")->AsString;
		}
		else
		{
			StringGridTermini->Cells[1][i] = "";
			StringGridTermini->Cells[2][i] = "";
			StringGridTermini->Cells[3][i] = "";
		}
	}
	ADOQuery1->Close();
	StringGridTermini->Invalidate();
}

//---------------------------------------------------------------------------
void __fastcall TFGlavna::FormClose(TObject *Sender, TCloseAction &Action)
{
	delete trenutniKorisnik;
	trenutniKorisnik = nullptr;
	Action = caFree;
	Application->Terminate();
}

//---------------------------------------------------------------------------
void __fastcall TFGlavna::SetKorisnik(Korisnik* k)
{
	trenutniKorisnik = k;
	Postavke_reg reg;

	reg.UcitajReg(trenutniKorisnik);
    Font->Size = reg.GetFontSize();
	if(reg.GetZapamtiDatum())
	{
		MCkalendar->Date = reg.GetZadnjiDatum();
    }
    else
	{
		MCkalendar->Date = Date();
	}
	Caption = siLangLinked_FGlavna->GetText("GZP@") + trenutniKorisnik->GetKor_ime();

	if (trenutniKorisnik->GetRole() != "admin")
	{
		GZPadmin1->Visible = false;
	}
	else
	{
		GZPadmin1->Visible = true;
	}

	UcitajTermine();
	ucitajSliku();
}

//---------------------------------------------------------------------------
void __fastcall TFGlavna::MCkalendarChange(TObject *Sender)
{
	Postavke_reg reg;
	reg.UcitajReg(trenutniKorisnik);
		if(reg.GetZapamtiDatum())
	{
		reg.SpremiPostavke(trenutniKorisnik, reg.GetFontSize(), true, MCkalendar->Date );
	}
	UcitajTermine();
}

//---------------------------------------------------------------------------
void __fastcall TFGlavna::StringGridTerminiKeyPress(TObject *Sender, char &Key)
{
	if(Key != 13) return;
	Key = 0;

	int red = StringGridTermini->Row;
	if(red < 1) return;

	StringGridTermini->EditorMode = false;

	String vrijeme = StringGridTermini->Cells[0][red];
	String registracija = StringGridTermini->Cells[2][red].Trim();
	String opis = StringGridTermini->Cells[3][red].Trim();
	int korisnik_id = trenutniKorisnik->GetId();
	TDate datum = MCkalendar->Date;

	StringGridTermini->Cells[1][red] = trenutniKorisnik->GetKor_ime();
	//DELETE za tablicu termini
	if(registracija.IsEmpty())
	{
        IzvrsiQuery(
			"DELETE FROM termini WHERE [datum] = :d AND vrijeme = :v",
			[&]() {
                ADOQuery1->Parameters->ParamByName("d")->DataType = ftDate;
				ADOQuery1->Parameters->ParamByName("d")->Value = datum;
				ADOQuery1->Parameters->ParamByName("v")->Value = vrijeme;
			}, true
        );

        StringGridTermini->Cells[1][red] = "";
        StringGridTermini->Cells[2][red] = "";
        StringGridTermini->Cells[3][red] = "";
        UcitajTermine();
        return;
    }

	//provjera jel rega na crnoj listi
    IzvrsiQuery(
        "SELECT cl.id, cl.razlog FROM crna_lista cl "
        "INNER JOIN termini t ON cl.termin_id = t.id "
        "WHERE t.registracija = :r",
        [&]() {
            ADOQuery1->Parameters->ParamByName("r")->Value = registracija;
        }
	);

    if(!ADOQuery1->Eof)
    {
        String razlog = ADOQuery1->FieldByName("razlog")->AsString;
        ADOQuery1->Close();

		int odgovor = MessageDlg(
			siLangLinked_FGlavna->GetText("IDS_42") +
			registracija +
			siLangLinked_FGlavna->GetText("IDS_43") +
			siLangLinked_FGlavna->GetText("IDS_44") +
			razlog +
			"\n\n" +
			siLangLinked_FGlavna->GetText("IDS_46"),
			mtWarning,
			TMsgDlgButtons() << mbYes << mbNo,
			0
		);

        if(odgovor != mrYes)
        {
            StringGridTermini->Cells[1][red] = "";
            StringGridTermini->Cells[2][red] = "";
			StringGridTermini->Cells[3][red] = "";
            StringGridTermini->EditorMode = true;
            return;
        }
    }
    else
        ADOQuery1->Close();

	// Provjeri postoji li zapis
    IzvrsiQuery(
        "SELECT id FROM termini WHERE [datum] = :d AND vrijeme = :v",
        [&]() {
            ADOQuery1->Parameters->ParamByName("d")->DataType = ftDate;
			ADOQuery1->Parameters->ParamByName("d")->Value = datum;
			ADOQuery1->Parameters->ParamByName("v")->Value = vrijeme;
		}
	);

	if(!ADOQuery1->Eof)
	{   //UPDATE za tablicu termini
		int id = ADOQuery1->FieldByName("id")->AsInteger;
		IzvrsiQuery(
            "UPDATE termini SET registracija = :r, korisnik_id = :kid, opis = :o WHERE id = :id",
			[&]() {
				ADOQuery1->Parameters->ParamByName("r")->Value = registracija;
				ADOQuery1->Parameters->ParamByName("kid")->DataType = ftInteger;
				ADOQuery1->Parameters->ParamByName("kid")->Value = korisnik_id;
				ADOQuery1->Parameters->ParamByName("o")->Value = opis;
				ADOQuery1->Parameters->ParamByName("id")->DataType = ftInteger;
				ADOQuery1->Parameters->ParamByName("id")->Value = id;
			}, true
		);
	}
	else
	{   //INSERT za tablicu termini
		IzvrsiQuery(
			"INSERT INTO termini (datum, vrijeme, registracija, opis, korisnik_id) "
			"VALUES (:d, :v, :r, :o, :kid)",
			[&]() {
                ADOQuery1->Parameters->ParamByName("d")->DataType   = ftDate;
                ADOQuery1->Parameters->ParamByName("d")->Value      = datum;
				ADOQuery1->Parameters->ParamByName("v")->Value      = vrijeme;
                ADOQuery1->Parameters->ParamByName("r")->Value      = registracija;
				ADOQuery1->Parameters->ParamByName("o")->Value      = opis;
				ADOQuery1->Parameters->ParamByName("kid")->DataType = ftInteger;
				ADOQuery1->Parameters->ParamByName("kid")->Value    = korisnik_id;
			}, true
		);
	}

	UcitajTermine();
	StringGridTermini->EditorMode = true;
}

//---------------------------------------------------------------------------
void __fastcall TFGlavna::StringGridTerminiMouseDown(TObject *Sender, TMouseButton Button,
	  TShiftState Shift, int X, int Y)
{
	if(Button != mbRight) return;

	//pretvaranje koordinata miša x,y u kolonu i red koji sam kliknuo, odnosno u odredenu celiju
	int col, row;
	StringGridTermini->MouseToCell(X, Y, col, row);

	//ako je kolona na fiksirane stupce(vrijeme, korisnik) i header prekid funkcije
	//ako je selektirana celije prazna prekid
	if(row < StringGridTermini->FixedRows || col < StringGridTermini->FixedCols) return;
	if(StringGridTermini->Cells[1][row].Trim().IsEmpty()) return;

	//grid vizualno označi gdje je kliknuto
	//otvara se crna lista popup na poziciji miša
	StringGridTermini->Row = row;
	StringGridTermini->Col = col;
	PopUpCrnaLista->Popup(Mouse->CursorPos.x, Mouse->CursorPos.y);
}

//---------------------------------------------------------------------------
void __fastcall TFGlavna::DodajnacrnulistuClick(TObject *Sender)
{
	int red = StringGridTermini->Row;
	String vrijeme = StringGridTermini->Cells[0][red];
    String registracija = StringGridTermini->Cells[2][red];

	//provjerava jel id temrina s tim datumom i vremenom postoji u bazi, ak ne zatvara query
    IzvrsiQuery(
        "SELECT id FROM termini WHERE [datum] = :d AND vrijeme = :v",
        [&]() {
            ADOQuery1->Parameters->ParamByName("d")->DataType = ftDate;
			ADOQuery1->Parameters->ParamByName("d")->Value = MCkalendar->Date;
            ADOQuery1->Parameters->ParamByName("v")->Value = vrijeme;
        }
    );

    if(ADOQuery1->Eof)
    {
		siLangLinked_FGlavna->GetText("IDS_59");
		ADOQuery1->Close();
        return;
    }

    int terminId = ADOQuery1->FieldByName("id")->AsInteger;
    ADOQuery1->Close();

    //kreira formu za unos u crnu listu i proslijeduje podatke
	FCrnaListaDialog = new TFCrnaListaDialog(this);
	FCrnaListaDialog->SetPodaci(terminId, registracija);

	//korisnik potvrdio unos u crnu listu, osvjezava cache i ponovno iscrtava termine
    if(FCrnaListaDialog->ShowModal() == mrOk)
	{
		UcitajCrnuListu();
		StringGridTermini->Invalidate();
	}

	delete FCrnaListaDialog;
	FCrnaListaDialog = nullptr;
}

//ux bojanje redova
void __fastcall TFGlavna::StringGridTerminiDrawCell(TObject *Sender, System::LongInt ACol,
		  System::LongInt ARow, TRect &Rect, TGridDrawState State)
{
	TStringGrid *Grid = dynamic_cast<TStringGrid*>(Sender);

	// osnovne boje
	Grid->Canvas->Brush->Color = clWindow;
	Grid->Canvas->Font->Color = clWindowText;

	// selektirani red
	if (State.Contains(gdSelected))
	{
		Grid->Canvas->Brush->Color = clHighlight;
		Grid->Canvas->Font->Color = clHighlightText;
	}

	String registracija = Grid->Cells[2][ARow].Trim();

	// crna lista
	if (!registracija.IsEmpty() && JeNaCrnojListi(registracija) && (ACol == 2 || ACol == 3))
	{
		Grid->Canvas->Brush->Color = clRed;
		Grid->Canvas->Font->Color = clWhite;
	}

	// nacrtaj pozadinu
	Grid->Canvas->FillRect(Rect);

	// tekst ćelije
	String tekst = Grid->Cells[ACol][ARow];

	Grid->Canvas->TextRect(
		Rect,
		Rect.Left + 4,
		Rect.Top + 2,
		tekst
	);
}
//---------------------------------------------------------------------------

void __fastcall TFGlavna::PromjenaKorisnikaClick(TObject *Sender)
{
	std::unique_ptr<TFPrijava> loginForma(new TFPrijava(NULL));

	// postavi isti jezik kao glavna forma
	loginForma->siLang_FPrijava->ActiveLanguage = siLangLinked_FGlavna->ActiveLanguage;
	loginForma->siLangCombo1->Visible = false;

	if (loginForma->ShowModal() == mrOk)
	{
		if (trenutniKorisnik != nullptr)
		{
			delete trenutniKorisnik;
			trenutniKorisnik = nullptr;
		}

		Korisnik* k = new Korisnik();

		k->SetId(loginForma->GetUserId());
		k->SetKor_ime(loginForma->GetKorIme());
		k->SetLozinka(loginForma->GetLozinka());
		k->SetRole(loginForma->GetRole());

		SetKorisnik(k);

		Postavke_ini postavke;
		postavke.UcitajIni(k);

		if (postavke.GetfullScreen())
			WindowState = wsMaximized;
		else
		{
			WindowState = wsNormal;
			Position = poDesktopCenter;
		}

		UcitajTermine();
		ucitajSliku();
	}
}
//---------------------------------------------------------------------------

void __fastcall TFGlavna::DodajKorisnikaClick(TObject *Sender)
{
	  FDodajKorisnika = new TFDodajKorisnika(this);
	  FDodajKorisnika->ShowModal();
	  delete FDodajKorisnika;
	  FDodajKorisnika = nullptr;
}
//---------------------------------------------------------------------------

void __fastcall TFGlavna::UrediKorisnikaClick(TObject *Sender)
{
	  FUrediKorisnike = new TFUrediKorisnike(this);
      FUrediKorisnike->SetTrenutniKorisnik(trenutniKorisnik);
	  FUrediKorisnike->ShowModal();
	  delete FUrediKorisnike;
	  FUrediKorisnike = nullptr;
}
//---------------------------------------------------------------------------

void __fastcall TFGlavna::Upravljanjecrnomlistom1Click(TObject *Sender)
{
	  FUpravljanjeCrnomListom = new TFUpravljanjeCrnomListom(this);
	  FUpravljanjeCrnomListom->ShowModal();
	  delete FUpravljanjeCrnomListom;
	  FUpravljanjeCrnomListom = nullptr;
}
//---------------------------------------------------------------------------

void __fastcall TFGlavna::Postavkeaplikacije1Click(TObject *Sender)
{
	FPostavke = new TFPostavke(this);
    FPostavke->SetKorisnik(trenutniKorisnik);
    FPostavke->Caption = siLangLinked_FGlavna->GetText("IDS_61") + trenutniKorisnik->GetKor_ime();

    if (FPostavke->ShowModal() == mrOk)
	{
		Postavke_ini ini;
		ini.UcitajIni(trenutniKorisnik); // TrySetStyle se sad zove kad NEMA modala na ekranu
	}

    delete FPostavke;
	FPostavke = nullptr;
}
//---------------------------------------------------------------------------

//morao dodati jer nije htjelo mijenjati jezik na string grid caption cellovima
void __fastcall TFGlavna::siLangCombo1Change(TObject *Sender)
{
	siLangLinked_FGlavna->ActiveLanguage = siLangCombo1->ItemIndex + 1;

	StringGridTermini->Cells[0][0] = siLangLinked_FGlavna->GetText("IDS_0");
	StringGridTermini->Cells[1][0] = siLangLinked_FGlavna->GetText("IDS_1");
	StringGridTermini->Cells[2][0] = siLangLinked_FGlavna->GetText("IDS_2");
	StringGridTermini->Cells[3][0] = siLangLinked_FGlavna->GetText("IDS_3");

	Caption = siLangLinked_FGlavna->GetText("GZP@") + trenutniKorisnik->GetKor_ime();
}
//---------------------------------------------------------------------------

void __fastcall TFGlavna::Promjena1Click(TObject *Sender)
{
	  TFPodaciPrijava* podaciPrijava = new TFPodaciPrijava(this);
	  podaciPrijava->setKorisnik(trenutniKorisnik);
      podaciPrijava->ShowModal();
	  delete FPodaciPrijava;
	  FPodaciPrijava = nullptr;
}
//---------------------------------------------------------------------------
void TFGlavna::ucitajSliku()
{
	ADOQuery1->Close();
	ADOQuery1->SQL->Text = "SELECT slika_profila FROM korisnici WHERE id=:id";
	ADOQuery1->Parameters->ParamByName("id")->Value = trenutniKorisnik->GetId();
	ADOQuery1->Open();

	if (!ADOQuery1->FieldByName("slika_profila")->IsNull)
	{
		TBlobField *blob = static_cast<TBlobField*>(ADOQuery1->FieldByName("slika_profila"));
		TMemoryStream* stream = new TMemoryStream();

		blob->SaveToStream(stream);
		stream->Position = 0;

		Slika->Picture->LoadFromStream(stream);
		delete stream;
	}
}

//---------------------------------------------------------------------------

void __fastcall TFGlavna::HotelGumeClick(TObject *Sender)
{
	  FHotelGume = new TFHotelGume(this);
	  FHotelGume->ShowModal();
	  delete FHotelGume;
	  FHotelGume = nullptr;
}
//---------------------------------------------------------------------------

void __fastcall TFGlavna::Cjenik1Click(TObject *Sender)
{
	FIzradaCjenika = new TFIzradaCjenika(this);
	FIzradaCjenika->ShowModal();
	delete FIzradaCjenika;
	FIzradaCjenika = nullptr;
}
//---------------------------------------------------------------------------

void __fastcall TFGlavna::Pretragaguma1Click(TObject *Sender)
{
	FPretragaGuma = new TFPretragaGuma(this);
	FPretragaGuma->ShowModal();
	delete FPretragaGuma;
    FPretragaGuma = nullptr;
}
//---------------------------------------------------------------------------

