#include<bits/stdc++.h>
using namespace std;

class Graph
{
    map<int, list<int>> adjList;

    public:
    void addEdge(int u, int v)
    {
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    void dfshelper(int node, map<int, bool>& visited)
    {
        visited[node]=true;
        for(auto neighbour: adjList[node])
        {
            if(!visited[neighbour])
            {
                dfshelper(neighbour, visited);
            }
        }
    }

    int count_trees()
    {
        map<int, bool> visited;
        int components=0;
        for(auto i: adjList)
        {
            if(!visited[i.first])
            {
                dfshelper(i.first, visited);
                components++;
            }
        }
        return components;
    }
};

int main()
{
    Graph g;
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(3, 4);
    cout << g.count_trees() << endl;
}