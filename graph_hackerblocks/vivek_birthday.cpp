//https://hack.codingblocks.com/app/practice/1/547/problem
#include<bits/stdc++.h>
using namespace std;
int N, D; 
int nodes;

class Graph
{
    map<int, list<int>> adjList;

    public:
    void addEdge(int u, int v)
    {
        adjList[u].push_back(v);
    }

    void dfsHelper(int node, map<int, bool> &visited)
    {
        visited[node] = true;
        nodes++;

        for(auto neighbour: adjList[node])
        {
            if(!visited[neighbour])
            {
                dfsHelper(neighbour, visited);
            }
        }
    }

    void dfs(int src)
    {
        map<int, bool> visited;
        dfsHelper(src, visited);
    }
};

int main()
{
    cin >> N >> D;
    Graph g;
    for(int i=0; i<D; i++)
    {
        int u, v; cin >> u >> v;
        g.addEdge(u, v);
    }
    int ans=INT_MAX;
    for(int i=1; i<=N; i++)
    {
        g.dfs(i);
        ans = min(nodes, ans);
        nodes=0;
    }
    cout << ans << endl;
}