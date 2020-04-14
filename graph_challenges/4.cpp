#include<bits/stdc++.h>
using namespace std;

template<typename T>
class Graph
{
    int no_of_vertices;
    int no_of_edges;
    map<T, list<pair<T, int>>> adjList;

    public:
    Graph<T>(int no_of_vertices, int no_edges)
    {
        this->no_of_vertices= no_of_vertices;
        this->no_of_edges=no_edges;
    }
    void addEdge(T u, T v, int dist, bool bidir=true)
    {
        adjList[u].push_back(make_pair(v, dist));
        if(bidir)
        {
            adjList[v].push_back(make_pair(u, dist));
        }
    }

    void print()
    {
        for(auto i: adjList)
        {
            cout << i.first << "--> ";
            for(auto j: adjList[i.first])
            {
                cout << j.first << " " << j.second << endl;
            }
        }
    }

    void Dijkstra(T src)
    {
        map<T, int> dist;
        for(int i=1; i<=this->no_of_vertices; i++)
        {
            dist[i]=INT_MAX;
        }
        set<pair<int, T>> s;
        dist[src]=0;
        s.insert(make_pair(0, src));

        while(!s.empty())
        {
            auto p = *(s.begin());
            T node = p.second;
            int nodeDist = p.first;

            s.erase(s.begin());
            for(auto child: adjList[node])
            {
                if(nodeDist + child.second < dist[child.first])
                {
                    T dest = child.first;
                    auto f = s.find(make_pair(dist[dest], dest));
                    if(f != s.end())
                    {
                        s.erase(f);
                    }
                    dist[dest] = nodeDist + child.second;
                    s.insert(make_pair(dist[dest], dest));
                }
            }
        }
        for(int i=1; i<=this->no_of_vertices; i++)
        {
            if(dist[i]== INT_MAX)
            {
                dist[i]=-1;
            }
        }
        for(int i=1; i<=this->no_of_vertices; i++)
        {
            if(i!=src)
            {
                cout << dist[i] << " ";
            }
        }
        cout << endl;
    }
};

int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        int N, M; cin >> N >> M;
        Graph<int> g(N, M);
        for(int i=0; i<M; i++)
        {
            int u, v, dist; cin >> u >> v >> dist;
            g.addEdge(u, v, dist);
        }
        int r; cin >> r;
        g.Dijkstra(r);
    }
}