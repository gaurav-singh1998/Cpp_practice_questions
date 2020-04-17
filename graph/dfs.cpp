#include<bits/stdc++.h>
using namespace std;


template<typename T>
class Graph
{
    map<T, list<T>>adjList;
    public:
    void addEdge(T u, T v, bool bidir)
    {
        adjList[u].push_back(v);
        if(bidir)
        {
            adjList[v].push_back(u);
        }
    }

    void print()
    {
        for(auto i: adjList)
        {
            cout << i.first << "-->";
            for(auto neighbour: i.second)
            {
                cout << neighbour << ", ";
            }
        }
    }

    void dfsHelper(T node, map<T, bool> &visited)
    {
        visited[node] = true;
        cout << node << " ";

        //try to find neighbour of current node which is not yet visited
        for(auto neighbour: adjList[node])
        {
            if(!visited[neighbour])
            {
                dfsHelper(neighbour, visited);
            }
        }
    }

    void dfs(T src)
    {
        map<T, bool> visited;
        dfsHelper(src, visited);
    }
};

int main()
{
    Graph<int> g;
    g.addEdge(1, 2, true);
    g.addEdge(2, 6, true);
    g.addEdge(2, 7, true);
    g.addEdge(2, 3, true);
    g.addEdge(3, 8, true);
    g.addEdge(3, 9, true);
    g.addEdge(3, 4, true);
    g.addEdge(4, 10, true);
    g.addEdge(4, 11, true);
    g.addEdge(4, 5, true);
    g.print();
    cout << endl << endl;
    g.dfs(1);
    cout << endl;
}