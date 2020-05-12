#include<bits/stdc++.h>
using namespace std;

int first_occurence(int* arr, int ans, int s, int e, int key)
{
    //Base case
    if(s>=e)
    {
        return ans;
    }

    //Recursive case
    int mid=(s+e)/2;
    if(arr[mid]==key)
    {
        ans=mid;
        return first_occurence(arr, ans, s, mid-1, key);
    }

    else if(arr[mid]<key)
    {
        return first_occurence(arr, ans, mid+1, e, key);
    }

    else
    {
        return first_occurence(arr, ans, s, mid-1, key);
    }
    
}

int last_occurence(int* arr, int ans, int s, int e, int key)
{
    //Base case
    if(s>=e)
    {
        return ans;
    }

    //Recursive case
    int mid=(s+e)/2;
    if(arr[mid]==key)
    {
        ans=mid;
        return last_occurence(arr, ans, mid+1, e, key);
    }

    else if(arr[mid]<key)
    {
        return last_occurence(arr, ans, mid+1, e, key);
    }

    else
    {
        return last_occurence(arr, ans, s, mid-1, key);
    }
    
}


int main()
{
    int arr[]={1, 2, 3, 4, 7, 7, 7, 7};
    int n=sizeof(arr)/sizeof(int);
    cout << first_occurence(arr, 0, 0, n, 7) << endl;
    cout << last_occurence(arr, 0, 0, n, 7) << endl;
}