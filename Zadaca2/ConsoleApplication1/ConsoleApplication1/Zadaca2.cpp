//Ovaj program koristi `struct` za definiranje struktura `student` i `ocjena`. Oba niza struktura ograničena su na maksimalni broj elemenata koji se mogu unijeti.

//Funkcija `postojiStudent` provjerava da li student s datim indeksom već postoji u nizu `studenti`. Funkcija `ispisiOcjene` traži studenta s 
//datim indeksom u nizu `ocjene` i ispisuje njegove ocjene.

//Glavni dio programa sadrži pet opcija koje korisnik može odabrati.Ako korisnik odabere opciju 1, 
//program traži unos imena, prezimena i indeksa novog studenta te provjerava da li je indeks već unesen.Ako je sve u redu, novi student se dodaje u niz `studenti`.

//Ako korisnik odabere opciju 2, program ispisuje popis svih studenata koji su uneseni.

//Ako korisnik odabere opciju 3, program traži unos indeksa studenta te poziva funkciju `ispisiOcjene` da bi ispisao ocjene tog studenta.

//Ako korisnik odabere opciju 4, program traži unos predmeta i minimalne ocjene te ispisuje popis svih studenata koji su dobili ocjenu veću ili jednaku



#include <iostream>
#include <cstring>

using namespace std;

const int MAX_STUDENTS = 100;
const int MAX_GRADES = 1000;

struct student {
    char ime[20];
    char prezime[30];
    int index;
};

struct ocjena {
    int indeks;
    int br_predmeta;
    int ocjena;
};

// Funkcija koja provjerava da li student s datim indeksom već postoji u nizu
bool postojiStudent(student* studenti, int n, int indeks) {
    for (int i = 0; i < n; i++) {
        if (studenti[i].index == indeks) {
            return true;
        }
    }
    return false;
}

// Funkcija koja traži studenta s datim indeksom i ispisuje njegove ocjene
void ispisiOcjene(ocjena* ocjene, int n, int indeks) {
    bool pronadjen = false;
    float suma = 0;
    int broj_ocjena = 0;
    for (int i = 0; i < n; i++) {
        if (ocjene[i].indeks == indeks) {
            if (!pronadjen) {
                cout << "Student sa indeksom " << indeks << ":\n";
                cout << ocjene[i].br_predmeta << " predmeta:\n";
                pronadjen = true;
            }
            cout << ocjene[i].br_predmeta << ". predmet: " << ocjene[i].ocjena << "\n";
            suma += ocjene[i].ocjena;
            broj_ocjena++;
        }
    }
    if (pronadjen) {
        cout << "Prosjek ocjena: " << suma / broj_ocjena << "\n";
    }
    else {
        cout << "Nema studenta sa indeksom " << indeks << "\n";
    }
}
//Glavna f-ja za unos studenata i ocjena, trazenje i ispis istih te ostalih parametara zadanih po zadatku. 
int main() {
    student studenti[MAX_STUDENTS];
    ocjena ocjene[MAX_GRADES];
    int broj_studenata = 0;
    int broj_ocjena = 0;

    while (true) {
        cout << "Izaberite opciju:\n";
        cout << "1. Unos studenta\n";
        cout << "2. Ispis svih studenata\n";
        cout << "3. Ispis ocjena studenta\n";
        cout << "4. Ispis studenata s ocjenom vecom od zadane\n";
        cout << "5. Izlaz iz programa\n";

        int opcija;
        cin >> opcija;

        if (opcija == 1) {
            if (broj_studenata == MAX_STUDENTS) {
                cout << "Nema dovoljno mjesta za unos novog studenta\n";
            }
            else {
                cout << "Unesite ime, prezime i indeks studenta:\n";
                char ime[20];
                char prezime[30];
                int indeks;
                cin >> ime >> prezime >> indeks;
                if (postojiStudent(studenti, broj_studenata, indeks)) {
                    cout << "[GRESKA] Student sa tim indeksom već postoji\n";
                }
                else {
                    strcpy_s(studenti[broj_studenata].ime, ime);
                    strcpy_s(studenti[broj_studenata].prezime, prezime);
                    studenti[broj_studenata].index = indeks;
                    broj_studenata++;
                    cout << "Student uspjesno dodan\n";
                }
            }
        }
        else if (opcija == 2) {
            cout << "Popis studenata:\n";
            for (int i = 0; i < broj_studenata; i++) {
                cout << studenti[i].ime << " " << studenti[i].prezime << ", " << studenti[i].index << "\n";
            }
        }
        else if (opcija == 3) {
            cout << "Unesite indeks studenta:\n";
            int indeks;
            cin >> indeks;
            ispisiOcjene(ocjene, broj_ocjena, indeks);
        }
        else if (opcija == 4) {
            cout << "Unesite predmet i minimalnu ocjenu:\n";
            int predmet;
            int ocjena;
            cin >> predmet >> ocjena;
            cout << "Studenti sa ocjenom " << ocjena << " ili većom iz predmeta " << predmet << ":\n";
            for (int i = 0; i < broj_ocjena; i++) {
                if (ocjene[i].br_predmeta == predmet && ocjene[i].ocjena >= ocjena) {
                    for (int j = 0; j < broj_studenata; j++) {
                        if (studenti[j].index == ocjene[i].indeks) {
                            cout << studenti[j].ime << " " << studenti[j].prezime << ", " << studenti[j].index << "\n";
                            break;
                        }
                    }
                }
            }
        }
        else if (opcija == 5) {
            break;
        }
        else {
            cout << "Pogrešna opcija\n";
        }
    }

    return 0;

}

//Faris Ibrisevic, 2023., 


