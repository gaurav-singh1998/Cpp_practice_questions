#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll mod = 1000000007;

ll StringtoInt(string a, ll m)
{
    ll ans = 0;
    for(ll i=0; i<a.size(); i++)
    {
        ans = (ans*10)%m + (a[i]-'0');
        ans %= m;
    }
    return ans;
}

ll fastExponentiation(ll a, ll b)
{
    ll res=1;
    while(b>0)
    {
        if(b&1)
        {
            res = (res*a)%mod;
        }
        a = (a*a)%mod;
        b=b>>1;
    }
    return res;
}


int main()
{
    ll t;
    cin >> t;
    string a, b;
    while(t--)
    {
        cin >> a >> b;
        ll x = StringtoInt(a, mod);
        ll y = StringtoInt(b, mod-1);
        ll ans = fastExponentiation(x, y);
        cout << ans << endl;
    }
}