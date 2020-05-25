//https://online.codingblocks.com/app/player/30547/content/87834/5054/code-challenge
//Concept:-Modular properties

#include<bits/stdc++.h>
using namespace std;
#define ll long long


ll stringtonum(string num, ll n)
{
    ll st=num[0]-'\0'-48;
    ll mod;
    for(ll i=1; i<num.length(); i++)
    {
        mod=st%n;
        ll mul=mod*10;
        st=num[i]-'\0'-48;
        st=st+mul;
    }
    return st%n;
}

int main()
{
    ll n; string m; cin >> n >> m;
    ll num=stringtonum(m, n);
    cout << __gcd(n, num) << endl;
}