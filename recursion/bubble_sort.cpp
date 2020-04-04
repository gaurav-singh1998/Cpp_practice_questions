#include<bits/stdc++.h>
using namespace std;

void bubble_sort(int arr[], int n) 
{ 
    // Base case 
    if (n == 1) 
        return; 
    for (int i=0; i<n-1; i++) 
        if (arr[i] > arr[i+1]) 
            swap(arr[i], arr[i+1]); 
    bubble_sort(arr, n-1); 
} 

int main()
{
    int arr[]={5, 4, 3, 2, 1};
    int n=sizeof(arr)/sizeof(int);
    bubble_sort(arr,n);
    for(int i=0; i<n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}