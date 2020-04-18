#include<bits/stdc++.h>
using namespace std;

class Graph
{
    map<int, list<int>> adjList;
    int v;

    public:
    Graph(int v)
    {
        this->v=v;
    }

    void addEdge(int u, int v)
    {
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    void dfs(int src, map<int, bool> &visited)
    {
        visited[src]=true;
        for(auto neighbour: adjList[src])
        {
            if(!visited[neighbour])
            {
                dfs(neighbour, visited);
            }
        }
    }

    bool isConnected()
    {
        map<int, bool> visited;
        int i;
        for(i=0; i<v; i++)
        {
            if(adjList[i].size() != 0)
            {
                break;
            }
        }

        if(i==v)
        {
            return true;
        }

        dfs(i, visited);
        for(int i=0; i<v; i++)
        {
            if(visited[i]==false && adjList[i].size()>0)
            {
                return false;
            }
        }

        return true;
    }

/* The function returns one of the following values 
   0 --> If grpah is not Eulerian 
   1 --> If graph has an Euler path (Semi-Eulerian) 
   2 --> If graph has an Euler Circuit (Eulerian)  */
    int isEulerian()
    {
        if(isConnected() == false) return 0;

        int odd=0;
        for(int i=0; i<v; i++)
        {
            if(adjList[i].size() & 1)
            {
                odd++;
            }
        }

        if(odd > 2) return 0;
        return (odd)? 1 : 2;
    }
};

void test(Graph &g) 
{ 
    int res = g.isEulerian(); 
    if (res == 0) 
        cout << "graph is not Eulerian\n"; 
    else if (res == 1) 
        cout << "graph has a Euler path\n"; 
    else
        cout << "graph has a Euler cycle\n"; 
} 

int main()
{
    // Let us create and test graphs shown in above figures 
    Graph g1(5); 
    g1.addEdge(1, 0); 
    g1.addEdge(0, 2); 
    g1.addEdge(2, 1); 
    g1.addEdge(0, 3); 
    g1.addEdge(3, 4); 
    test(g1); 
  
    Graph g2(5); 
    g2.addEdge(1, 0); 
    g2.addEdge(0, 2); 
    g2.addEdge(2, 1); 
    g2.addEdge(0, 3); 
    g2.addEdge(3, 4); 
    g2.addEdge(4, 0); 
    test(g2); 
  
    Graph g3(5); 
    g3.addEdge(1, 0); 
    g3.addEdge(0, 2); 
    g3.addEdge(2, 1); 
    g3.addEdge(0, 3); 
    g3.addEdge(3, 4); 
    g3.addEdge(1, 3); 
    test(g3); 
  
    // Let us create a graph with 3 vertices 
    // connected in the form of cycle 
    Graph g4(3); 
    g4.addEdge(0, 1); 
    g4.addEdge(1, 2); 
    g4.addEdge(2, 0); 
    test(g4); 
  
    // Let us create a graph with all veritces 
    // with zero degree 
    Graph g5(3); 
    test(g5); 

    Graph g6(4);
    g6.addEdge(1, 2);
    g6.addEdge(3, 4);
    test(g6);
  
    return 0; 
}