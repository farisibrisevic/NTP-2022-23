#include<iostream>
#include<cmath>
using namespace std;
int iste_cifre(int a,int b){  //vraæa broj sastavljen od onih cifara iz broja a koje se nalaze i u broju b
	int n[5],m[5],i,j,d,f,k[5],br,broj;
	i=0;
	do{ //cifre broja a pretvara u clanove niza n
		n[i]=a%10;
		a=a/10;
		i++;
	}while(a!=0);
	j=0;
	do{ //cifre broja b pretvara u clanove niza m
		m[j]=b%10;
		b=b/10;
		j++;
	}while(b!=0);
	br=0;
	for(d=i;d>=0;d--){    // ispituje elemente nizova m i n
	 for(f=j;f>=0;f--){    
	 	if(n[d]==m[f]){
	 		k[br]=n[d];  //clanove koji su jednaki pridruzuje novom nizu k
	 		br++;
		 }
	 }
}
br=br-1;
broj=0;
for(int v=0;v<=br;v++){  //clanove niza k pretvara u broj
	broj+=k[v]*pow(10,br-v); 
}
return broj;
}
int main(){
    int b1,b2;
	cout<<"Unesi prvi broj: ";
    cin>>b1;
    cout<<"Unesi drugi broj: ";
    cin>>b2;
    cout<<endl;
    cout<<"Broj sastavljen od cifri broja "<<b1<<" a koje su sadrzane u broju "<<b2<<" je "<< iste_cifre(b1,b2)<<endl;
	
	system("pause");
	return 0;
};
