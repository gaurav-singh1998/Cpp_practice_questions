//https://online.codingblocks.com/app/player/30547/content/87834/5070/code-challenge
//Concept:- modular properties

#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;


ll factorial(ll num)
{
    //Base case
    if(num==0)
    {
        return 1;
    }

    //Recursive case
    return (num%mod)*(factorial(num-1)%mod);
}

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
    ll c, r; cin >> c >> r;
    ll c_fact=factorial(c);
    ll r_fact=factorial(r);
    ll nr_fact=factorial(c-r);

    ll r_fact_inv=getInverse(r_fact);
    ll nr_fact_inv=getInverse(nr_fact);

    cout << (c_fact*r_fact_inv*nr_fact_inv)%mod << endl;
}