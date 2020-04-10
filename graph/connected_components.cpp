#include<bits/stdc++.h>
using namespace std;


template<typename T>
class Graph
{
    map<T, list<T>> adjList;
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
        for(auto node: adjList)
        {
            cout << node.first << "--> ";
            for(auto neighbours: node.second)
            {
                cout << neighbours << ", ";
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
        int components =1;
        dfsHelper(src, visited);
        cout << endl;

        for(auto i: adjList)
        {
            T city = i.first;
            if(!visited[city])
            {
                dfsHelper(city, visited);
                components++;
            }
        }

        
        cout << "The current graph had " << components << " components." << endl;
    }
};


int main()
{
    Graph<string> g;
    g.addEdge("Amritsar", "Jaipur");
    g.addEdge("Amritsar", "Delhi");
    g.addEdge("Delhi", "Jaipur");
    g.addEdge("Mumbai", "Jaipur");
    g.addEdge("Mumbai", "Bhopal");
    g.addEdge("Delhi", "Bhopal");
    g.addEdge("Agra", "Delhi");
    g.addEdge("Andaman", "Nicobar");

    g.dfs("Amritsar");
    cout << endl;
}