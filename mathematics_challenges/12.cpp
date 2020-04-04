#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD (1000000000+7)

ll n;

ll fib(ll n)
{
    if(n==0)
    {
        return 0;
    }
    else if(n==1 || n==2)
    {
        return 1;
    }
    else
    {
        ll res=0;
        vector<ll>F1(2);
        F1[0]=1; F1[1]=1;
         vector<vector<ll>>T({{0, 1},{1, 1}});
        for(ll i=n; i>1; i--)
        {
            ll m=(T[0][0]*F1[0])+(T[0][1]*F1[1]);
            ll n=(T[1][0]*F1[0])+(T[1][1]*F1[1]);
            F1[0]=m;
            F1[1]=n;
        }
        res=F1[0];
        res=(res%MOD);
        return res;
    }
}

int main()
{

    ll t;
    cin >> t;
    while(t--)
    {
        cin >> n;
        cout << fib(n) << endl;
    }
}
