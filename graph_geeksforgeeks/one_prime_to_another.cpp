//https://www.geeksforgeeks.org/shortest-path-reach-one-prime-changing-single-digit-time/
/**
Given two four digit prime numbers, suppose 1033 and 8179, we need to find
the shortest path from 1033 to 8179 by altering only single digit at a time such that every number 
that we get after changing a digit is prime. For example a solution is
1033, 1733, 3733, 3739, 3779, 8779, 8179
**/

#include<bits/stdc++.h>
using namespace std;

void SieveOfEratosthenes(vector<int>& v)
{
    bool isPrime[10000]={false};
    for(int i=3; i<=10000; i+=2)
    {
        isPrime[i]=true;
    }

    for(int i=3; i<=10000; i+=2)
    {
        if(isPrime[i])
        {
            for(int j=i*i; j<=10000; j+=i)
            {
                isPrime[j]=false;
            }
        }
    }

    isPrime[2]=true;
    for(int i=1000;i<=10000; i++)
    {
        if(isPrime[i])
        {
            v.push_back(i);
        }
    }
}

bool compare(int num1, int num2) 
{ 
    string s1 = to_string(num1); 
    string s2 = to_string(num2); 
    int c = 0; 
    if (s1[0] != s2[0]) 
        c++; 
    if (s1[1] != s2[1]) 
        c++; 
    if (s1[2] != s2[2]) 
        c++; 
    if (s1[3] != s2[3]) 
        c++; 
   
    return (c == 1); 
}

class Graph
{
    int V;
    map<int, list<int>> adjList;

    public:
    Graph(int v)
    {
        this->V=v;
    }

    void addEdge(int u, int v)
    {
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    int bfs(int in1, int in2)
    {
        int visited[V];
        memset(visited, 0, sizeof(visited));
        visited[in1]=1;
        queue<int> q;
        q.push(in1);

        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            for(auto neighbour: adjList[node])
            {
                if(!visited[neighbour])
                {
                    visited[neighbour]=visited[node]+1;
                    q.push(neighbour);
                }
                if(neighbour==in2)
                {
                    return visited[neighbour]-1;
                }
            }
        }
    }
};

int shortestPath(int num1, int num2) 
{ 
    vector<int> pset;  
    SieveOfEratosthenes(pset); 
  
    Graph g(pset.size());  
    for (int i = 0; i < pset.size(); i++)  
        for (int j = i + 1; j < pset.size(); j++)  
            if (compare(pset[i], pset[j])) 
                g.addEdge(i, j);      
      

    int in1, in2; 
    for (int j = 0; j < pset.size(); j++)  
        if (pset[j] == num1) 
            in1 = j;  
    for (int j = 0; j < pset.size(); j++)  
        if (pset[j] == num2) 
            in2 = j;  
  
    return g.bfs(in1, in2); 
} 

int main() 
{ 
    int num1 = 1373, num2 = 8017; 
    cout << shortestPath(num1, num2) << endl; 
    return 0; 
} 