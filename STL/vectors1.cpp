#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    vector <int> v(5);
    for(int i=0; i<=4; i++)
    {
        cin >> v[i];
    }
    next_permutation(v.begin(), v.end());
    for(int i=0; i<=4; i++)
    {
        cout << v[i] << endl;
    }
}
