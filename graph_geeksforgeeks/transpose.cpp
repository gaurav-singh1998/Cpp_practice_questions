//https://www.geeksforgeeks.org/transpose-graph/

#include<bits/stdc++.h>
using namespace std;

class Graph
{
    map<int, list<int>> adjList;
    map<int, list<int>> adjListTranspose;

    public:
    void addEdge(int u, int v)
    {
        adjList[u].push_back(v);
    }

    void dfshelper(int node, map<int, bool>& visited)
    {
        visited[node]=true;
        for(auto neighbour: adjList[node])
        {
            adjListTranspose[neighbour].push_back(node);
        }
        for(auto neighbour: adjList[node])
        {
            if(!visited[neighbour])
            {
                dfshelper(neighbour, visited);
            }
        }
    }

    void dfs()
    {
        map<int, bool> visited;
        for(auto i: adjList)
        {
            if(!visited[i.first])
            {
                dfshelper(i.first, visited);
            }
        }
    }

    void printTranspose()
    {
        for(auto i: adjListTranspose)
        {
            cout << i.first << "--> ";
            for(auto neighbour: adjListTranspose[i.first])
            {
                cout << neighbour << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    Graph g;
    g.addEdge(3, 1);
    g.addEdge(1, 2);
    g.addEdge(1, 5);
    g.addEdge(1, 4);
    g.addEdge(5, 2);
    g.addEdge(5, 4);
    g.addEdge(4, 3);
    g.dfs();
    g.printTranspose();
}