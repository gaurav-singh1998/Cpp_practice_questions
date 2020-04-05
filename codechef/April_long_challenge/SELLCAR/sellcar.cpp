#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;

bool compare(ll a, ll b)
{
    return a>b;
}

int main()
{
    ll T;
    cin >> T;
    //vector<ll> outputs(T);
    while(T--)
    {
        ll N, ans=0;
        cin >> N;
        vector<ll> prices(N);
        prices.clear();
        for(ll i=0; i<N; i++)
        {
            ll price;
            cin >> price;
            prices.push_back(price);
        }
        sort(prices.begin(), prices.end(), compare);
        ans+=*prices.begin();
        ll z=1;
        prices[1]--;
        for(ll i=1; i<N-1; i++)
        {
            if(prices[i] > 0) ans+=prices[i];
            else ans+=0;
            z++;
            prices[i+1]-=z;
        }
        if(prices[N-1] > 0) ans+=prices[N-1];
        else ans+=0;
        cout << (ans%mod) << endl;
    }
}