#include<bits/stdc++.h>
using namespace std;

class Graph
{
    private:
    int V;
    list<int> *l;

    public:
    Graph(int v)
    {
        V = v;

        //Array of linked list to store the adjacency list.
        l = new list<int>[V];
    }

    void AddEdge(int u, int v, bool bidir=true)
    {
        l[u].push_back(v);
        if(bidir)
        {
            l[v].push_back(u);
        }
    }

    void printAdjList()
    {
        for(int i=0; i<V; i++)
        {
            cout << i << "-->";
            for(int vertex: l[i])
            {
                cout << vertex << ", ";
            }
            cout << endl;
        }
    }
};

int main()
{
    Graph g(5);
    g.AddEdge(1, 2, false);
    g.AddEdge(1, 3, false);
    g.AddEdge(2, 4, false);
    g.AddEdge(2, 5, false);

    g.printAdjList();
}