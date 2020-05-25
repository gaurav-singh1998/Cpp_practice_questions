#include<bits/stdc++.h>
using namespace std;

int x, y;
void extended_euclid_algo(int a, int b)
{
    //Base case
    if(b==0)
    {
        return;
    }

    //Recursive case
    extended_euclid_algo(b, a%b);
    int cX=y;
    int cY=x-(a/b)*y;

    x=cX;
    y=cY;
}


int main()
{
    x=1;
    y=0;
    int a, m; cin >> a >> m;
    extended_euclid_algo(a, m);
    //inverse modulo is in x;
    if(x<0)
    {
        cout << (x+m)%m << endl;
    }


    else
    {
        cout << x << endl;
    }
    
}