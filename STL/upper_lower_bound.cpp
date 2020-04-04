#include<iostream>
using namespace std;

int lower_bound(int *a, int n, int key)
{
    int s=0, e=n-1;
    int ans, mid;
    while(s<=e)
    {
        mid=(s+e)/2;
        if(a[mid]==key)
        {
            ans=mid;
            e=mid-1;
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
    return ans;
}

int main()
{
    int a[]={1, 2, 2, 2, 3, 4, 4};
    cout << lower_bound(a, 7, 2) << endl;
}

