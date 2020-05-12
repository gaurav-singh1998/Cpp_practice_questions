#include<bits/stdc++.h>
using namespace std;


int SearchIn(int a[], int s, int e, int key)
{
    //Base case
    if(s>e)
    {
        return -1;
    }

    //rec case
    int mid=(s+e)/2;
    if(a[mid]==key)
    {
        return mid;
    }

    //mid lies in the first line
    if(a[s]<=a[mid])
    {
        if(key>=a[s] && key<=a[mid])
        {
            return SearchIn(a, s, mid-1, key);
        }
        else
        {
            return SearchIn(a, mid+1, e, key);
        }
        
    }
    //mid lies in the second line
    if(key>=a[mid]&& key<=a[e])
    {
        return SearchIn(a, mid+1, e, key);
    }
    return SearchIn(a, s, mid-1, key);
     
}


int main()
{
    int arr[]={4, 5, 1, 2, 3};
    int n=sizeof(arr)/sizeof(int);
    int key; cin >> key;
    cout << SearchIn(arr, 0, n-1, key) << endl;
}