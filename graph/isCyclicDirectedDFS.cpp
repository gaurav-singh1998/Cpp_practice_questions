#include<bits/stdc++.h>
using namespace std;


template<typename T>
class Graph
{
    map<T, list<T>>adjList;
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
            cout << i.first << "-->";
            for(auto neighbour: i.second)
            {
                cout << neighbour << ", ";
            }
        }
    }

    bool isCycleHelper(T node, map<T, bool> &visited, map<T, bool> &inStack)
    {
        visited[node]=true;
        inStack[node]=true;

        for(auto elem: adjList[node])
        {
            if(inStack[elem]==true)
            {
                return true;
            }

            else if(!visited[elem])
            {
                bool isValid=isCycleHelper(elem, visited, inStack);
                if(isValid)
                {
                    return true;
                }
            }
        }

        inStack[node]=false;
        return false;
    }

    //Check for directed graph.
    bool isCyclicDFS()
    {
        map<T, bool> visited;
        map<T, bool> inStack;

        bool isValid=isCycleHelper(0, visited, inStack);
        if(isValid)
        {
            return true;
        }
        return false;
    }
};