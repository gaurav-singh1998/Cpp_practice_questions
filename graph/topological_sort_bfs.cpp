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

    void bfsTopologicalSort()
    {
        queue<T> q;
       // map<T, bool> visited;
        map<T, int> indegree;

        for(auto i: adjList)
        {
            T node = i.first;
         //   visited[node] = false;
            indegree[node] = 0;
        }

        //Init the indegrees of all the nodes
        for(auto i: adjList)
        {
            T u = i.first;
            for(T v: adjList[u])
            {
                indegree[v]++;
            }
        }

        //Find all the nodes with 0 indegree
        for(auto i: adjList)
        {
            T node = i.first;
            if(indegree[node] == 0)
            {
                q.push(node);
            }
        }

        //Start the algorithm
        while(!q.empty())
        {
            T node = q.front();
            q.pop();
            cout << node << "--> ";
            for(T neighbour: adjList[node])
            {
                indegree[neighbour]--;
                if(indegree[neighbour] == 0)
                {
                    q.push(neighbour);
                }
            }
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

    g.bfsTopologicalSort();
    cout << endl;
}