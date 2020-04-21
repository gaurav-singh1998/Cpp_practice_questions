//https://www.geeksforgeeks.org/transitive-closure-of-a-graph-using-dfs/

/**
Given a directed graph, find out if a vertex v is reachable from
another vertex u for all vertex pairs (u, v) in the given graph. Here reachable mean
that there is a path from vertex u to v. The reach-ability matrix is called transitive closure of a graph.
**/

#include<bits/stdc++.h>
using namespace std;

class Graph
{
    int V;
    map<int, list<int>> adjList;
    bool **tc;
    public:
    Graph(int V)
    {
        this->V=V;
        tc = new bool*[V];
        for(int i=0; i<this->V; i++)
        {
            tc[i] = new bool[this->V];
            memset(tc[i], false, V*sizeof(bool));
        }
    }

    void addEdge(int u, int v, bool bidir)
    {
        adjList[u].push_back(v);
        if(bidir)
        {
            adjList[v].push_back(u);
        }
    }

    void DFS(int src, int dest)
    {
        tc[src][dest]=true;
        for(auto neighbour: adjList[dest])
        {
            if(tc[src][neighbour]==false)
            {
                DFS(src, neighbour);
            }
        }
    }

    void transitive_closure()
    {
        for(int i=0; i<V; i++)
        {
            DFS(i, i);
        }

        for(int i=0; i<V; i++)
        {
            for(int j=0; j<V; j++)
            {
                cout << tc[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    Graph g(4);
    g.addEdge(0, 2, true);
    g.addEdge(0, 1, false);
    g.addEdge(1, 2, false);
    g.addEdge(2, 3, false);

    g.transitive_closure();
}