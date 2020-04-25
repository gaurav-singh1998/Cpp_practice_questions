//https://www.geeksforgeeks.org/maximum-number-edges-added-tree-stays-bipartite-graph/

//maximum edges a bipartite graph can have are count_color0 * count_color1

/**
Do a simple DFS (or BFS) traversal of graph and color it with two colors

While coloring also keep track of counts of nodes colored with the two 
colors. Let the two counts be count_color0 and count_color1

Now we know maximum edges a bipartite graph can have are count_color0 x count_color1.

We also know tree with n nodes has n-1 edges.

So our answer is count_color0 * count_color1 - (n-1).
**/

#include<bits/stdc++.h>
using namespace std;

long long count_color[2]; 
void dfs(vector<int> adj[], int node, int parent, int color) 
{
    count_color[color]++;
    for (int i = 0; i < adj[node].size(); i++)
    {
        if (adj[node][i] != parent) 
        {
            dfs(adj, adj[node][i], node, !color);
        }
    }
}

int findMaxEdges(vector<int> adj[], int n) 
{
    dfs(adj, 1, 0, 0);
    return count_color[0] * count_color[1] - (n - 1);
}

int main()
{
    int n = 5; 
    vector<int> adj[n + 1]; 
    adj[1].push_back(2); 
    adj[1].push_back(3); 
    adj[2].push_back(4); 
    adj[3].push_back(5); 
    cout << findMaxEdges(adj, n) << endl; 
    return 0; 
}