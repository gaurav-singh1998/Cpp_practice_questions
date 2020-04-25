#include<bits/stdc++.h>
using namespace std;
//Query works in log(n) and update also works in log(n)

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

//Sum till ith index
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
        update(i, a[i], n);
    }

    int q; cin >> q;
    while(q--)
    {
        int l, r; cin >> l >> r;
        cout << query(r) - query(l-1) << endl;
    }
}