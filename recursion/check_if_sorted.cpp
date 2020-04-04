#include<bits/stdc++.h>
using namespace std;

bool isSorted(int *a, int N)
{
    if(N==1) return true;

    if(a[0]<a[1] && isSorted(a+1, N-1)) return true;
    else return false;
}

int main()
{
    int arr[]={1, 3, 7, 8, 9};
    cout << isSorted(arr, 5) << endl;
}