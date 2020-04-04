#include<iostream>
using namespace std;

int binary_search(int *a, int n, int key)
{
    int s=0; 
    int e=n-1;
    int mid;
    while(s<=e)
    {
        mid=(s+e)/2;
        if(a[mid]==key)
        {
            return mid;
            break;
        }
        else if(a[mid]>key)
        {
            e=mid-1;
        }
        else
        {
            s=mid+1;
        }
    }
    return -1;
}

int main()
{
    int a[]={1, 3, 6, 7, 10};
    cout << binary_search(a, 5, 10) << endl;
    cout << binary_search(a, 5, 11) << endl;
}
