#include <iostream>
using namespace std;

int brojac = 0;


//F-ja ispod jednostavno ispisuje koji disk se premjestio sa kojeg na koji stub, i broj poteza pomocu brojaca. Broj poteza je 2^n - 1, gdje je n broj diskova.
void pomjeriDisk(int disk, char izvor, char odrediste) {
    brojac++;
    cout<<brojac<<". Disk "<<disk<<" se premjestio sa "<<izvor<<" na "<<odrediste<<endl;
}


//F-ja ispod je "glavna" funkcija. Ako je broj diskova 1, poziva f-ju pomjeriDisk, a ako nije, poziva samu sebe tri puta. 
//Prvi put sa jednim diskom manje, koristeci izvorni stub kao pocetni, i pomocni kao krajnji.
//Drugi put poziva f-ju pomjeriDisk da premjesti najveci disk sa pocetnog na krajnji.
//Zadnji put ponovo poziva samu sebe s jednim diskom manje koristeci pomocni stup kao pocetni i odredisni kao odredisni. 
void hanoiKula(int diskovi, char izvor, char pomocni, char odrediste) {
    if (diskovi == 1) {
        pomjeriDisk(diskovi, izvor, odrediste);
    }
    else {
        hanoiKula(diskovi - 1, izvor, odrediste, pomocni);
        pomjeriDisk(diskovi, izvor, odrediste);
        hanoiKula(diskovi - 1, pomocni, izvor, odrediste);
    }
}
//F-ja main trazi unos diskova od korisnika, i ogranicena je da je unos izmedju tri i 5000. Ako je unos ispod 3, zadatak nema smisla. 
//Koristi se goto za ponovni unos. 
int main() {
    unos:
    int diskovi;
    cout << "Unesi broj diskova (izmedju 3 i 5000): ";
    cin >> diskovi;
    if (diskovi < 3 && diskovi > 5000) {
        cout << "Unos mora biti izmedju 3 i 5000!";
        goto unos;
	}
    char izvor = 'A', pomocni = 'B', odrediste = 'C';
    hanoiKula(diskovi, izvor, pomocni, odrediste);
    return 0;
}

//Faris Ibrisevic, 2023. godina.
