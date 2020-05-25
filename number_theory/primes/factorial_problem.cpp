//find minimium value of x such that n!%pow(k, x)==0
//Very important.
#include<bits/stdc++.h>
#define ll long long
using namespace std;




int main()
{
    ll T; cin >> T;
    while(T--)
    {
        ll n, k; cin >> n >> k;
        ll ans=LONG_MAX;
        for(ll i=2; i*i<=k; i++)
        {
            if(k%i==0)
            {
                ll cnt=0;
                while(k%i==0)
                {
                    cnt++;
                    k=k/i;
                }

                ll p=i;
                ll occ=0;
                while(p<=n)
                {
                    occ+=n/p;
                    p*=i;
                }

                ans=min(ans, occ/cnt);
            }
        }

        if(k!=1)
        {
            ll p=k;
            ll occ=0;
            while(p<=n)
            {
                occ+=n/p;
                p*=k;
            }

            ans=min(ans, occ);
        }

        if(ans==LONG_MAX)
        {
            cout << 0 << endl;
        }

        cout << ans << endl;
    }
}