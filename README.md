# GZP Planer (Gume Zelina Planer)

Desktop aplikacija za Windows razvijena u C++Builderu / VCL-u za upravljanje poslovanjem vulkanizerskog servisa i skladišta guma.

Aplikacija omogućuje zakazivanje termina, evidenciju korisnika, upravljanje crnom listom vozila, sezonsko skladištenje guma ("hotel guma"), izradu cjenika te pretragu preporučenih dimenzija guma prema podacima o vozilu.

## Sadržaj

* [O aplikaciji](#o-aplikaciji)
* [Značajke](#značajke)
* [Tehnologije](#tehnologije)
* [Struktura projekta](#struktura-projekta)
* [Baza podataka](#baza-podataka)
* [Preduvjeti](#preduvjeti)
* [Instalacija i pokretanje](#instalacija-i-pokretanje)
* [Korištenje](#korištenje)
* [Sigurnost](#sigurnost)
* [Poznata ograničenja](#poznata-ograničenja)
* [Licenca](#licenca)

## O aplikaciji

GZP Planer je desktop aplikacija izvorno razvijena za servis "Gume Zelina".

Cilj aplikacije je objediniti svakodnevne funkcionalnosti potrebne za rad vulkanizerskog servisa na jednom mjestu:

* zakazivanje i pregled termina
* upravljanje korisničkim računima i korisničkim ulogama
* evidencija vozila na crnoj listi
* sezonsko skladištenje guma korisnika
* izrada i ispis cjenika
* pretraga preporučenih dimenzija guma prema vozilu
* generiranje izvještaja i potvrda
* podrška za hrvatski i engleski jezik
* spremanje postavki aplikacije

Projekt je izrađen u Embarcadero C++Builderu koristeći VCL framework.

## Značajke

### Prijava i korisnici

* Prijava korisničkim imenom i lozinkom.
* Lozinke se ne spremaju u čitljivom obliku, već se hashiraju.
* Sustav korisničkih uloga (`role`) omogućuje različite razine pristupa.
* Administratori mogu dodavati i uređivati korisničke račune.
* Korisnik može uređivati vlastiti profil.

### Glavni ekran i termini

* Mjesečni kalendar za pregled i odabir datuma.
* Tablični prikaz termina za odabrani dan.
* Dohvat podataka iz Microsoft Access baze putem ADO-a.
* Dodavanje, uređivanje i upravljanje terminima.
* Mogućnost dodavanja registracije na crnu listu iz konteksta termina.

### Crna lista

* Evidencija registracijskih oznaka vozila.
* Spremanje razloga zbog kojeg je vozilo dodano na crnu listu.
* Automatska provjera vozila prilikom rada s terminima.
* Vizualno označavanje termina povezanih s vozilima na crnoj listi.
* Administracija zapisa crne liste.

### Hotel guma

Modul "Hotel guma" služi za evidenciju sezonski pohranjenih guma.

Za svaki zapis moguće je evidentirati:

* vlasnika
* broj mobitela
* marku i dimenziju guma
* lokaciju skladištenja
* napomenu
* datum zaprimanja

Podaci se pohranjuju u JSON formatu, uz mogućnost enkripcije osjetljivih podataka.

Za korisnika je moguće generirati potvrdu o zaprimanju guma putem FastReport predloška.

### Cjenik

* Kreiranje i uređivanje cjenika usluga.
* Spremanje podataka u XML formatu.
* Učitavanje i prikaz podataka iz cjenika.
* Generiranje i ispis cjenika putem FastReporta.

### Pretraga guma po vozilu

Modul omogućuje kaskadni odabir:

1. godine proizvodnje
2. marke vozila
3. modela
4. izvedbe

Nakon odabira vozila aplikacija putem HTTP zahtjeva dohvaća preporučene dimenzije guma iz vanjskog API-ja.

Podaci API-ja obrađuju se u JSON formatu.

### Postavke i višejezičnost

* Spremanje postavki pomoću INI datoteke i registra.
* Podrška za hrvatski i engleski jezik.
* Promjena jezika unutar aplikacije.
* Podrška za tamni način rada.
* Spremanje određenih korisničkih postavki između pokretanja aplikacije.

## Tehnologije

| Kategorija         | Tehnologija                                                    |
| ------------------ | -------------------------------------------------------------- |
| Programski jezik   | C++                                                            |
| IDE / framework    | Embarcadero C++Builder / RAD Studio, VCL                       |
| Korisničko sučelje | VCL (`TForm`, `TStringGrid`, `TMonthCalendar`, `TListView`...) |
| Baza podataka      | Microsoft Access (`GZP.mdb`)                                   |
| Pristup bazi       | ADO (`TADOConnection`, `TADOQuery`)                            |
| Izvještaji         | FastReport VCL                                                 |
| Kriptografija      | TurboPower LockBox                                             |
| Mrežni zahtjevi    | `System.Net.HttpClient`                                        |
| Podaci             | JSON, XML                                                      |
| Postavke           | INI datoteke i Windows Registry                                |
| Lokalizacija       | Sisulizer                                                      |

## Struktura projekta

```text
GZP-planer/

├── Gume Zelina Planer.cbproj       # Glavna projektna datoteka
├── Gume Zelina Planer.cpp          # Ulazna točka aplikacije
├── Gume Zelina PlanerPCH1.h        # Precompiled header
│
├── Login.cpp / .h / .dfm           # Ekran za prijavu
├── Glavna.cpp / .h / .dfm          # Glavni prozor i kalendar
├── Korisnik.cpp / .h               # Model korisnika
├── DodajKorisnika.cpp / .h / .dfm  # Dodavanje korisnika
├── UrediKorisnike.cpp / .h / .dfm  # Uređivanje korisnika
├── PodaciPrijava.cpp / .h / .dfm   # Podaci o prijavi
│
├── CrnaLista.cpp / .h / .dfm       # Crna lista
├── UpravljanjeCrnomListom.*        # Upravljanje crnom listom
│
├── HotelGume.cpp / .h / .dfm       # Modul hotel guma
├── HotelGume.json                  # Podaci hotela guma
│
├── IzradaCjenika.cpp / .h / .dfm   # Izrada cjenika
├── cjenik.cpp / .h / .xml / .xdb   # Cjenik
│
├── PretragaGuma.cpp / .h / .dfm    # Pretraga guma
│
├── Postavke.*                      # Postavke aplikacije
├── Postavke_ini.*                  # Postavke putem INI datoteke
├── Postavke_reg.*                  # Postavke putem registra
│
├── GZP.mdb                         # Microsoft Access baza
├── Report.fr3                      # FastReport predložak
├── Potvrda o zaprimanju guma na čuvanje.fr3
│
├── gume_zelina.jpg                 # Grafički resurs
├── Flag_of_Croatia.bmp             # Grafički resurs
├── postavke.ini                    # Konfiguracija
└── jezik.sil                       # Datoteka prijevoda
```

## Baza podataka

Aplikacija koristi Microsoft Access bazu podataka `GZP.mdb`.

Pristup bazi ostvaren je pomoću ADO tehnologije kroz komponente kao što su:

* `TADOConnection`
* `TADOQuery`
* `TADOTable`
* `TDataSource`

Baza sadrži podatke vezane uz korisnike, termine i crnu listu.

Podaci za modul "Hotel guma" i cjenik pohranjuju se odvojeno u JSON i XML datotekama.

## Preduvjeti

Za razvoj i pokretanje aplikacije potrebno je:

* Windows operacijski sustav
* Embarcadero C++Builder / RAD Studio
* FastReport VCL
* TurboPower LockBox
* Sisulizer runtime komponente
* Microsoft Access Database Engine / odgovarajući OLEDB driver
* pristup internetu za modul pretrage guma

Za potpuno otvaranje i kompajliranje projekta potrebno je imati instalirane korištene vanjske komponente.

## Instalacija i pokretanje

Kloniranje repozitorija:

```bash
git clone https://github.com/nikolagluhak2206-cmd/GZP-planer.git
```

Nakon kloniranja:

1. Otvori `Gume Zelina Planer.cbproj` u Embarcadero C++Builderu.
2. Provjeri jesu li instalirane potrebne komponente.
3. Provjeri konfiguraciju konekcije prema `GZP.mdb` bazi.
4. Buildaj projekt.
5. Pokreni aplikaciju.

## Korištenje

### 1. Prijava

Prilikom pokretanja aplikacije korisnik se prijavljuje svojim korisničkim imenom i lozinkom.

### 2. Glavni ekran

Nakon uspješne prijave prikazuje se glavni ekran s kalendarom i terminima.

Odabirom određenog datuma prikazuju se termini rezervirani za taj dan.

### 3. Crna lista

Registracija vozila može se dodati na crnu listu, zajedno s razlogom dodavanja.

Aplikacija automatski provjerava nalazi li se registracija na crnoj listi te prema tome označava termine.

### 4. Hotel guma

Modul omogućuje unos, izmjenu, brisanje i pretragu podataka o pohranjenim gumama.

Za zaprimljene gume moguće je generirati potvrdu putem FastReporta.

### 5. Cjenik

Omogućeno je kreiranje i uređivanje stavki cjenika te generiranje ispisa.

### 6. Pretraga guma

Korisnik odabire podatke o vozilu, nakon čega aplikacija dohvaća preporučene dimenzije guma putem vanjskog API-ja.

### 7. Korisnici i postavke

Administratori mogu upravljati korisničkim računima i korisničkim ulogama.

U postavkama je moguće mijenjati jezik i druge postavke aplikacije.

## Sigurnost

* Lozinke korisnika hashiraju se prije spremanja i provjere.
* Za hashiranje se koristi TurboPower LockBox.
* Za dodatnu sigurnost pri obradi lozinki korišteni su salt i pepper mehanizmi.
* Podaci modula "Hotel guma" mogu se enkriptirati prije spremanja u JSON.
* Za enkripciju se koriste TurboPower LockBox `TCodec` i `TCryptographicLibrary`.


## Poznata ograničenja

* Aplikacija je namijenjena Windows operacijskom sustavu i VCL okruženju.
* Za kompajliranje projekta potrebne su vanjske komponente korištene tijekom razvoja.
* Microsoft Access baza prikladna je prvenstveno za manji lokalni sustav.
* Rad većeg broja korisnika istovremeno preko mreže zahtijevao bi dodatnu prilagodbu arhitekture.
* Modul za pretragu guma ovisi o dostupnosti vanjskog API-ja.
* Projekt je razvijen kao desktop aplikacija i nije predviđen za mobilne ili web platforme.

## Licenca

Projekt je izrađen u edukativne svrhe.

Autor: Nikola Gluhak

---

### Napomena

README dokument je generiran uz pomoć Claude-a
