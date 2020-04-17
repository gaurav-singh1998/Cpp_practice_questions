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
        visited[node] = true;
        inStack[node] = true;

        //Explore the neighbours
        for(auto neighbour: adjList[node])
        {
            if(!visited[neighbour] && isCycleHelper(neighbour, visited, inStack) || inStack[neighbour])
            {
                return true;
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

        //To check for cycle in each DFS tree
        for(auto i: adjList)
        {
            T node = i.first;
            if(!visited[node])
            {
                bool cyclePresent = isCycleHelper(node, visited, inStack);
                if(cyclePresent) return true;
            }
        }
        return false;
    }
};