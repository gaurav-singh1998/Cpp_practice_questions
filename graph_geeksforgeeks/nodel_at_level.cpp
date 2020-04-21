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

    int BFS(int src, int level)
    {
        map<int, bool> visited;
        map<int, int> nc;
        int l=0;
        int no_nodes=0;
        nc[l]=1;
        visited[src]=true;
        queue<int> q;
        q.push(src);
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            for(auto neighbour: adjList[node])
            {
                no_nodes+=1;
                if(!visited[neighbour])
                {
                    q.push(neighbour);
                    visited[neighbour]=true;
                }
            }
            l++;
            nc[l]=no_nodes;
            no_nodes=0;
        }

        return nc[level+1];
    }
};

int main()
{
    Graph g;
    g.addEdge(0, 1); 
    g.addEdge(0, 2); 
    g.addEdge(1, 3); 
    g.addEdge(2, 4); 
    g.addEdge(2, 5);
    cout << g.BFS(0, 2) << endl;
}