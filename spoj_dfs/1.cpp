#include<bits/stdc++.h>
using namespace std;
int N, M;
class Graph
{
    public:
    map<int, list<int>> adjList;
    void addEdge(int u, int v)
    {
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    void dfshelper(int src, map<int, bool>&visited)
    {
        visited[src]=true;
        for(auto neighbour: adjList[src])
        {
            if(!visited[neighbour])
            {
                dfshelper(neighbour, visited);
            }
        }
    }
    void dfs()
    {
        int components=0;
        int count=0;
        map<int, bool> visited;
        for(auto i: adjList)
        {
            if(!visited[i.first])
            {
                dfshelper(i.first, visited);
                components++;
            }
        }
        for(auto i: adjList)
        {
            count += adjList[i.first].size();
        }
        //cout << components << "  " << count << 
        if(components==1 && count/2==N-1) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
};

int main()
{
    Graph g;
    cin >> N >> M;
    for(int i=0; i<M; i++)
    {
        int u, v; cin >> u >> v;
        g.addEdge(u, v);
    }
    g.dfs();
}