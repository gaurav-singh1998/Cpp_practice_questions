//Giving TLE
#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;

ll graph[1000][1000];
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
        ll noFactorized;
        vector<ll>ans(Q);
        ans.clear();
        while(Q--)
        {
            noFactorized=1;
            cin >> query.first >> query.second;
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
            ans.push_back(noofFactors(noFactorized));
        }
        for(ll a: ans) cout << a << "\n";
    }
}