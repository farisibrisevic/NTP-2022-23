//Napisati rekurzivnu funkciju koja raèuna najveæu cifru datog cjelog broja i program koji testira rad funkcije.
#include <iostream>
using namespace std;
int veci(int a, int b)
	{
 		if (a > b) return a;
 		else return b;
	}

int najveca(int n)
	{
 		if (n<10) return n;
 		else return veci(najveca(n/10), n%10);
	}

int main()
	{
 	int n;
 	cout<<"Unesi broj\n";
 	cin>>n;
 	cout<<"Najveca cifara je: "<<najveca(n)<<endl;
 	system("Pause");
 	return 0;
	}	 
