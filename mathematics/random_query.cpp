#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll a[1000006]={0};
ll lastocc[1000006]={0};
ll ans[1000006]={0};

int main()
{
    ll n;
    cin >> n;
    for(ll i=1; i<=n; i++)
    {
        cin >> a[i];
    }
    memset(lastocc, 0, sizeof(lastocc));
    memset(ans, 0, sizeof(ans));
    ans[0]=0;
    double sum=0.0;
    for(ll i=0; i<=n; i++)
    {
        ans[i]=a[i-1]+(i-lastocc[a[i]]);
        lastocc[a[i]]=i;
        sum=sum+ans[i];
    }
    double finalAns=0.0;
    finalAns=(2*(sum-n)+n)/(n*n*1.0);
    cout << fixed << setprecision(6) << finalAns << endl;
}
