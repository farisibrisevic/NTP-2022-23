#include <iostream>
using namespace std;
double Seta();

int main (){
	cout << "Ukupan broj zrna psenice iznosi : ";
	cout << Seta();
	}

double Seta(){
	 double zrna=1,polje,suma=1;
	for (int i=1;i<=64;i++){
		zrna=2*zrna;
		suma=suma+zrna;
	}
	polje=suma/64;
	cout << suma<< endl;
	cout << "Broj zrna po polju sahovske ploce je : ";
	return polje;
}
