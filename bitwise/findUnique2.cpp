#include<bits/stdc++.h>
using namespace std;

void findUnique2(int *a, int n)
{
    int res=0;
    for(int i=0; i<n; i++)
    {
        res=res^a[i];
    }
    int i=0;
    int temp=res;
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
    int secondNo=(res^firstNo);
    cout <<firstNo<< "  " << secondNo << endl;
}

int main()
{
    int a[] = {3,3,4,4,5,7,8,8,9,9};
    int n = sizeof(a)/sizeof(int);
    findUnique2(a, n);
}

