#include<iostream>
using namespace std;

int SearchIn(int a[], int s, int e, int key)
{
    //Base case
    if(s>e)
    {
        return -1;
    }

    //rec case
    int mid=(s+e)/2;
    if(a[mid]==key)
    {
        return mid;
    }

    //mid lies in the first line
    if(a[s]<=a[mid])
    {
        if(key>=a[s] && key<=a[mid])
        {
            return SearchIn(a, s, mid-1, key);
        }
        else
        {
            return SearchIn(a, mid+1, e, key);
        }
        
    }
    //mid lies in the second line
    if(key>=a[mid]&& key<=a[e])
    {
        return SearchIn(a, mid+1, e, key);
    }
    return SearchIn(a, s, mid-1, key);
     
}

int main()
{
    int a[]={5, 6, 7, 1, 2, 3, 4};
    int key;
    cin >> key;
    cout << "Element found at index: " << SearchIn(a, 0, 6, key) << endl;
}
