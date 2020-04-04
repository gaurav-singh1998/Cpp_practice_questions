#include<bits/stdc++.h>
using namespace std;

int binary_search(int *arr, int a, int b, int key)
{
    //base case
    if(b<a) return -1;

    //recursive case
    int mid=(a+b)/2;
    if(arr[mid]==key) return mid;
    else if(arr[mid]<key) return binary_search(arr, mid+1, b, key);
    else return binary_search(arr, a, mid-1, key);
}

int main()
{
    int arr[]={1, 2, 3, 4, 5};
    int a=0, b=4;
    int key;
    cin >> key;
    int ans=binary_search(arr, a, b, key);
    cout << ans << endl;
}