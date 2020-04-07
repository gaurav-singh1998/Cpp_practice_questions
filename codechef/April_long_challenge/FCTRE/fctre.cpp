//Giving TLE//
#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;

vector<vector<ll>> graph(100000, vector<ll>(100000));
typedef pair<ll, ll> node;

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

int main()
{
    ll T;
    cin >> T;
    node n;
    vector<ll>costs;
    ll cost;
    node query;
    while(T--)
    {
        ll N;
        cin >> N;
        vector<node> nodes(N);
        nodes.clear();
        costs.clear();
        for(ll i=1; i<=N-1; i++)
        {
            cin >> n.first >> n.second;
            nodes.push_back(n);
        }
        for(ll i=1; i<=N; i++)
        {
            cin >> cost;
            graph[i][i]=cost;
            costs.push_back(cost);
        }
        for(node n: nodes)
        {
            graph[n.first][n.second]=costs[n.second - 1];
        }
        //cout << endl << endl;
        //for(ll i=1; i<=N; i++)
        //{
        //    for(ll j=1; j<=N; j++)
        //    {
        //        cout << graph[i][j] << " ";
        //    }
        //    cout << endl;
        //}
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
            query.first=queries[i].first; query.second=queries[i].second;
            if(query.first == query.second)
            {
                noFactorized *= graph[query.first][query.first];
            }
            else
            {
                noFactorized*=graph[query.first][query.first];
                noFactorized*=graph[query.second][query.second];
                if(graph[query.first][query.second] == 0 )
                {
                    while(graph[query.first][query.second] == 0)
                    {
                        query.first+=1;
                    }
                    noFactorized*=graph[query.first][query.first];
                }
            }
            cout << noofFactors(noFactorized) << '\n';
        }
    }
}