#include<bits/stdc++.h>
using namespace std;

void findUnique2(int *a, int n)
{
    int res=0;
    for(int i=0; i<n; i++)
    {
        res=res^a[i];
    }
    int temp=res;
    int i=0;
    while(temp>0)
    {
        if(temp&1)
        {
            break;
        }
        i++;
        temp=temp>>1;
    }
    int mask=(1<<i);
    int firstNo=0;
    for(int i=0; i<n; i++)
    {
        if((mask&a[i])!=0)
        {
            firstNo=firstNo^a[i];
        }
    }
    int secondNo=res^firstNo;
    if(secondNo>firstNo)
    {
        cout << firstNo << " " << secondNo << endl;
    }
    else
    {
        cout << secondNo << " " << firstNo << endl;
    }
}

int main()
{
    int n;
    cin >> n;
    int a[n];
    for(int i=0; i<n; i++)
    {
        cin >> a[i];
    }
    findUnique2(a, n);
}
