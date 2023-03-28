#include <iostream> 
#include <iomanip> 
#include <cstdlib>
#include <ctime>
#include <conio.h>
using namespace std; 
int niz[1000]; 
 
void Merge(int mali, int srednji, int veliki){  
int h, i, j, k, b[1000];  
h=i=mali;  
j=srednji+1;  
	while((h<=srednji) && (j<=veliki)){   
		if(niz[h]<=niz[j]){    
			b[i]=niz[h];    
			h++;   
		}
		else{    
			b[i]=niz[j];    
			j++;   
		}   
	i++;   
	}   
		
	if(h>srednji){    
		for(k=j; k<=veliki; k++){     
			b[i]=niz[k];     
			i++;    
		}   
	}
	else{    
		for(k=h; k<=srednji; k++){     
			b[i]=niz[k];     
			i++;    
		}   
	}     

	for(k=mali; k<=veliki; k++)    
		niz[k]=b[k]; 
} 
 
void MergeSort(int mali, int veliki){      
int srednji;      
	if (mali<veliki){         
		srednji=(mali+veliki)/2;         
		MergeSort(mali, srednji);         
		MergeSort(srednji+1, veliki);         
		Merge(mali, srednji, veliki);      
	}
} 

int main(){  
int broj, i;  
cout<<"\n\nUnesi broj elemenata u nizu: ";  
cin>>broj;  
cout<<"\n\nElementi niza su: \n\n";  
//niz=new int[broj];  
	for(i=1; i<=broj; i++){   
		niz[i]=rand()%1000+1;   
		cout<<setw(5)<<niz[i];  
	}  
cout<<"\n\n";  
	MergeSort(1, broj);  
cout<<"\n\nSortirani niz: \n\n";  
	for(i=1; i<=broj; i++){         
		cout<<setw(5)<<niz[i];        
	}  
//delete [] niz;  
cout<<"\n\n\n";  
system("pause");  
return 0; 
} 
