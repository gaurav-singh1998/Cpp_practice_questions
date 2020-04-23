//https://www.geeksforgeeks.org/count-possible-paths-two-vertices/

//Example of backtracking
/**
Count the total number of ways or paths that exist between
two vertices in a directed graph. These paths doesn’t contain a cycle,
the simple enough reason is that a cylce contain infinite number of 
paths and hence they create problem.
**/


#include<bits/stdc++.h>
using namespace std;

class Graph
{
    map<int, list<int>> adjList;

    public:
    void addEdge(int u, int v, bool bidir=false)
    {
        adjList[u].push_back(v);
        if(bidir)
        {
            adjList[v].push_back(u);
        }
    }

    void dfshelper(int u, int v, map<int, bool>&visited, int& pathCount)
    {
        //Base case
        visited[u]=true;
        if(u==v) pathCount++;

        //Recursive case
        for(auto neighbour: adjList[u])
        {
            if(!visited[neighbour])
            {
                dfshelper(neighbour, v, visited, pathCount);
            }
        }
        visited[u]=false;
    }

    int DFS(int u, int v)
    {
        map<int, bool> visited;
        int pathCount=0;
        dfshelper(u, v, visited, pathCount);
        return pathCount;
    }
};

int main()
{
    Graph g;
    g.addEdge(0, 1); 
    g.addEdge(0, 2); 
    g.addEdge(0, 3); 
    g.addEdge(2, 0); 
    g.addEdge(2, 1); 
    g.addEdge(1, 3); 
    cout << g.DFS(2, 3) << endl;
}