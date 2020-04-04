#include<bits/stdc++.h>
using namespace std;

int findUniqueNo(int *a, int n)
{
    int *handler=new int[64]{0};
    for(int j=0; j<n; j++)
    {
        int i=0;
        int no=a[j];
        while(no>0)
        {
            handler[i] += (no&1);
            i++;
            no=no>>1;
        }
    }
    int p=1;
    int ans=0;
    for(int i=0; i<64; i++)
    {
        handler[i]%=3;
        ans += handler[i]*p;
        p=p<<1;
    }
    free(handler);
    return ans;
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
    cout << findUniqueNo(a, n) << endl;
}

