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

    //Check for undirected graph.
    bool isCyclicBFS(T src)
    {
        map<T, bool>visited;
        map<T, T>parent;
        queue<T> q;

        q.push(src);
        visited[src]=true;
        parent[src]=src;

        while(!q.empty())
        {
            T node = q.front();
            q.pop();

            //Iterate over the neighbours leaving parent.
            for(auto neighbour: adjList[node])
            {
                if(visited[neighbour]==true && parent[node]!=neighbour)
                {
                    return true;
                }

                else if(!visited[neighbour])
                {
                    visited[neighbour]=true;
                    parent[neighbour]=node;
                    q.push(neighbour);
                }
            }
        }
        return false;
    }
};

int main()
{
    Graph<int> g;
    g.addEdge(1, 2);
    g.addEdge(1, 4);
    g.addEdge(4, 3);
    g.addEdge(2, 3);

    cout << g.isCyclicBFS(1) << endl;
}