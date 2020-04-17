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

    int bfs1()
    {
        queue<int> q;
        map<int, int> dist;
        for(auto i: adjList)
        {
            dist[i.first]=INT_MAX;
        }
        q.push(1);
        dist[1]=0;
        int node;
        while(!q.empty())
        {
            node = q.front();
            q.pop();
            for(auto neighbour: adjList[node])
            {
                if(dist[neighbour]==INT_MAX)
                {
                    q.push(neighbour);
                    dist[neighbour] = dist[node] + 1;
                }
            }
        }
        return node;
    }

    int bfs2()
    {
        int max_dist=0;
        int node = bfs1();
        queue<int> q;
        map<int, int> dist;
        for(auto i: adjList)
        {
            dist[i.first]=INT_MAX;
        }
        q.push(node);
        dist[node]=0;
        while(!q.empty())
        {
            node = q.front();
            q.pop();
            for(auto neighbour: adjList[node])
            {
                if(dist[neighbour]==INT_MAX)
                {
                    q.push(neighbour);
                    dist[neighbour] = dist[node] + 1;
                    max_dist = max(max_dist, dist[neighbour]);
                }
            }
        }
        return max_dist;
    }
};

int main()
{
    int N;
    cin >> N;
    Graph g;
    for(int i=0; i<N-1; i++)
    {
        int u, v; cin >> u >> v;
        g.addEdge(u, v);
    }
    cout << g.bfs2() << endl;
}