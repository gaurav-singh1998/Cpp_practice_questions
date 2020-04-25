//Point update and range query
//Spoj: invcnt

#include<bits/stdc++.h>
using namespace std;

int a[10000];
int BIT[10000];

void update(int i, int inc, int n)
{
    while(i<=n)
    {
        BIT[i] += inc;
        i += (i&(-i));
    }
}

int query(int i)
{
    int ans=0;
    while(i>0)
    {
        ans+=BIT[i];
        i -= (i&(-i));
    }
    return ans;
}

int main()
{
    int n; cin >> n;

    for(int i=1; i<=n; i++)
    {
        cin >> a[i];
    }

    int ans=0;
    for(int i=n; i>=1; i--)
    {
        ans += query(a[i]-1);
        update(a[i], 1, n);
    }
    cout << ans << endl;
}