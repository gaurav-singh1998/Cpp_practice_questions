#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;

ll func(ll a, ll b)
{
    ll res=1;
    while(b>0)
    {
        if(b&1){
            res = (res*a)%mod;
        }
        a = (a*a)%mod;
        b=b>>1;
    }
    return res;
}

int main()
{
    ll n;
    cin >> n;
    cout << func(n, mod-2) << endl;
}