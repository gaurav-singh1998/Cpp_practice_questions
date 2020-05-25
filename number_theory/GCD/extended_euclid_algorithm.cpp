//Proof is important
#include<bits/stdc++.h>
using namespace std;


int x, y, GCD;

void extended_euclid(int a, int b)
{
    //Base case
    if(b==0)
    {
        GCD=a;
        x=1;
        y=0;
        return;
    }

    //Recursive case
    extended_euclid(b, a%b);
    int cX=y;
    int cY=x-(a/b)*y;

    x=cX;
    y=cY;
}

int main()
{
    extended_euclid(18, 30);
    cout << x << " " << y << endl;
}