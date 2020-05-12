#include<iostream>
using namespace std;

int main()
{
    int a[]={6, 7, 1, 2, 3, 4, 5};
    int n=sizeof(a)/sizeof(int);
    int s=0;
    int e=n-1;
    int mid;
    while(s<=e)
    {
        mid=(s+e)/2;
        if(mid<e && a[mid]>a[mid+1])
        {
            cout << mid << endl;
            break;
        }
        if(mid>s && a[mid]<a[mid-1])
        {
            cout << mid-1 << endl;
            break;
        }
        if(a[s]>=a[mid])
        {
            e=mid-1;
        }
        else
        {
            s=mid+1;
        }
        
    }
    if(s>e)
    {
        cout << "Pivot does not exist" << endl;
    }
}