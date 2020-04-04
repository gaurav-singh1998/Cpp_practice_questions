#include<bits/stdc++.h>
using namespace std;

int main()
{
    // maps in C++ are of two types 
    // [a] Unordered Map:- Uses separate chaining technique with hash function
    // useful to keep elements in unsorted order has a time complexity of O(1)
    // to search an element;
    // [b] Map:- Uses Balanced BST of red-black tree, useful to keep
    // values of (key, value) pair in sorted order has a time complexity of 
    // O(logn) to element;
    //
    
    unordered_map<string, int> m;
    m["mango"] = 100;
    m.insert(make_pair("Apple", 120));
    if(m.count("Apple")==1)
    {
        cout << m["Apple"] << endl;
    }

    auto it = m.find("mango");
    if(it!=m.end())
    {
        cout << (it->second) << endl;
    }

    // to delete
    m.erase("mango");

}
