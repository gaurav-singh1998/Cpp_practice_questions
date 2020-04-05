#include<bits/stdc++.h>
using namespace std;

int x, y, g;
int GCD(int a, int b)
{
    if(b==0) return a;
    return GCD(b, a%b);
}

void ExtendedGCD(int a, int b)
{
    if(b==0)
    {g=a;
      x=1;
      y=0;
      return;
    }

    ExtendedGCD(b, a%b);
    int cx = y;
    int cy = x-(a/b)*y;

    x=cx;
    y=cy;
}

int multiplicativeModuloInverse(int a, int m)
{
    ExtendedGCD(a, m);
    return (x+m)%m;
}

int main()
{
    int a, b;
    cin >> a >> b;
    cout << multiplicativeModuloInverse(5, 7) << endl;
}