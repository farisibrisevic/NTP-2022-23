/*-----------------------------------------------------*\
| prostFaktor.cpp                                       |
|                                                       |
| Program za razlaganje cijelog broja na proste faktore |
\*-----------------------------------------------------*/

#include <iostream>
#include <cmath>
using namespace std;

void faktor(int n);   // Funkcija za prikaz prostih faktora cijelog broja
int minDjel(int n);   // Funkcija koja nalazi najmanji djelilac
                      // cijelog broja izmedju 2 i n
bool parni(int broj); // Funkcija za indikaciju parnog broja

int main()
{
  for(int i = 1; i <= 1000; i++)
  {
    faktor(i);
  }

  system("PAUSE");
  return 0;
}

// Definicija funkcije za prikaz prostih faktora
void faktor(int n)
{
  // Ispisuje najmanji prosti faktor
  int trenutniFaktor = minDjel(n);
  cout << n << " = " << trenutniFaktor;

  // Ispisuje ostale faktore
  for (int naredniFaktor = n / trenutniFaktor;
       naredniFaktor > 1;
       naredniFaktor /= trenutniFaktor)
  {
    trenutniFaktor = minDjel(naredniFaktor);
    cout << " x " << trenutniFaktor;
  }
  cout << endl;
}

// Definicija funkcije koja nalazi najmanji djelilac
int minDjel(int n)
{
  int pokusaj;  // Kandidat za najmanji djelilac od n
  int djelilac; // Najmanji djelilac od n - nula znaci djelilac jos nije pronadjen

  // Inicijalizacija za djelilac i pokusaj zavisno od toga
  // da li je n parni ili neparni broj
  if (parni(n))
  {
    djelilac = 2;
  }
  else
  {
    djelilac = 0;
    pokusaj = 3;
  }

  // Testiranje neparnih brojeva da li su djelilac od n dok se djelilac ne pronadje
  // ili dok pokusaj ne poraste dovoljno da se vidi da je sam n najmanji djelilac
  while (djelilac == 0)
  {
    if (pokusaj > sqrt(n))
      djelilac = n;
    else if ((n % pokusaj) == 0)
      djelilac = pokusaj;
    else
      pokusaj += 2;
  }

  return djelilac;
}

// Definicija funkcije za indikaciju parnog broja
bool parni (int broj) 
{
  bool rez = ((broj % 2) == 0);
  return rez;
}
