//https://online.codingblocks.com/app/player/30547/content/87834/5057/code-challenge
//concept:-Sieve

#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define num 5000005

bitset<num> isPrime;
vector<ll> primes;

void sieve()
{
    for(ll i=3; i<=num; i+=2)
    {
        isPrime[i]=1;
    }

    primes.push_back(2);

    for(ll i=3; i<=num; i+=2)
    {
        if(isPrime[i])
        {
            primes.push_back(i);
            for(ll j=i*i; j<=num; j+=i)
            {
                isPrime[j]=0;
            }
        }
    }
}


int main()
{
    sieve();
    ll n; cin >> n;
    cout << primes[n-1] << endl;
}