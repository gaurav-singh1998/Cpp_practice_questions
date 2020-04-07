//Giving TLE//
#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;

ll noofFactors(ll n)
{
    ll ans=0;
    for(ll i=1; i*i<=n; i++)
    {
        if(n%i == 0) ans += 2;
        if(n/i == i) ans -= 1;
    }
    return ans%mod;
}
//multimap<ll, ll> paths;

int main()
{
    ll T;
    cin >> T;
    while(T--)
    {
        ll N, first, second;
        cin >> N;
        vector<pair<ll, ll>>path;

        for(ll i=0; i<N-1; i++)
        {
            cin >> first >> second;
            //paths.insert({first, second});
            path.push_back(make_pair(first, second));
        }
        //for(auto it: paths) cout << it.first << " " << it.second << endl;
        vector<ll> costs(N);
        costs.clear();
        for(ll i=0; i<N; i++)
        {
            ll cost;
            cin >> cost;
            costs.push_back(cost);
        }
        ll Q;
        cin >> Q;
        ll noFactorized=1;
        vector<pair<ll, ll>> queries;
        for(ll i=0; i<Q; i++)
        {
            ll j, k;
            cin >> j >> k;
            queries.push_back(make_pair(j, k));
        }
        for(ll i=0; i<Q; i++)
        {
            noFactorized=1;
            pair<ll, ll> query;
            query.first = queries[i].first; query.second = queries[i].second; 
            if(query.first==query.second)
            {
                noFactorized=(noFactorized*costs[query.first-1])%mod;
            }
            else
            {
                noFactorized=(noFactorized*costs[query.first-1])%mod; noFactorized=(noFactorized*costs[query.second-1])%mod;
                while(!binary_search(path.begin(), path.end(), query))
                {
                    query.first++;
                }
                noFactorized=(noFactorized*costs[query.first-1])%mod;
            }
            cout << noofFactors(noFactorized) << '\n';
        }
    }
}