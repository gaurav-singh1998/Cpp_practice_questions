#include<bits/stdc++.h>
using namespace std;

void merge(int *arr, int s, int e)
{
    int mid=(s+e)/2;
    int i=s, k=s, j=mid+1;
    int *temp=new int[100];

    while(i<=mid && j<=e)
    {
        if(arr[i]<=arr[j])
        {
            temp[k++]=arr[i++];
        }
        else
        {
            temp[k++]=arr[j++];
        }
    }
    while(i<=mid)
    {
        temp[k++]=arr[i++];
    }

    while(j<=e)
    {
        temp[k++]=arr[j++];
    }
    for(int i=s; i<=e; i++)
    {
        arr[i]=temp[i];
    }
}

void merge_sort(int* arr, int s, int e)
{
    //Base case
    if(s>=e)
    {
        return;
    }

    //Recursive case
    int mid=(s+e)/2;
    merge_sort(arr, s, mid);
    merge_sort(arr, mid+1, e);
    merge(arr, s, e);
}

int main()
{
    int arr[]={9, 8, 7, 5, 4};
    int n=sizeof(arr)/sizeof(int);
    merge_sort(arr, 0, n);
    for(int i=0; i<n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}