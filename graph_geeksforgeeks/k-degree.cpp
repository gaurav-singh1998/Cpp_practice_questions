//https://www.geeksforgeeks.org/find-k-cores-graph/

/**
Given a graph G and an integer K, K-cores of the graph are connected components
that are left after all vertices of degree less than k have been removed
**/

#include<bits/stdc++.h>
using namespace std;

class Graph
{
    int V;
    map<int, list<int>> adjList;

    public:
    Graph(int v)
    {
        this->V=v;
    }

    void addEdge(int u, int v)
    {
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    bool DFS(int src, vector<bool>& visited, vector<int>& vdegree, int K)
    {
        visited[src]=true;

        for(auto neighbour: adjList[src])
        {
            if(vdegree[src]<K)
            {
                vdegree[neighbour]--;
            }

            if(!visited[neighbour])
            {
                if(DFS(neighbour, visited, vdegree, K))
                {
                    vdegree[src]--;
                }
            }
        }
        return (vdegree[src]<K);
    }

    void printKcores(int K)
    {
        vector<bool> visited(V, false);
        int mindeg=INT_MAX;
        int startvertex;

        vector<int> vdegree(V);

        for(int i=0; i<V; i++)
        {
            vdegree[i]=adjList[i].size();

            if(vdegree[i]<mindeg)
            {
                mindeg=vdegree[i];
                startvertex=i;
            }
        }

        DFS(startvertex, visited, vdegree, K);
        for (int i=0; i<V; i++)
        { 
            if (visited[i] == false)
            {
                DFS(i, visited, vdegree, K);
            }
        }
        cout << "K-Cores : \n"; 
        for (int v=0; v<V; v++) 
        {
            if (vdegree[v] >= K) 
            { 
                cout << "\n[" << v << "]";  
                for (auto neighbour: adjList[v])
                {
                    if (vdegree[neighbour] >= K)
                    {
                        cout << " -> " << neighbour; 
                    }
                }
            } 
        } 
    }
};

int main() 
{ 
    int k = 3; 
    Graph g1(9); 
    g1.addEdge(0, 1); 
    g1.addEdge(0, 2); 
    g1.addEdge(1, 2); 
    g1.addEdge(1, 5); 
    g1.addEdge(2, 3); 
    g1.addEdge(2, 4); 
    g1.addEdge(2, 5); 
    g1.addEdge(2, 6); 
    g1.addEdge(3, 4); 
    g1.addEdge(3, 6); 
    g1.addEdge(3, 7); 
    g1.addEdge(4, 6); 
    g1.addEdge(4, 7); 
    g1.addEdge(5, 6); 
    g1.addEdge(5, 8); 
    g1.addEdge(6, 7); 
    g1.addEdge(6, 8); 
    g1.printKcores(k); 
  
    cout << endl;
    return 0; 
} 