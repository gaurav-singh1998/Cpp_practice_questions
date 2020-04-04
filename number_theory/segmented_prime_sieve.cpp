#include<bits/stdc++.h>
#define ll long long
using namespace std;

void prime_sieve(ll *p)
{
    for(ll i=3; i<=1000000; i+=2)
    {
        p[i]=1;
    }
    for(ll i=3; i<=1000000; i+=2)
    {
        if(p[i]==1)
        {
            for(ll j=i*i; j<=1000000; j+=i)
            {
                p[j]=1;
            }
        }
    }
    p[2]=1;
    p[1]=p[0]=0;
}

void segmented_sieve(ll *pp, ll a, ll b)
{
    ll *p = new ll[1000000]{0};
    prime_sieve(p);

    for(ll i=2; i*i<=b; i++)
    {
        for(ll j=a; j<=b; j++)
        {
            if(p[i])
            {
                if(j==i) continue;
                if(j%i==0) pp[j-a]=0;
            }
        }
    }
}

int main()
{
    ll b, a;
    cin >> a >> b;
    ll *pp = new ll[b-a+1]{1};
    segmented_sieve(pp, a, b);
    int res=0;
    for(ll i=a; i<b; i++)
    {
        res+=pp[i-a];
    }
    cout << res << endl;
}