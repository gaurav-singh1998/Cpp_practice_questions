//https://www.geeksforgeeks.org/bidirectional-search/

#include<bits/stdc++.h>
using namespace std;

class Graph
{
    map<int, list<int>> adjList;
    int V;

    void BFS(queue<int>& q, map<int, bool>& visited, map<int, int>& parent)
    {
        int current=q.front();
        q.pop();
        for(auto neighbour: adjList[current])
        {
            if(!visited[neighbour])
            {
                visited[neighbour]=true;
                parent[neighbour]=current;
                q.push(neighbour);
            }
        }
    }

    int isIntersecting(map<int, bool> s_visited, map<int, bool> t_visited)
    {
        for(int i=0; i<V; i++)
        {
            if(s_visited[i] && t_visited[i])
            {
                return i;
            }
        }
        return -1;
    }

    void printPath(map<int, int> s_parent, map<int, int> t_parent, int src, int dest, int intersectNode)
    {
        vector<int> path; 
        path.push_back(intersectNode); 
        int i = intersectNode; 
        while (i != src) 
        { 
            path.push_back(s_parent[i]); 
            i = s_parent[i]; 
        } 
        reverse(path.begin(), path.end()); 
        i = intersectNode; 
        while(i != dest) 
        { 
            path.push_back(t_parent[i]); 
            i = t_parent[i]; 
        } 
  
        cout << "*************PATH****************" << endl;
        for(auto elem: path)
        {
            cout << elem << " ";
        }
        cout << endl;
    }

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

    int bidirSearch(int src, int dest)
    {
        map<int, bool> s_visited;
        map<int, bool> t_visited;

        map<int, int> s_parent;
        map<int, int> t_parent;

        queue<int> s_queue;
        queue<int> t_queue;

        int intersectNode=-1;

        s_queue.push(src);
        t_queue.push(dest);

        s_parent[src]=-1; s_visited[src]=true;
        t_parent[dest]=-1; t_visited[dest]=true;

        while(!s_queue.empty() && !t_queue.empty())
        {
            BFS(s_queue, s_visited, s_parent);
            BFS(t_queue, t_visited, t_parent);

            intersectNode = isIntersecting(s_visited, t_visited); 

            if(intersectNode != -1)
            {
                cout << "Path exist between " << src << " and "
                 << dest << "\n"; 
                cout << "Intersection at: " << intersectNode << endl;

                printPath(s_parent, t_parent, src, dest, intersectNode); 
                exit(0);
            }
        }
        return -1;
    }
};

int main()
{
    int n=17;
    Graph g(n);
    g.addEdge(0, 4); 
    g.addEdge(1, 4); 
    g.addEdge(2, 5); 
    g.addEdge(3, 5); 
    g.addEdge(4, 6); 
    g.addEdge(5, 6); 
    g.addEdge(6, 7); 
    g.addEdge(7, 8); 
    g.addEdge(8, 9); 
    g.addEdge(8, 10); 
    g.addEdge(9, 11); 
    g.addEdge(9, 12); 
    g.addEdge(10, 13); 
    g.addEdge(10, 14);
    g.addEdge(14, 15);
    g.addEdge(15, 16);
    g.bidirSearch(0, 16);
}