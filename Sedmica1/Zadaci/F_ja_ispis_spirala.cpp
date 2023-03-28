#include <iostream>
#include <iomanip>
#include <conio.h>
using namespace std;
short matrica[20][20];
short n;

void popuni()
{
    short krug = 0;
    short count = 0;
    while(true)
    {
        for(short x = krug; x < n-krug; x++)
            matrica[x][krug] = ++count;
        for(short y = krug+1; y < n-krug; y++)
            matrica[n-krug-1][y] = ++count;
        for(short x = n-2-krug; x > krug-1; x--)
            matrica[x][n-krug-1] = ++count;
        for(short y = n-2-krug; y > krug; y--)
            matrica[krug][y] = ++count;
        if(count == n*n)return;
        krug++;
    }
}

int main()
{
    n = -1;while(n < 2)cin>>n;
    popuni();
    for(short int y = 0; y < n; y++)
    {
        for(short int x = 0; x < n; x++)
            cout<<setw(4)<<matrica[x][y];
        cout<<endl;
    }
    system("PAUSE");
    return 0;
}
