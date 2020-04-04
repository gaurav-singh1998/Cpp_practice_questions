#include<bits/stdc++.h>
using namespace std;

int x, y, GCD;
void ExtendedGCD(int a, int b)
{
    if(b==0)
    {GCD=a;
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