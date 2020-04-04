#include<bits/stdc++.h>
using namespace std;

int findUnique(int *a, int n)
{
    int res=0;
    for(int i=0; i<n; i++)
    {
        res=res^a[i];
    }
    return res;
}

int main()
{
    int n;
    cin >> n;
    int a[n];
    for(int i=0; i<n; i++)
    {
        cin >> a[i];
    }
    cout << findUnique(a, n) << endl;
}
