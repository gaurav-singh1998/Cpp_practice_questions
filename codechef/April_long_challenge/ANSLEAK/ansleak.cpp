#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t; cin >>t;
    while(t--)
    {
        int n, m, k; cin >> n >> m >> k;
        for (int i = 0; i < n * k; i++)
        {
            int x; cin >> x;
        }
        for (int i = 0; i < n; i++)
        {
            cout << rand() % m + 1 << ' ';
            cout << '\n';
        }
    }
}