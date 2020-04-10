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

    void dfsHelper(T node, map<T, bool> &visited, list<T> &ordering)
    {
        visited[node]=true;

        for(auto neighbour: adjList[node])
        {
            if(!visited[neighbour])
            {
                dfsHelper(neighbour, visited, ordering);
            }
        }

        ordering.push_front(node);
    }

    void dfsTopologicalSort()
    {
        map<T, bool> visited;
        list<T> ordering;

        for(auto i: adjList)
        {
            T node = i.first;
            if(!visited[node])
            {
                dfsHelper(node, visited, ordering);
            }
        }

        for(auto element: ordering)
        {
            cout << element << "-->";
        }
    }
};

int main()
{
    Graph<string> g;
    g.addEdge("English", "PL");
    g.addEdge("Math", "PL");
    g.addEdge("PL","HTML");
    g.addEdge("PL", "Python");
    g.addEdge("PL", "Java");
    g.addEdge("PL", "JS");
    g.addEdge("Python", "Web dev");
    g.addEdge("HTML", "CSS");
    g.addEdge("CSS", "JS");
    g.addEdge("JS", "Web dev");
    g.addEdge("Java", "Web dev");
    g.addEdge("Python", "Web dev");

    g.dfsTopologicalSort();
    cout << endl;
}