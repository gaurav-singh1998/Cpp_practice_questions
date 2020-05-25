//https://online.codingblocks.com/app/player/30547/content/87834/5076/code-challenge
//modular properties
#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll fast_exponentiation(ll a, ll b, ll c)
{
    ll res=1;
    while(b>0)
    {
        if(b&1)
        {
            res=(a*res)%c;
        }
        a=(a*a)%c;
        b=b>>1;
    }
    return res;
}


int main()
{
    ll a, b, c; cin >> a >> b >> c;
    cout << fast_exponentiation(a, b, c) << endl;
}