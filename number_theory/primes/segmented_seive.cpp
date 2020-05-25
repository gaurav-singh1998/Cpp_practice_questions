//https://www.spoj.com/problems/PRIME1/

#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define num 100000

bitset<num> b;
vector<ll> primes;

void seive()
{
    for(ll i=3; i<=num; i+=2)
    {
        b[i]=1;
    }

    primes.push_back(2);
    for(ll i=3; i<=num; i+=2)
    {
        if(b[i])
        {
            primes.push_back(i);
            for(ll j=i*i; j<=num; j+=i)
            {
                b[j]=0;
            }
        }
    }
}

int main()
{
    seive();
    ll t; cin >> t;
    while(t--)
    {
        ll n, m; cin >> m >> n;
        ll *segmented=new ll[n-m+1]{0};
        for(auto x: primes)
        {
            if(x*x>n)
            {
                break;
            }

            ll start=(m/x)*x;
            
            if(x>=m && x<=n)
            {
                start=2*x;
            }

            for(ll i=start; i<=n; i+=x)
            {
                segmented[i-m]=1;
            }
        }

        for(ll i=m; i<=n; i++)
        {
            if(!segmented[i-m] && i!=1)
            {
                cout << i << endl;
            }
        }
        cout << endl;
    }
}