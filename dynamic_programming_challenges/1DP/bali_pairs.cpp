#include<bits/stdc++.h>
#define ll long long int
using namespace std;


class shoes
{
    public:
    ll lt;
    ll rt;
    shoes(){
        lt=0;
        rt=0;
    }
    shoes(ll l, ll r)
    {
        lt=l;
        rt=r;
    }
};

shoes s[1000000];
ll dp[1000000];
ll n;

ll solveit(ll i, ll sum)
{
    if(i==n)
    {
        if(sum%2)return 1;
        else return 0;
    }
    else if(dp[i]!=-1) return dp[i];
    //base case
    ll ans=0;
    ans+=(solveit(i+1, sum+s[i].lt) + solveit(i+1, sum+s[i].rt));
    return dp[i]=ans%1000000007;
}

int main()
{
    memset(dp, -1, sizeof(dp));
    cin >> n;
    for(ll i=0; i<n; i++)
    {
        ll l,r;
        cin >> l >> r;
        s[i].lt=l;
        s[i].rt=r;
    }
    cout << solveit(0, 0) << endl;
}