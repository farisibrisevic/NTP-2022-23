#include <iostream> 
#include <iomanip> 
using namespace std; 
 
void BinarySearch(int niz[15], int pocetak, int kraj, int broj){  
int srednji, nasao;  
	if(pocetak<=kraj){   
		srednji=(pocetak+kraj)/2;   
			if(niz[srednji]==broj){    
				cout<<"\n\t\tBroj pronaden!\n";    
				nasao=1;   
			}   
				if(broj<niz[srednji]){    
					kraj=srednji-1;    
					BinarySearch(niz, pocetak, kraj, broj);   
				}
				else{    
					pocetak=srednji+1;    
					BinarySearch(niz, pocetak, kraj, broj);   
					}  
			}
	else if (pocetak>kraj && nasao==0){             
		cout<<"\n\t\tBroj nije pronaden!\n";     
	}
}
 
int main(){  
int niz[]={1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};  
int i, broj;  
cout<<"\n\nElementi niza su: \n\n";  
	for(i=0;i<15;i++){   
		cout<<setw(5)<<niz[i];  
	}  
cout<<"\n\n\tTrazi: ";  
cin>>broj;    
	BinarySearch(niz, 0, 15, broj);  
cout<<"\n\n";  
system("pause");  
return 0; 
}
