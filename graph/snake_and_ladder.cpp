#include<bits/stdc++.h>
using namespace std;



template<typename T>
class Graph
{
    map<T, list<T>> adjList;

    public:
    void addEdge(T u, T v, bool bidir)
    {
        adjList[u].push_back(v);
        if(bidir)
        {
            adjList[v].push_back(u);
        }
    }

    void printGraph()
    {
        for(auto node: adjList)
        {
            cout << node.first << "--> ";
            for(auto element: node.second)
            {
                cout << element << ", ";
            }
            cout << endl;
        }
        cout << endl;
    }

    int sssp(T src, T dest)
    {
        queue<T> q;
        map<T, int> dist;
        map<T, T> parent;

        for(auto i: adjList)
        {
            dist[i.first] = INT_MAX;
        }

        q.push(src);
        dist[src] = 0;
        parent[src] = src;

        while(!q.empty())
        {
            T node = q.front();
            q.pop();


            for(auto neighbour: adjList[node])
            {
                if(dist[neighbour]==INT_MAX)
                {
                    q.push(neighbour);
                    dist[neighbour] =dist[node] + 1;
                    parent[neighbour] = node;
                }
            }
        }

        //for(auto i: adjList)
        //{
        //    T node = i.first;
        //    cout << "Dist of " << node << "is " << dist[node] << endl;
        //}

        T temp = dest;
        while(temp != src)
        {
            cout << temp << "<--";
            temp = parent[temp];
        }
        cout << src << endl;

        return dist[dest];
    }
};


int main()
{
    int *board = new int[50]{0};
    board[2] = 13;
    board[5] = 2;
    board[9] = 18;
    board[18] = 11;
    board[17] = -13;
    board[20] = -14;
    board[24] = -8;
    board[25] = -10;
    board[32] = -2;
    board[34] = -22;
    Graph<int> g;

    for(int u=0; u<=36; u++)
    {
        for(int dice=1; dice<=6; dice++)
        {
            int v = u + dice +board[u+dice];
            g.addEdge(u, v, false);
        }
    }

    cout << g.sssp(0, 36) << endl;
    return 0;
}