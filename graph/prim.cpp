#include<bits/stdc++.h>
using namespace std;

class Graph
{
    int V;
    list<pair<int, int>> *adj;

    public:
    Graph(int v)
    {
        this->V =v;
        adj = new list<pair<int, int>>[v];
    }

    void addEdge(int u, int v, int w)
    {
        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }

    int findminVertex(int *weight, bool *visited, int v)
    {
        int minVertex = -1;

        for(int i=0; i<v; i++)
        {
            if(!visited[i] && (minVertex == -1 || weight[i] < weight[minVertex]))
            {
                minVertex = i;
            }
        }

        return minVertex;
    }

    void Prim()
    {
        bool *visited = new bool[V];
        int *parent = new int[V];
        int *weight = new int[V];
        for(int i=0; i<V; i++)
        {
            visited[i] = false;
            weight[i] = INT_MAX;
        }
        parent[0] = -1;
        weight[0] = 0;

        for(int i=0; i<V; i++)
        {
            int minVertex = findminVertex(weight, visited, V);
            visited[minVertex] = true;
            for(auto neighbour: adj[minVertex])
            {
                if(!visited[neighbour.first])
                {
                    if(weight[neighbour.first] > neighbour.second)
                    {
                        parent[neighbour.first] = minVertex;
                        weight[neighbour.first] = neighbour.second;
                    }
                }
            }
        }

        for(int i=1; i<V; i++)
        {
            cout << i << "--" << parent[i] << " with weight " << weight[i] << endl;
        }
    }
};

int main()
{
    int n, e;
    cin >> n >> e;
    Graph g(n);
    for(int i=0; i<e; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        g.addEdge(u, v, w);
    }
    g.Prim();
}