#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector <int> v;
    //v.reserve(100);
    int n;
    cin >> n;
    for(int i=0; i<n ; i++)
    {
        int temp;
        cin >> temp;
        v.push_back(temp);
    }
    cout << v.capacity() << endl;
    v.pop_back();
    for(int i=0; i<v.size(); i++)
    {
        cout << v[i] << endl;
    }
}
