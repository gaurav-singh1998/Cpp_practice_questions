//https://hack.codingblocks.com/app/practice/1/522/problem

#include <bits/stdc++.h>
using namespace std;

int testCase = 0;

template<typename T>

class Graph{
    int V;
public:

    unordered_map<T, list<T>>adjList;
    Graph<T>(int v){
        
        V = v;
    }
    
    void addEdge(T u, T v){

        adjList[u].push_back(v);
    }

    
    void print(){
        
        for(auto i:adjList){
            
           /// cout<<"printing testing "<<endl;
            T node = i.first;
            cout<<node<<" -> ";
            for(T neighbour:i.second){ /// this syntex is not working
                
                cout<<neighbour<<", ";
            }
            cout<<endl;
        }
        
        cout<<endl;
    }
    
    
    void dfsHelper(T node, map<T, bool>&visited, list<T>&ordering){
    
        visited[node] = true;
        
        for(T neighbour:adjList[node]){
            
            if(!visited[neighbour]){
                
                dfsHelper(neighbour, visited, ordering);
            }
        }
        
        
        ordering.push_front(node);
    }
    
    void topologicalSort(vector<string>v){
        
        map<T, bool>visited;
        
        list<T>ordering;
        
        ///call beverage name with descending order of given input 
        for(int i = v.size()-1; i >= 0; i--){  
            
            T node = v[i];
            if(!visited[node]){
                
                dfsHelper(node, visited, ordering);
            }
        }
        
    
        testCase++;
        cout<<"Case #"<<testCase<<":"<<" Vivek should drink beverages in this order: ";
        
        
        int lastIndex = 0;
        
        for(T i:ordering){
            
            lastIndex++;
            if(lastIndex == ordering.size()){
                
                cout<<i<<".";
                break;
            }
            cout<<i<<" ";
        }
        cout<<endl;
    }
};


int main(){
    
    ///int t;
    //cin>>t;
    ///number of vertix
    int vertix = -1;
    cin>>vertix;
    while(vertix != -1){
        
        ///int vertix;
        ///cin>>vertix;
        std::vector<string> v(vertix);
        Graph<string>g(vertix);
        
        ///taking input all beverages in given order
        
        for(int i = 0; i < vertix; i++){
        
            cin>>v[i];
        }
        
        ///number of edge 
        int edge;
        cin>>edge;
        for(int i = 0; i < edge; i++){
            
            string u, v;
            cin>>u>>v;
            g.addEdge(u, v);
        }
       /// g.print();
        
        g.topologicalSort(v);
        
        vertix = -1;
        ///again taking input for number of vertix
        cin>>vertix;
    }
	return 0;
}
