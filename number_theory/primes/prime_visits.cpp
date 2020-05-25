//https://www.hackerrank.com/contests/launchpad-1-winter-challenge/challenges/prime-visits
#include<bits/stdc++.h>
using namespace std;
#define num 1000005

int isPrime[num];

void Seive()
{
    for(int i=3; i<=10000; i+=2)
    {
        isPrime[i]=true;
    }

    for(int i=3; i<=10000; i+=2)
    {
        if(isPrime[i])
        {
            for(int j=i*i; j<=10000; j+=i)
            {
                isPrime[j]=false;
            }
        }
    }

    isPrime[2]=1;
    isPrime[0]=isPrime[1]=0;
}


int main()
{
    Seive();
    int csum[num];
    for(int i=1; i<=10000; i++)
    {
        csum[i]=csum[i-1]+isPrime[i];
    }

    int t; cin >> t;
    while(t--)
    {
        int l, r; cin >> l >> r;
        cout << csum[r]-csum[l-1] << endl;
    }
}