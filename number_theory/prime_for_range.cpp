#include<bits/stdc++.h>
#define ll long long
using namespace std;

void prime_sieve(int *p)
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
                p[j]=0;
            }
        }
    }
    p[2]=1;
    p[1]=p[0]=0;
}

int main()
{
    int *p = new int[1000000]{0};
    prime_sieve(p);
    int *csum = new int[1000000]{0};
    for(ll i=1; i<=1000000; i++)
    {
        csum[i] = csum[i-1] + p[i];
    }
    int a, b; cin >> a >> b;
    cout << csum[b]-csum[a] << endl;
}