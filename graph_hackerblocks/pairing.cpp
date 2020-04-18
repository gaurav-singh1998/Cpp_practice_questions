#include<bits/stdc++.h>
#define ll long long
using namespace std;

class Graph
{
    ll v;
    map<ll, list<ll>> adjList;

    public:
    Graph(ll v)
    {
        this->v=v;
    }

    void addEdge(ll u, ll v)
    {
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    void dfshelper(int node, map<ll, bool> &visited, ll& no_nodes)
    {
        visited[node] = true;
        no_nodes++;

        //try to find neighbour of current node which is not yet visited
        for(auto neighbour: adjList[node])
        {
            if(!visited[neighbour])
            {
                dfshelper(neighbour, visited, no_nodes);
            }
        }
    }

    void dfs()
    {
        map<ll, bool> visited;
        ll ans=0;
        for(auto i: adjList)
        {
            int city = i.first;
            if(!visited[city])
            {
                ll no_nodes=0;
                dfshelper(city, visited, no_nodes);
                ans+=(no_nodes*(v-no_nodes));
                v-=no_nodes;
            }
        }
        
        cout << ans << endl;
    }
};

int main()
{
    ll N, M; cin >> N >> M;
    Graph g(N);
    for(ll i=0; i<M; i++)
    {
        ll u, v; cin >> u >> v;
        g.addEdge(u, v);
    }
    g.dfs();
}