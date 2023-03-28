#include <iostream> 
#include <iomanip> 
#include <cstdlib>
#include <ctime>
#include <conio.h>
using namespace std; 
int niz[1000]; 
 
void QuickSort(int lijevi, int desni, int niz[]){  
int i=lijevi;  
int j=desni;  
int pivot=niz[(lijevi+desni)/2];  
	while (i<=j){   
		while(niz[i]<pivot)    
			i=i+1;   
		while(pivot<niz[j])    
			j=j-1;   
		if(i<=j){    
			int temp=niz[i];    
			niz[i]=niz[j];    
			niz[j]=temp;    
			i=i+1;    
			j=j-1;   
			}
	} 
	if (lijevi < j)  
		QuickSort(lijevi, j, niz);  
	if (i < desni) 
		QuickSort(i, desni, niz); 
} 
 
int main(){  
int broj, i;  
cout<<"\n\nUnesi broj elemenata u nizu: ";  
cin>>broj;  
cout<<"\n\nElementi niza su: \n\n";  
	for(i=1; i<=broj; i++){   
		niz[i]=rand()%1000+1;   
		cout<<setw(5)<<niz[i];  
	}
cout<<"\n\n";      
	QuickSort(1, broj, niz);     
cout<<"\n\nSortirani niz: \n\n";  
	for(i=1; i<=broj; i++){         
		cout<<setw(5)<<niz[i];        
	}
cout<<"\n\n\n";  	
system("pause");  
return 0; 
} 
