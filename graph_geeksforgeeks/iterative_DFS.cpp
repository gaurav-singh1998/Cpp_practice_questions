//https://www.geeksforgeeks.org/iterative-depth-first-traversal/

#include<bits/stdc++.h>
using namespace std;

class Graph
{
    map<int, list<int>> adjList;

    public:
    void addEdge(int u, int v)
    {
        adjList[u].push_back(v);
        //adjList[v].push_back(u);
    }

    void iter_DFS(int s) 
    { 
        map<int, bool> visited;
  
        stack<int> stack; 
  
        stack.push(s); 
  
        while (!stack.empty()) 
        { 
            s = stack.top(); 
            stack.pop(); 
            if (!visited[s]) 
            { 
                cout << s << " "; 
                visited[s] = true; 
            } 
            for(auto neighbour: adjList[s])
            {
                if(!visited[neighbour])
                {
                    stack.push(neighbour);
                }
            }
        }
    } 
};

int main()
{
    Graph g; 
    g.addEdge(1, 0); 
    g.addEdge(0, 2); 
    g.addEdge(2, 1); 
    g.addEdge(0, 3); 
    g.addEdge(1, 4); 
  
    cout << "Following is Depth First Traversal\n"; 
    g.iter_DFS(0);
    cout << endl;
}