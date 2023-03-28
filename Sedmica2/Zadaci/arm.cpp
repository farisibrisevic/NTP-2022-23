#include <iostream>
using namespace std;
 
bool DaLiJeArmstrong(int broj) {
  int suma = 0;
  int temp = broj;
  int tekuca_cifra = 0;
 
  while (broj > 0) {
        tekuca_cifra = broj % 10;
       suma += tekuca_cifra * tekuca_cifra * tekuca_cifra;
    broj /= 10;
  }
  if (suma == temp) {
    return true;
  } else
    return false;
}
 
int main() {
  int broj;
 
  
  for(int i=100;i<1000; i++)
  {
  	if (DaLiJeArmstrong(i))
	  cout<<i<<" "<<endl;
  }
 
  system("Pause");
  return 0;
}
