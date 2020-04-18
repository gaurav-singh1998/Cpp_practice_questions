//https://hack.codingblocks.com/app/practice/1/144/problem

#include<bits/stdc++.h>
using namespace std;

class Graph
{
    int no_of_vertices;
    map<int, list<int>> adjList;

    public:
    Graph(int v)
    {
        no_of_vertices=v;
    }

    void addEdge(int u, int v)
    {
        adjList[u].push_back(v);
    }

    void get_children(map<int, int> &no_of_children)
    {
        for(auto i: adjList)
        {
            int node = i.first;
         //   visited[node] = false;
            no_of_children[node] = 0;
        }

        for(auto i: adjList)
        {
            int u = i.first;
            for(int v: adjList[u])
            {
                no_of_children[v]++;
            }
        }
    }

    void bfs(int src, map<int, int> &parent, map<int, bool>& visited)
    {
        queue<int> q;
        //map<i, bool> visited;
        q.push(src);
        visited[src] = true;

        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            for(auto neighbour: adjList[node])
            {
                if(!visited[neighbour])
                {
                    q.push(neighbour);
                    visited[neighbour] = true;
                    parent[neighbour]=node;
                }
            }
        }
    }
};

int main()
{
    int N, M; cin >> N >> M;
    Graph g(N);
    for(int i=0; i<M; i++)
    {
        int u, v; cin >> u >> v;
        g.addEdge(u, v);
    }
    map<int, int> parent;
    map<int, int> no_of_children;
    map<int, bool> visited;

    g.get_children(no_of_children);

    for(int i=1; i<=N; i++)
    {
        if(!visited[i])
        {
            //cout << i << endl;
            g.bfs(i, parent, visited);
        }
    }
    int ans=0;
    for(int i=1; i<=N; i++)
    {
        if((no_of_children[i] > no_of_children[parent[i]]) && (parent[i] > 0))
        {
            ans++;
        }
    }
    cout << ans << endl;
}