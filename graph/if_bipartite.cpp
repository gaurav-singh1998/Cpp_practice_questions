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
};

int main()
{
    Graph g;
    g.addEdge(1, 2);
    g.addEdge(1, 4);
    g.addEdge(2, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 2);
    g.addEdge(3, 4);
    g.addEdge(4, 1);
    g.addEdge(4, 3);
    cout << g.ifBipartite() << endl;

    Graph g2;
    g2.addEdge(1, 2);
    g2.addEdge(2, 3);
    g2.addEdge(3, 4);
    g2.addEdge(4, 5);
    g2.addEdge(5, 1);
    cout << g2.ifBipartite() << endl;

    Graph g3;
    g3.addEdge(1, 2);
    g3.addEdge(2, 3);
    g3.addEdge(3, 4);
    g3.addEdge(4, 5);
    g3.addEdge(5, 6);
    g3.addEdge(6, 1);
    cout << g3.ifBipartite() << endl;

    Graph g4;
    g4.addEdge(1, 6);
    g4.addEdge(2, 6);
    g4.addEdge(2, 7);
    g4.addEdge(3, 8);
    g4.addEdge(3, 9);
    g4.addEdge(4, 7);
    g4.addEdge(5, 6);
    g4.addEdge(5, 9);
    cout << g4.ifBipartite() << endl;
}