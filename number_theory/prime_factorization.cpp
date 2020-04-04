#include<bits/stdc++.h>
#define ll long long
using namespace std;

vector<int> prime_sieve(int *p, int n)
{
    //marking all primes as odd number.
    for(int i=3; i<=1000000; i+=2)
    {
        p[i]=1;
    }
    //Start the seive.
    for(ll i=3; i<=1000000; i+=2)
    {
        if(p[i]==1)
        {
            for(ll j = i*i; j<=1000000; j+=i)
            {
                p[j] = 0;
            }
        }
    }

    p[2]=1;
    p[1]=p[0]=0;

    vector<int> primes;
    primes.push_back(2);

    for(int i=3; i<=n; i+=2)
    {
        if(p[i]==1) primes.push_back(i);
    }
    return primes;
}

vector<int> prime_factorization(vector<int> primes, int n)
{
    vector<int> factors;
    int i=0;
    int p =primes[0];

    while(p*p <= n)
    {
        if(n%p == 0)
        {
            factors.push_back(p);
        }
        while(n%p == 0)
        {
            n = n/p;
        }
        i++;
        p=primes[i];
    }

    if(n != 1)
    {
        factors.push_back(n);
    }
    return factors;
}


int main()
{
    int n;
    int *p=new int[1000000]{0};
    cin >> n;
    vector<int> primes = prime_sieve(p, n);
    for(int i: primes) cout << i << endl;
    cout << endl;
    cout << endl;
    vector<int>factors = prime_factorization(primes, n);
    for(int i: factors) cout << i << endl;
}