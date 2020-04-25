//https://www.geeksforgeeks.org/print-paths-given-source-destination-using-bfs/

#include<bits/stdc++.h>
using namespace std;

class Graph
{
    map<int, list<int>> adjList;

    void printPath(vector<int> path)
    {
        for(int i=0; i<path.size(); i++)
        {
            cout << path[i] << " ";
        }
        cout << endl;
    }

    bool isNotVisited(vector<int> path, int vertex)
    {
        for(int i=0; i<path.size(); i++)
        {
            if(path[i]==vertex)
            {
                return false;
            }
        }
        return true;
    }

    public:
    void addEdge(int u, int v)
    {
        adjList[u].push_back(v);
    }

    void bfs(int src, int dest)
    {
        queue<vector<int>> q;
        vector<int> path;
        path.push_back(src);
        q.push(path);

        while(!q.empty())
        {
            path = q.front();
            q.pop();

            int last = path[path.size() - 1];
            if(last == dest)
            {
                printPath(path);
            }

            for(auto neighbour: adjList[last])
            {
                if(isNotVisited(path, neighbour))
                {
                    vector<int> newpath(path);
                    newpath.push_back(neighbour);
                    q.push(newpath);
                }
            }
        }
    }
};

int main()
{
    Graph g;
    g.addEdge(0, 2);
    g.addEdge(0, 3);
    g.addEdge(0, 1);
    g.addEdge(2, 0);
    g.addEdge(2, 1);
    g.addEdge(1, 3);
    g.bfs(2, 3);
}