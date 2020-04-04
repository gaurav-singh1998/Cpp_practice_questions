#include<bits/stdc++.h> 
using namespace std;

void KswapPermutation(int arr[], int n, int k) 
{ 
    int pos[n+1]; 
  
    for (int i = 0; i < n; ++i) 
        pos[arr[i]] = i; 
  
    for (int i=0; i<n && k; ++i) 
    {
        if (arr[i] == n-i) 
            continue; 
        int temp = pos[n-i]; 
        pos[arr[i]] = pos[n-i]; 
        pos[n-i] = i; 
 
        swap(arr[temp], arr[i]); 
        --k; 
    } 
}

int main()
{
    int n, no_of_swaps;
    cin >> n >> no_of_swaps;
    int arr[n];
    for(int i=0; i<n; i++)
    {
        cin >> arr[i];
    }
    KswapPermutation(arr, n, no_of_swaps);
    for(int i=0; i<n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
