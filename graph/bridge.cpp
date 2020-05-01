#include<bits/stdc++.h>
using namespace std;

int in[1000];
int low[1000];
map<int, bool> visited;
int timer;

class Graph
{
    map<int, list<int>> adjList;

    public:
    void addEdge(int u, int v)
    {
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    void dfs(int node, int parent)
    {
        visited[node]=true;
        in[node]=low[node]=timer;
        timer++;
        for(auto children: adjList[node])
        {
            //check if parent
            if(children==parent)
            {
                continue;
            }

            //Check if back edge
            if(visited[children])
            {
                low[node]=min(low[node], in[children]);
            }
            
            else
            {
                dfs(children, node);
                if(low[children] > in[node])
                {
                    cout << node << "-" << children << " is bridge." << endl;
                }

                low[node] = min(low[node], low[children]);
            }
            
        }
    }
};

int main()
{
    Graph g;
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(2, 4);
    g.dfs(1, -1);
}