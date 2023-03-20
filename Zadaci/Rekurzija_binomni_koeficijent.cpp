/*Napisati C++ program koji za uneseno n i k izraèunava binomni koeficijent!*/
#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;
 
int Fakt(int n)
	{
 int faktorijel = 1;
 	if (n<=0)
 		{return faktorijel;}
	 else
 		{
 		faktorijel = n * Fakt(n-1);
 		}
	}
 
int main()
{
 int n, binomni, k;
 
cout << "Binomni Koeficijent!" << endl;
cout << "n? ";
cin >> n;
cout << "k? ";
cin >> k;
 
if (k>n)
 	{
 	binomni = 0;
 	cout << "Binomni koeficijent: " << binomni << endl;
 	}
else if (k==0)
	{
 	binomni = 1;
 	cout << "Binomni koeficijent: " << binomni << endl;
 	}
else
 	{
 	binomni = Fakt(n) / (Fakt(k) * Fakt(n - k));
 	cout << "Binomni koeficijent: " << binomni << endl;
 	}
 system("pause");
 return 0;
}

