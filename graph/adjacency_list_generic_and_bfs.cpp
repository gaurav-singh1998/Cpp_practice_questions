#include<bits/stdc++.h>
using namespace std;

template<typename T>
class Graph
{
    map<T, list<T>> adjList;

    public:
    void addEdge(T u, T v, bool bidir=true)
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
            for(auto entry: i.second)
            {
                cout << entry << ", ";
            }
            cout << endl;
        }
    }

    void bfs(T src)
    {
        queue<T> q;
        map<T, bool> visited;
        q.push(src);
        visited[src] = true;

        while(!q.empty())
        {
            T node = q.front();
            cout << node << " ";
            q.pop();
            //For the neighbours of the current node, find out the nodes which are not visited.
            for(auto neighbour: adjList[node])
            {
                if(!visited[neighbour])
                {
                    q.push(neighbour);
                    visited[neighbour] = true;
                }
            }
        }
        cout << endl;
    }

    void sssp(T src)
    {
        queue<T> q;
        map<T, int> dist;
        map<T, T> parent;

        for(auto i: adjList)
        {
            dist[i.first] = INT_MAX;
        }

        q.push(src);
        dist[src] = 0;
        //parent[src] = src;

        while(!q.empty())
        {
            T node = q.front();
            cout << node << " ";
            q.pop();


            for(auto neighbour: adjList[node])
            {
                if(dist[neighbour]==INT_MAX)
                {
                    q.push(neighbour);
                    dist[neighbour] =dist[node] + 1;
                    //parent[neighbour] = node;
                }
            }
        }

        //Print the distances to all the nodes
        for(auto i: adjList)
        {
            T node = i.first;
            cout << "Dist of " << node << " from " << src << " is " << dist[node] << endl;
        }
    }
};

int main()
{
    Graph<string> s;
    s.addEdge("putin", "trump", true);
    s.addEdge("Modi", "putin", false);

    s.print();

    cout << endl << endl;
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
    g.bfs(1);
    cout << endl << endl;
    g.sssp(1);
}