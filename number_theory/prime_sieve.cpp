#include<bits/stdc++.h>
#define ll long long
using namespace std;

void prime_sieve(int *p)
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
}

int main()
{
    int n;
    cin >> n;
    int p[1000005] = {0};
    prime_sieve(p);

    for(int i=0; i<=n; i++)
    {
        if(p[i]==1)
        {
            cout << i << " = prime" << endl;
        }
    }
}