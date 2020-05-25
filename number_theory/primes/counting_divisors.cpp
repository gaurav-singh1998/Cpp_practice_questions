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

ll count_divisors(ll m)
{
    ll i=0;
    ll n=primes[i];
    ll ans=1;
    while(n*n<=m)
    {
        if(m%n==0)
        {
            ll cnt=0;
            while(m%n==0)
            {
                cnt++;
                m=m/n;
            }
            ans=ans*(cnt+1);
        }
        i++;
        n=primes[i];
    }

    if(m!=1)
    {
        ans=ans*2;
    }
    return ans;
}

int main()
{
    seive();
    ll n; cin >> n;
    cout << count_divisors(n) << endl;
}