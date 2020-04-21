//https://www.geeksforgeeks.org/find-a-mother-vertex-in-a-graph/

/**
Case 1:- Undirected Connected Graph : In this case, all the vertices are 
mother vertices as we can reach to all the other nodes in the graph.
Case 2:- Undirected/Directed Disconnected Graph : In this case, there is no mother vertices as 
we cannot reach to all the other nodes in the graph.
Case 3:- Directed Connected Graph : In this case, we have to find a vertex -v in the 
graph such that we can reach to all the other nodes in the graph through a directed path.
**/

#include<bits/stdc++.h>
using namespace std;

class Graph
{
    int V;
    map<int, list<int>> adjList;

    public:
    Graph(int V)
    {
        this->V = V;
    }

    void addEdge(int u, int v, bool bidir=false)
    {
        adjList[u].push_back(v);
        if(bidir)
        {
            adjList[v].push_back(u);
        }
    }

    void DFS(int src, vector<bool>& visited)
    {
        visited[src]=true;
        for(auto neighbour: adjList[src])
        {
            if(!visited[neighbour])
            {
                DFS(neighbour, visited);
            }
        }
    }

    int findMother()
    {
        vector<bool> visited(V, false);

        int v=0;
        for(int i=0; i<V; i++)
        {
            if(!visited[i])
            {
                DFS(i, visited);
                v=i;
            }
        }

        fill(visited.begin(), visited.end(), false);
        DFS(v, visited);
        if(find(visited.begin(), visited.end(), false) == visited.end()) return v;
        else return -1;
    }
};

int main()
{
    Graph g(7); 
    g.addEdge(0, 1); 
    g.addEdge(0, 2); 
    g.addEdge(1, 3); 
    g.addEdge(4, 1); 
    g.addEdge(6, 4); 
    g.addEdge(5, 6); 
    g.addEdge(5, 2); 
    g.addEdge(6, 0); 

    cout << "A mother vertex is " << g.findMother() << endl;  

}