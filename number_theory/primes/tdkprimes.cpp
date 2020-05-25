//https://www.spoj.com/problems/TDKPRIME/

#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define num 90000000

bitset<90000000> b;
vector<int> primes;

void seive()
{
    for(ll i=3; i<=num; i+=2)
    {
        b[i]=true;
    }

    primes.push_back(2);
    for(ll i=3; i<=num; i+=2)
    {
        if(b[i])
        {
            primes.push_back(i);
            for(ll j=i*i; j<=num; j+=i)
            {
                b[j]=false;
            }
        }
    }
}

int main()
{
    seive();
    int t; cin >> t;
    while(t--)
    {
        int n; cin >> n;
        cout << primes[n-1] << endl;
    }
}