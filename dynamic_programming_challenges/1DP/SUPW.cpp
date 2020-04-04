#include<bits/stdc++.h>
#define ll long long int
using namespace std;

ll SUPW(ll *supw, ll N)
{
    ll *dp = new ll[N+1]{0};
    dp[0]=supw[0];
    dp[1]=supw[1];
    dp[2]=supw[2];
    for(ll i=3; i<N; i++)
    {
        dp[i]=min(dp[i-1], min(dp[i-2], dp[i-3])) + supw[i];
    }
    return min(dp[N-1], min(dp[N-2], dp[N-3]));
}

int main()
{
    ll N;
    cin >> N;
    ll supw[N];
    for(ll i=0; i<N; i++)
    {
        cin >> supw[i];
    }
    cout << SUPW(supw, N) << endl;
    return 0;
}