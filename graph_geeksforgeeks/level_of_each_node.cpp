//https://www.geeksforgeeks.org/level-node-tree-source-node-using-bfs/
/**
find the level of each node from the source node
**/

#include<bits/stdc++.h>
using namespace std;

class Graph
{
    int V;
    map<int, list<int>> adjList;

    public:
    void addEdge(int u, int v)
    {
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    map<int, int> bfs()
    {
        queue<int> q;
        q.push(0);
        map<int, bool> visited;
        visited[0]=true;

        map<int, int> level_of_node;
        level_of_node[0]=0;

        while(!q.empty())
        {
            int node = q.front();
            q.pop();

            for(auto neighbour: adjList[node])
            {
                if(!visited[neighbour])
                {
                    q.push(neighbour);
                    level_of_node[neighbour] = level_of_node[node]+1;
                    visited[neighbour]=true;
                }
            }
        }

        return level_of_node;
    }
};

int main()
{
    Graph g;
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(1, 5);
    g.addEdge(2, 5);
    g.addEdge(2, 6);
    g.addEdge(6, 7);
    map<int, int> level_of_node=g.bfs();
    for(auto i: level_of_node)
    {
        cout << "Node: " << i.first << "  Level: " << i.second << endl;
    }
}