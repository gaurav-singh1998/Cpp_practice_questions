#include<bits/stdc++.h>
#define ll long long
using namespace std;

template<typename T>
class Graph
{
    ll noVertex;
    ll noEdges;
    map<T, list<T>> adjList;
    public:
    Graph(ll noVertex, ll noEdges)
    {
        this->noVertex = noVertex;
        this->noEdges = noEdges;
    }

    void addEdge(T u, T v, bool bidir=true)
    {
        adjList[u].push_back(v);
        if(bidir)
        {
            adjList[v].push_back(u);
        }
    }

    void print()
    {
        for(auto node: adjList)
        {
            cout << node.first << "--> ";
            for(auto neighbour: adjList[node.first])
            {
                cout << neighbour << "  ";
            }
            cout << endl;
        }
    }

    void sssp(T src)
    {
        queue<T> q;
        map<T, int> dist;
        bool *visited = new bool[this->noVertex + 1]{false};
        //map<T, T> parent;

        for(auto i: adjList)
        {
            dist[i.first] = INT_MAX;
        }

        q.push(src);
        dist[src] = 0;
        //parent[src] = src;
        visited[src] = true;

        while(!q.empty())
        {
            T node = q.front();
            //cout << node << " ";
            q.pop();


            for(auto neighbour: adjList[node])
            {
                if(dist[neighbour]==INT_MAX)
                {
                    q.push(neighbour);
                    dist[neighbour] =dist[node] + 6;
                    //parent[neighbour] = node;
                    visited[neighbour] = true;
                }
            }
        }
        int *finalAns = new int[this->noVertex + 1]{-1};
        for(int i=1; i<=noVertex; i++)
        {
            if(visited[i] && dist[i]!=0 && dist[i]!=INT_MAX)
            {
                finalAns[i] = dist[i];
            }
        }
        for(int i=1; i<=noVertex; i++)
        {
            if(i != src && finalAns[i] == 0)
            {
                cout << -1 << " ";
            }
            else if(i != src)
            {
                cout << finalAns[i] << " ";
            }
        }
        cout << endl;
    }
};

int main()
{
    int q;
    cin >> q;
    while(q--)
    {
        ll N, M; cin >> N >> M;
        Graph<int> g(N, M);
        for(int i=0; i<M; i++)
        {
            int u, v; cin >> u >> v;
            g.addEdge(u, v);
        }
        int spoint;
        cin >> spoint;
        g.sssp(spoint);
    }
}