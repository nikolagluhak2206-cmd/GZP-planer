\# GZP Planer (Gume Zelina Planer)



Desktop aplikacija (Windows, C++Builder / VCL) za upravljanje poslovanjem vulkanizerskog servisa/skladišta guma — zakazivanje termina, "hotel guma" (sezonsko skladištenje), cjenik, pretraga dimenzija guma po vozilu, upravljanje korisnicima i crna lista (blokirane registracije vozila).



> Napomena: ovaj README je sastavljen na temelju pregleda strukture i izvornog koda repozitorija. Neki detalji (npr. točan izvor podataka za pretragu guma) mogu se razlikovati — po potrebi ih prilagodi.



\## Sadržaj



\- \[O aplikaciji](#o-aplikaciji)

\- \[Značajke](#značajke)

\- \[Tehnologije](#tehnologije)

\- \[Struktura projekta](#struktura-projekta)

\- \[Baza podataka](#baza-podataka)

\- \[Preduvjeti](#preduvjeti)

\- \[Instalacija i pokretanje](#instalacija-i-pokretanje)

\- \[Korištenje](#korištenje)

\- \[Sigurnost](#sigurnost)

\- \[Poznata ograničenja](#poznata-ograničenja)

\- \[Licenca](#licenca)



\## O aplikaciji



GZP Planer je interni alat za servis guma koji objedinjuje:



\- kalendarsko zakazivanje termina,

\- vođenje korisničkih računa djelatnika s razinama pristupa (role),

\- evidenciju vozila na "crnoj listi" (npr. zbog neplaćanja ili nedolazaka),

\- skladištenje ("hotel guma") sezonskih guma korisnika uz mogućnost ispisa potvrde,

\- izradu cjenika usluga,

\- pretragu preporučenih dimenzija guma prema marki, modelu, izvedbi i godini proizvodnje vozila.



Aplikacija je izvorno razvijena za servis "Gume Zelina" (naziv projektne datoteke: `Gume Zelina Planer.cbproj`).



\## Značajke



\### 🔐 Prijava i korisnici

\- Prijava korisnim imenom i lozinkom (`Login`), lozinke se ne čuvaju u čitljivom obliku (hashing).

\- Uloge korisnika (`role`) — razlikuju se prava pristupa (npr. administrator vs. djelatnik).

\- Dodavanje novih korisnika (`DodajKorisnika`) i uređivanje postojećih (`UrediKorisnike`) — dostupno administratoru.

\- Promjena trenutnog korisnika i uređivanje vlastitog profila iz glavnog izbornika.



\### 📅 Glavni ekran — kalendar termina

\- Mjesečni kalendar (`Glavna`) za pregled i odabir datuma.

\- Tablični prikaz termina za odabrani dan, dohvaćen iz baze putem ADO upita.

\- Desni klik na termin nudi opciju "Dodaj na crnu listu" uz unos razloga.



\### 🚫 Crna lista

\- Evidencija registracijskih oznaka vozila koja se ne smiju/ne trebaju uslužiti (`CrnaLista`, `UpravljanjeCrnomListom`).

\- Automatska provjera i vizualno isticanje termina čije je vozilo na crnoj listi.

\- Upravljački ekran za pregled, dodavanje i uklanjanje unosa s crne liste.



\### 🏨 Hotel guma (sezonsko skladištenje)

\- Evidencija pohranjenih guma po vlasniku: ime, broj mobitela, marka i dimenzija gume, lokacija skladištenja, napomena, datum zaprimanja (`HotelGume`).

\- Dodavanje, izmjena, brisanje i pretraga unosa.

\- Podaci se pohranjuju/učitavaju u JSON formatu (`HotelGume.json`), uz podršku za enkripciju osjetljivih podataka.

\- Ispis potvrde o zaprimanju guma na čuvanje putem FastReport predloška (`Potvrda o zaprimanju guma na čuvanje.fr3`).



\### 💰 Cjenik

\- Kreiranje i uređivanje cjenika usluga (`IzradaCjenika`, `cjenik`), s podacima pohranjenim u `cjenik.xml` / `cjenik.xdb`.

\- Ispis/generiranje cjenika putem FastReport izvještaja.



\### 🔎 Pretraga guma po vozilu

\- Kaskadni odabir: godina proizvodnje → marka → model → izvedba (`PretragaGuma`).

\- Dohvat preporučenih dimenzija guma putem HTTP poziva vanjskom API-ju (`TNetHTTPClient`, JSON odgovor).



\### ⚙️ Postavke

\- Postavke aplikacije čitaju se/spremaju kroz `.ini` datoteku i/ili registar (`Postavke`, `Postavke\_ini`, `Postavke\_reg`).

\- Podrška za višejezičnost sučelja (komponente `siLang` / `siLangCombo`), uključena zastava Hrvatske (`Flag\_of\_Croatia.bmp`) kao indikator jezika.



\## Tehnologije



| Sloj | Tehnologija |

|---|---|

| Jezik / okvir | C++ (Embarcadero C++Builder, VCL) |

| UI komponente | VCL (`TForm`, `TStringGrid`, `TMonthCalendar`, `TListView` ...) |

| Baza podataka | Microsoft Access (`GZP.mdb`) putem ADO (`Data.Win.ADODB`) |

| Izvještaji / ispis | FastReport VCL (`.fr3` predlošci) |

| Enkripcija / hash | TurboPower LockBox (`uTPLb\_Codec`, `uTPLb\_Hash`, `uTPLb\_CryptographicLibrary`) |

| Mrežni pozivi | `System.Net.HttpClient` (REST/JSON poziv za pretragu guma) |

| Pohrana podataka | JSON (hotel guma), XML (cjenik), INI/registar (postavke) |

| Višejezičnost | Sisulizer komponente (`siComp`, `siLngLnk`, `siLangCombo`) |



\## Struktura projekta



```

GZP-planer/

├── Gume Zelina Planer.cbproj      # Glavna projektna datoteka (C++Builder)

├── Gume Zelina Planer.cpp         # Ulazna točka aplikacije

├── Gume Zelina PlanerPCH1.h       # Precompiled header

├── Login.cpp / .h / .dfm          # Ekran za prijavu

├── Glavna.cpp / .h / .dfm         # Glavni prozor (kalendar + termini)

├── Korisnik.cpp / .h              # Model podataka korisnika

├── DodajKorisnika.cpp / .h / .dfm # Dodavanje korisnika

├── UrediKorisnike.cpp / .h / .dfm # Uređivanje korisnika

├── PodaciPrijava.cpp / .h / .dfm  # Podaci o prijavi/tvrtki

├── CrnaLista.cpp / .h / .dfm/.fr3 # Dijalog dodavanja na crnu listu

├── UpravljanjeCrnomListom.\*       # Pregled/upravljanje crnom listom

├── HotelGume.cpp / .h / .dfm      # Modul "hotel guma" (skladištenje)

├── HotelGume.json                 # Pohranjeni podaci hotela guma

├── IzradaCjenika.cpp / .h / .dfm  # Izrada/uređivanje cjenika

├── cjenik.cpp / .h / .xml / .xdb  # Model i podaci cjenika

├── PretragaGuma.cpp / .h / .dfm   # Pretraga dimenzija guma po vozilu

├── Postavke.\* / Postavke\_ini.\* / Postavke\_reg.\* # Postavke aplikacije

├── GZP.mdb                        # MS Access baza podataka

├── Report.fr3                     # Dodatni FastReport predložak

├── Potvrda o zaprimanju guma na čuvanje.fr3

├── gume\_zelina.jpg / Flag\_of\_Croatia.bmp # Grafički resursi

├── postavke.ini                   # Konfiguracijska datoteka

└── jezik.sil                      # Datoteka prijevoda (Sisulizer)

```



\## Baza podataka



Aplikacija koristi \*\*Microsoft Access\*\* bazu podataka (`GZP.mdb`) kojoj se pristupa putem \*\*ADO\*\* konekcije (`TADOConnection`, `TADOQuery`). Baza sadrži barem tablice za korisnike, termine i crnu listu — dio podataka (hotel guma, cjenik) drži se odvojeno u JSON/XML datotekama.



\## Preduvjeti



Za razvoj i pokretanje aplikacije potrebno je:



\- \*\*Windows\*\* operacijski sustav

\- \*\*Embarcadero C++Builder / RAD Studio\*\* (verzija kompatibilna s korištenim VCL i FastReport komponentama)

\- Instalirane komponente:

&#x20; - \*\*FastReport VCL\*\*

&#x20; - \*\*TurboPower LockBox\*\* (uTPLb biblioteke za enkripciju/hash)

&#x20; - \*\*Sisulizer runtime\*\* komponente (`siComp`, `siLngLnk`, `siLangCombo`) za višejezičnost

\- \*\*Microsoft Access Database Engine\*\* (ACE/Jet OLEDB driver) za pristup `.mdb` bazi putem ADO-a

\- Pristup internetu (za modul pretrage guma koji poziva vanjski API)



\## Instalacija i pokretanje



1\. Kloniraj repozitorij:

&#x20;  ```bash

&#x20;  git clone https://github.com/nikolagluhak2206-cmd/GZP-planer.git

&#x20;  ```

2\. Otvori `Gume Zelina Planer.cbproj` u Embarcadero C++Builderu.

3\. Provjeri i po potrebi instaliraj nedostajuće komponente (FastReport, TurboPower LockBox, Sisulizer).

4\. Provjeri da je `GZP.mdb` u istom direktoriju kao izvršna datoteka (ili prilagodi putanju u konekcijskom stringu).

5\. Buildaj projekt (Build/Compile) i pokreni (`Run`).



\## Korištenje



1\. \*\*Prijava\*\* — pri pokretanju aplikacije unosi se korisničko ime i lozinka.

2\. \*\*Glavni ekran\*\* — nakon prijave prikazuje se kalendar; odabirom datuma učitavaju se termini za taj dan u tablici.

3\. \*\*Crna lista\*\* — desnim klikom na termin moguće je dodati registraciju vozila na crnu listu uz naveden razlog; termini povezani s vozilima na crnoj listi vizualno su istaknuti.

4\. \*\*Hotel guma\*\* — kroz izbornik otvara se modul za unos/pretragu pohranjenih guma (vlasnik, kontakt, dimenzija, lokacija, datum), s mogućnošću ispisa potvrde o zaprimanju.

5\. \*\*Cjenik\*\* — kreiranje/uređivanje stavki cjenika i njegov ispis.

6\. \*\*Pretraga guma\*\* — odabirom godine proizvodnje, marke, modela i izvedbe vozila dohvaćaju se preporučene dimenzije guma.

7\. \*\*Korisnici i postavke\*\* — administratori mogu dodavati/uređivati korisničke račune te mijenjati postavke aplikacije (uključujući jezik sučelja).



\## Sigurnost



\- Lozinke korisnika se hashiraju prije spremanja/provjere (TurboPower LockBox `THash`).

\- Podaci u modulu "hotel guma" mogu se enkriptirati (`TCodec` / `TCryptographicLibrary`) prije zapisa u JSON.



\## Poznata ograničenja



\- Aplikacija je vezana uz Windows/VCL okruženje i ne može se pokretati na drugim platformama bez značajnog prepravljanja.

\- Baza podataka (`.mdb`) pogodna je za manji, lokalni obujam podataka; nije predviđena za rad više korisnika istovremeno preko mreže bez dodatnih prilagodbi.

\- Modul pretrage guma ovisi o dostupnosti vanjskog API-ja.



