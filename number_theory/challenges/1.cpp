//https://online.codingblocks.com/app/player/30547/content/87834/5056/code-challenge
//Concept:- fermat's little theorem


#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007


ll getInverse(ll n)
{
    ll res=1;
    ll b=mod-2;
    while(b>0)
    {
        if(b&1)
        {
            res=(res*n)%mod;
        }
        n=(n*n)%mod;
        b=b>>1;
    }

    return res;
}


int main()
{
    ll n;
    cin >> n;
    cout << getInverse(n) << endl;
}