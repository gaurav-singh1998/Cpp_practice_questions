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

    bool ifBipartite()
    {
        bool ans=true;
        queue<int> q;
        map<int, int> color;
        for(auto i: adjList)
        {
            color[i.first]=-1;
        }

        color[1]=0;
        q.push(1);
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            for(auto neighbour: adjList[node])
            {
                if(color[neighbour]==-1)
                {
                    color[neighbour] = 1-color[node];
                    q.push(neighbour);
                }

                else if(color[neighbour] == color[node])
                {
                    ans=false;
                    break;
                }
            }
        }
        return ans;
    }

    void dfshelper(int node, map<int, bool>& visited)
    {
        visited[node]=true;
        for(auto neighbour: adjList[node])
        {
            if(!visited[neighbour])
            {
                dfshelper(neighbour, visited);
            }
        }
    }

    int dfs()
    {
        int components=0;
        map<int, bool> visited;
        for(auto i: adjList)
        {
            if(!visited[i.first])
            {
                dfshelper(i.first, visited);
                components++;
            }
        }
        return components;
    }
};

int main()
{
    int scenario; cin >> scenario;
    Graph *g = new Graph[scenario];
    int no_vertices, no_edges; cin >> no_vertices >> no_edges;

    for(int i=0; i<scenario; i++)
    {
        for(int j=0; j<no_edges; j++)
        {
            int u, v; cin >> u >> v;
            g[i].addEdge(u, v);
        }
    }

    for(int i=0; i<scenario; i++)
    {
        if(g[i].ifBipartite() && g[i].dfs() == 1)
        {
            cout << "Scenario #" << i+1 << '\n';
            cout << "No suspicious bugs found!" << '\n';
        }
        else
        {
            cout << "Scenario #" << i+1 << '\n';
            cout << "Suspicious bugs found!" << '\n';            
        }
        
    }
}