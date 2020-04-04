#include<bits/stdc++.h>
using namespace std;

int linear_search(int *a, int n, int key)
{
    if(n<0)
    {
        return -1;
    }
    else
    {
        if(a[n-1]==key) return n-1;
        else
        {
            return linear_search(a, n-1, key);
        }
        
    }
    
}

int main()
{
    int a[]={1, 2, 3, 4, 5};
    int n=sizeof(a)/sizeof(int);
    int key;
    cin >> key;
    int ans=linear_search(a, n, key);
    if(ans==-1)
    {
        cout << "not found" << endl;;
    }
    else
    {
        cout << "found at: " << ans << endl;
    }
    
}