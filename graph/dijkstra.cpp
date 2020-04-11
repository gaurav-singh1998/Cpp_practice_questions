#include<bits/stdc++.h>
using namespace std;

template<typename T>
class Graph
{
    map<T, list<pair<T, int>>>adjList;

    public:
    void addEdge(T u, T v, int dist, bool bidir)
    {
        adjList[u].push_back(make_pair(v, dist));

        if(bidir)
        {
            adjList[v].push_back(make_pair(u, dist));
        }
    }

    void printAdj()
    {
        for(auto i: adjList)
        {
            cout << i.first << "--> ";
            for(auto pair: i.second)
            {
                cout << pair.first << " " << pair.second << ", ";
            }
            cout << endl;
        }
    }

    void dijkstraSSSP(T src)
    {
        unordered_map<T, int> dist;
        for(auto i: adjList)
        {
            T node = i.first;
            dist[node] = INT_MAX;
        }

        set<pair<int, T>> s;

        dist[src]=0;
        s.insert(make_pair(0, src));

        while(!s.empty())
        {
            auto p = *s.begin();
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
    }

};