#include<bits/stdc++.h>
using namespace std;

void merge(int *arr, int s, int m, int e)
{
    int n1=m-s+1;
    int n2=e-m;
    int L[n1], R[n2];
    for(int i=0; i<n1; i++)
    {
        L[i]=arr[s+i];
    }
    for(int q=0; q<n2; q++)
    {
        R[q]=arr[m+q+1];
    }
    int i=0, j=0, k=s;
    while(i<n1 && j<n2)
    {
        if(L[i]<=R[j])
        {
            arr[k]=L[i];
            i++;
        }
        else
        {
            arr[k]=R[j];
            j++;
        }
        k++;
    }
    while(i<n1)
    {
        arr[k]=L[i];
        i++;
        k++;
    }
    while(j<n2)
    {
        arr[k]=R[j];
        j++;
        k++;
    }
}

void merge_sort(int *A, int p, int r)
{
    if(r<=p) return;
    int q=(p+r)/2;
    merge_sort(A, p, q);
    merge_sort(A, q+1, r);
    merge(A, p, q, r);
}

int main()
{
    int arr[]={5, 4, 3, 2, 1};
    merge_sort(arr, 0, 5);
    for(int i=0; i<5; i++)
    {
        cout << arr[i] << endl;
    }
}