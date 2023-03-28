//Uèitati dva cijela broja sa tastature, M i N. Pronaci sve kombinacije izraza:
        				//(((...(1?2)?3)?4)?5 ... ?N) = M
#include <cstdlib>
#include <iostream>
#define MAXN 35000
#define MAXM 35000
using namespace std;

long M, N;
char* rijesenje;
int ukupno=0;

void ispis() {
     ukupno++;
     for (int i=1; i<N; i++)
         cout<<"(";
     cout<<'1';
     
     for (int j=1; j<N; j++)
         cout<<rijesenje[j]<<j+1<<')';
     cout<<" = "<<M<<endl;
}

void rekurzija(long pozicija, long rezultat) {
     if (pozicija>N) {       		 	// nadjen rezultat
        if (rezultat == M)   		// tacno rijesenje
           ispis();
        return;
     }
     rijesenje[pozicija-1]='+';
     rekurzija(pozicija+1, rezultat+pozicija);

     rijesenje[pozicija-1]='-';
     rekurzija(pozicija+1, rezultat-pozicija);
     
     rijesenje[pozicija-1]='*';
     rekurzija(pozicija+1, rezultat*pozicija);
     
     rijesenje[pozicija-1]='/';
     rekurzija(pozicija+1, rezultat/pozicija);
}

void ulaz() {
     cout<<"Unesite trazeni broj " << endl;
     cin>>M;
     cout<<"Unesite broj N do koga se vrse operacije " << endl;
     cin>>N;
     
     if (M>MAXM || N>MAXN || M<-MAXM || N<1) {
                cout<<"Unijeli ste lose brojeve!"<<endl;
                system("PAUSE");
                exit(0);
                }
        
     rijesenje = new char[MAXN];
     memset((void*)rijesenje, '?', MAXN*sizeof(char));  
     /*
     dozvoljava “punjenje” memorije nekim drugim sadrzajem (zamjena za copy)
     
     */   
}

int main(int argc, char *argv[])
{
    ulaz();
    cout<<"Broj "<<M<< " se moze dobiti na slijedeci nacin(e):"<<endl;
    rekurzija(2, 1);
    if (ukupno==0)
       cout<<"Nema rijesenja!"<<endl;
    system("PAUSE");
    return EXIT_SUCCESS;
}
