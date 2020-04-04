#include<bits/stdc++.h>
using namespace std;

int main()
{
    list<int> l;
    //intialize a list with certain numbers
    list<int> l1{1, 4, 5, 8, 10, 15, 14, 98, 0};
    l1.push_back(13);
    for(int x: l1)
    {
        cout << x << endl;
    }
    l1.sort();
    l1.front();
    l1.pop_front();
    l1.push_front(9999);
    for(auto x: l1)
    {
        cout << x << endl;
    }
    cout << endl;
    cout << "Part 2" << endl;
    cout << endl;
    list<string> l2{"Apple", "Mango", "Guava", "pineapple"};
    for(auto x: l2)
    {
        cout << x  << "-->";
    }
    cout << endl;
    l2.push_back("Guava");
    l2.push_back("Guava");
    for(auto x: l2) cout << x << endl;
    l2.remove("Guava");
    for(auto x: l2) cout << x << "-->";
    cout << endl;
    auto it = l2.begin();
    it++; 
    l2.erase(it);
    for(auto x: l2) cout << x << endl;
    auto it1 = l2.begin();
    it1++;
    l2.insert(it1, "juice");
    for(auto x: l2) cout << x << endl;
}