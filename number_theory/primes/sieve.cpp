#include<bits/stdc++.h>
using namespace std;

bool isPrime[9000];
vector<int> primes;


void Sieve()
{
    int maxN=9000;
    for(int i=3; i<=maxN; i+=2)
    {
        isPrime[i]=true;
    }

    for(int i=3; i<=maxN; i+=2)
    {
        if(isPrime[i])
        {
            for(int j=i*i; j<=maxN; j+=i)
            {
                isPrime[j]=false;
            }
        }
    }
    primes.push_back(2);
    for(int i=3; i<=maxN; i+=2)
    {
        if(isPrime[i])
        {
            primes.push_back(i);
        }
    }
}

int main()
{
    int t; cin >> t;
    Sieve();

    while(t--)
    {
        int n; cin >> n;
        cout << primes[n-1] << endl;
    }
}