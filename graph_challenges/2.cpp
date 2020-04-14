#include<bits/stdc++.h>
using namespace std;

template<typename T>
class Graph
{
    map<T, list<T>> adjList;

    public:
    void addEdge(T u, T v, bool bidir=false)
    {
        adjList[u].push_back(v);
        if(bidir)
        {
            adjList[v].push_back(u);
        }
    }
    void print()
    {
        for(auto i: adjList)
        {
            cout << i.first << "--> ";
            for(auto neighbour: adjList[i])
            {
                cout << neighbour << "  ";
            }
            cout << endl;
        }
    }

    void sssp(T src, T dest)
    {
        queue<T> q;
        map<T, int> dist;
        dist[dest] = -1;
        for(auto i: adjList)
        {
            dist[i.first] = INT_MAX;
        }

        q.push(src);
        dist[src] = 0;
        while(!q.empty())
        {
            T node = q.front();
            q.pop();
            for(auto neighbour: adjList[node])
            {
                if(dist[neighbour] == INT_MAX)
                {
                    dist[neighbour] = dist[node] + 1;
                    q.push(neighbour); 
                }
            }
        }
        cout << dist[dest] << endl;
    }
};

int main()
{
    int *board = new int[1000]{0};
    int T;
    cin >> T;
    while(T--)
    {
        Graph<int> g;
        int no_of_ladders; cin >> no_of_ladders;
        while(no_of_ladders--)
        {
            int from, to; cin >> from >> to;
            board[from]+=(to-from);
        }
        int no_of_snakes; cin >> no_of_snakes;
        while(no_of_snakes--)
        {
            int from, to; cin >> from >> to;
            board[from]-=(from-to);
        }
        for(int u=1; u<=100; u++)
        {
            for(int dice=1; dice<=6; dice++)
            {
                int v = u + board[u+dice] + dice;
                if(v<=100) g.addEdge(u, v);
            }   
        }
        g.sssp(1, 100);
    }
}