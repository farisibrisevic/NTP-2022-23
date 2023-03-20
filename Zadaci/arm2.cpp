#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;
int main()
{
    int broj, pos_cifra, cifra, sum, i, end;

    cout<<"Do kojeg broja: ";
    cin>>end;

    cout<<"Armstrongovi brojevi izmeðu 1 i n: "<<endl;

    for(i=1; i<=end; i++)
    {
        sum = 0;
        broj = i;

        cifra = (int) log10(broj) + 1;

        while(broj > 0)
        {
            pos_cifra = broj % 10;
            sum = sum + ceil(pow(pos_cifra, cifra));
            broj = broj / 10;
        }

        if(i == sum)
        {
            cout<<i<<" ";
        }
		
    }
cout<<endl;
    return 0;
}
