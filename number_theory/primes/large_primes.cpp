#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define n 90000000

bitset<90000000> b;
vector<ll> primes;

void seive()
{
    for(ll i=3; i<=n; i+=2)
    {
        b[i]=1;
    }

    primes.push_back(2);
    for(ll i=3; i<=n; i+=2)
    {
        if(b[i])
        {
            primes.push_back(i);
            for(ll j=i*i; j<=n; j+=i)
            {
                b[j]=0;
            }
        }
    }
}


bool check(ll num)
{
    if(num<=n)
    {
        if(b[num]==1)
        {
            return true;
        }
        return false;
    }

    for(int i=0; primes[i]*primes[i]<=n; i++)
    {
        if(n%primes[i]==0)
        {
            return false;
        }
    }
    return true;
}


int main()
{
    seive();
    ll num; cin >> num;
    cout << check(num) << endl;
}
