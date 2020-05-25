//https://codeforces.com/problemset/problem/26/A

#include<bits/stdc++.h>
using namespace std;


int seive(int n)
{
    int primes[n+1];
    memset(primes, 0, sizeof(primes));
    for(int i=2; i<=n; i++)
    {
        if(!primes[i])
        {
            for(int j=i; j<=n; j+=i)
            {
                primes[j]++;
            }
        }
    }

    int ans=0;
    for(int i=2; i<=n; i++)
    {
        if(primes[i]==2)
        {
            ans+=1;
        }
    }
    return ans;
}

int main()
{
    int num; cin >> num;
    cout << seive(num) << endl;
}