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

vector<ll> factorize(ll m)
{
    ll i=0;
    ll n=primes[i];
    vector<ll> factors;
    while(n*n<=m)
    {
        if(m%n==0)
        {
            factors.push_back(n);
            while(m%n==0)
            {
                m=m/n;
            }
        }
        i++;
        n=primes[i];
    }

    if(m!=1)
    {
        factors.push_back(m);
    }

    return factors;
}

int main()
{
    seive();
    ll no; cin >> no;
    vector<ll> factors=factorize(no);
    for(auto nums: factors)
    {
        cout << nums << endl;
    }
}