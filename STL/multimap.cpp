#include<bits/stdc++.h>
using namespace std;

int main()
{
    multimap<char, string> m;
    typedef pair<char, string> ll;
    ll code;
    for(int i=0; i<7; i++)
    {
        cin >> code.first >> code.second;
        m.insert(code);
    } 
    for(auto it: m)
    {
        cout << it.first << "->" << it.second << endl;
    }
}