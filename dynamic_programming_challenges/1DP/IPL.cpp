#include<bits/stdc++.h>
#define ll long long int
using namespace std;

ll IPL(ll* costs, ll N)
{
    ll *dp=new ll[N+1]{0};
    ll ans=0;
    dp[1]=costs[1];
    dp[2]=costs[2];
    dp[3]=costs[3];
    for(ll i=4; i<=N; i++)
    {
        dp[i]=min(dp[i-1], min(dp[i-2], dp[i-3]))+costs[i];
    }
    for(ll i=1; i<=N; i++)
    {
        ans+=costs[i];
    }
    return ans-min(dp[N], min(dp[N-1], dp[N-2]));

}

int main()
{
    ll N;
    cin >> N;
    ll costs[N+1];
    for(ll i=1; i<=N; i++)
    {
        cin >> costs[i];
    }
    cout << IPL(costs, N) << endl;
    return 0;
}