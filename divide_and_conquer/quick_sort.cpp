#include<bits/stdc++.h>
using namespace std;


int getPivot(int* arr, int s, int e)
{
    int i=s-1;
    int pivot=arr[e];
    for(int j=s; j<e; j++)
    {
        if(arr[j]<pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1], arr[e]);
    return i+1;
}


void quick_sort(int* arr, int s, int e)
{
    //Base case
    if(s>=e)
    {
        return;
    }

    //Recursive case
    int pivot=getPivot(arr, s, e);
    quick_sort(arr, s, pivot-1);
    quick_sort(arr, pivot+1, e);
}


int main()
{
    int arr[]={9, 8, 7, 6, 4};
    int n=sizeof(arr)/sizeof(int);
    quick_sort(arr, 0, n-1);
    for(int i=0; i<n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}