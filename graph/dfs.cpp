#include<bits/stdc++.h>
using namespace std;


template<typename T>
class Graph
{
    map<T, list<T>>adjList;
    public:
    void addEdge(T u, T v, bool bidir=false)
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
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(2, 4);
    g.addEdge(4, 5);
    g.addEdge(1, 6);
    g.addEdge(6, 7);
    g.addEdge(6, 8);
    g.addEdge(8, 9);
    g.addEdge(9, 10);
    g.addEdge(7, 11);
    g.addEdge(7, 12);
    g.addEdge(11, 13);

    g.print();
    cout << endl << endl;
    g.dfs(1);
    cout << endl;
}