#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll friends_pairing(ll n)
{
    ll dp[n+1]={0};
    //Base case
    dp[1]=1;
    dp[2]=2;
    for(int i=3; i<=n; i++)
    {
        dp[i]=dp[i-1]+((i-1)*dp[i-2]);
    }
    return dp[n];
}

int main()
{
    ll t;
    cin >> t;
    while(t--)
    {
        ll n;
        cin >> n;
        cout << friends_pairing(n) << endl;
    }
}