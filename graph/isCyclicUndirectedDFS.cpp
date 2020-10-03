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

    bool cyclicHelper(int node, map<int, bool>& visited, int parent)
    {
        visited[node]=true;
        for(auto elem: adjList[node])
        {
            if(!visited[elem])
            {
                bool isValid = cyclicHelper(elem, visited, node);
                if(isValid)
                {
                    return true;
                }
            }
            else if(elem != parent)
            {
                return true;
            }
            
        }
        return false;
    }


    bool isCyclic()
    {
        map<int, bool> visited;
        return cyclicHelper(0, visited, -1);
    }
};

int main()
{
    Graph g;
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 0);
    cout << g.isCyclic() << endl;
}