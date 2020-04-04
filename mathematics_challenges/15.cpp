#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD (1000000000+7)

vector<vector<ll>>multiply(vector<vector<ll>> A, vector<vector<ll>> B)
{
    vector<vector<ll>>C({{0, 0}, {0, 0}});
    for(int i=0; i<2; i++)
    {
        for(int j=0; j<2; j++)
        {
            for(int x=0; x<2; x++)
            {
                C[i][j]=(C[i][j]+(A[i][x]*B[x][j])%MOD)%MOD;
            }
        }
    }
    return C;
}

vector<vector<ll>> power(vector<vector<ll>> A, ll n)
{
    if(n==1)
    {
        return A;
    }
    else
    {
        if(n&1)
        {
            return multiply(A, power(A, n-1));
        }
        else
        {
            vector<vector<ll>>X=power(A, n/2);
            return multiply(X, X);
        }
    }
}

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
        vector<ll>F1({1, 1});
        vector<vector<ll>>T({{0, 1}, {1, 1}});
        T=power(T, n-1);
        ll res=0;
        res=(res%MOD);
        res=(T[0][0]*F1[0])+(T[0][1]*F1[1]);
        return res;
    }
}

int main()
{
    ll t;
    cin >> t;
    while(t--)
    {
        ll n; ll m;
        cin >> n; cin >> m;
        ll res=0;
	//sum from fib(n) to fib(m) is fib(m+2)-fib(n+1)
        res+=(fib(m+2)-fib(n+1));
        res=(res%MOD+MOD)%MOD;
        cout << res << endl;
    }
}
