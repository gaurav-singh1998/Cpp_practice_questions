#include<bits/stdc++.h>
using namespace std;
int cnt;

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
            cnt+=mid-i+1;
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
    int arr[]={1, 5, 2, 6, 3, 0};
    int n=sizeof(arr)/sizeof(int);
    merge_sort(arr, 0, n);
    cout << cnt << endl;
}