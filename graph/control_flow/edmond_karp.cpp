#include<bits/stdc++.h>
using namespace std;

bool bfs(int **capacity, int source, int sink, int n, int *parent)
{
    bool *visited = new bool[n]{false};
    queue<int> q;
    visited[source] = true;
    q.push(source);
    bool foundAugmentedPath = false;

    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(int v=0; v<n; v++)
        {
            if(!visited[v] && capacity[u][v] > 0)
            {
                parent[v]=u;
                visited[v]=true;
                q.push(v);
                if(v==sink)
                {
                    foundAugmentedPath = true;
                    break;
                }
            }
        }
    }

    return foundAugmentedPath;
}

void printAugmentedPaths(vector<vector<int>> augmentedPaths)
{
    for(int i=0; i<augmentedPaths.size(); i++)
    {
        for(int j=0; j<augmentedPaths[i].size(); j++)
        {
            cout << augmentedPaths[i][j] << ", ";
        }
        cout << endl;
    }
}

int maxFlow(int **capacity, int source, int sink, int v)
{
    int **residualCapacity = new int*[v];

    for(int i=0; i<v; i++)
    {
        residualCapacity[i] = new int[v];
    }

    for(int i=0; i<v; i++)
    {
        for(int j=0; j<v; j++)
        {
            residualCapacity[i][j] = capacity[i][j];
        }
    }

    int *parent = new int[1000];
    vector<vector<int>> augmentedPaths;
    int maxflow =0;

    while(bfs(residualCapacity, source, sink, v, parent))
    {
        vector<int> currentAugmentedPath;
        int flow = INT_MAX;
        int v = sink;
        while(v!=source)
        {
            currentAugmentedPath.push_back(v);
            int u = parent[v];
            if(flow > residualCapacity[u][v])
            {
                flow = residualCapacity[u][v];
            }
            v=u;
        }
        currentAugmentedPath.push_back(source);
        reverse(currentAugmentedPath.begin(), currentAugmentedPath.end());
        augmentedPaths.push_back(currentAugmentedPath);
        maxflow += flow;

        v=sink;
        while(v!=source)
        {
            int u = parent[v];
            residualCapacity[u][v] -= flow;
            residualCapacity[v][u] += flow;
            v=u;
        }
    }

    printAugmentedPaths(augmentedPaths);
    return maxflow;
}

int main()
{
    int v, e; cin >> v >> e;
    int **capacity = new int*[v];

    for(int i=0; i<v; i++)
    {
        capacity[i] = new int[v];
    }

    for(int i=0; i<e; i++)
    {
        int u, v, c; cin >> u >> v >> c;
        capacity[u][v] = c;

    }
    cout << maxFlow(capacity, 0, 1, v) << endl;
}
/**
5 7
0 2 100
0 3 50 
2 3 50
2 4 50
3 4 100    
2 1 50
4 1 125
**/