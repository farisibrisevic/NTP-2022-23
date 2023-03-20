//Napisati rekurzivnu funkciju koja prikazuje dekadne cifre datog cjelog broja.
//Napisati rekurzivnu funkciju koja prikazuje dekadne cifre datog cjelog broja u obrnutom poretku.
#include <iostream>
using namespace std;
void ispisi_cifre(int x)
{
 		if (x < 10) cout<<x;
 	else
 	{
 	ispisi_cifre(x/10);
 	cout<<x%10;
 	}
}

void ispisi_cifre2(int x)
{
 	if (x < 10) cout<<x;
 	else
 	{
 	cout<<x%10;
 	ispisi_cifre2(x/10);
 	}
}

int main()
{
 int n;
 cout<<"Unesi broj\n";
 cin>>n;
 printf("Cifre su: ");
 ispisi_cifre(n);
 cout<<"\n";
 ispisi_cifre2(n);
 cout<<"\n";
 system("PAUSE");
 return 0;
}

