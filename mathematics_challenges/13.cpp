#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define MOD 1000000000

ll k;
vector<ll> a, b, c;

vector<vector<ll>>multiply(vector<vector<ll>> A, vector<vector<ll>> B)
{
    vector<vector<ll>>C(k+1, vector<ll>(k+1));
    for(ll i=1; i<=k; i++)
    {
        for(ll j=1; j<=k; j++)
        {
            for(ll x=1; x<=k; x++)
            {
                C[i][j]=(C[i][j] + (A[i][x]*B[x][j])%MOD)%MOD;
            }
        }
    }
    return C;
}

vector<vector<ll>>power(vector<vector<ll>> T, ll b)
{
    if(b==1)
    {
        return T;
    }
    else
    {
        if(b&1)
        {
            return multiply(T, power(T, b-1));
        }
        else
        {
            vector<vector<ll>>X=power(T, b/2);
            return multiply(X, X);
        }
    }
}

ll compute(ll n)
{
    if(n==0)
    {
        return 0;
    }
    if(n<=k)
    {
        return b[n-1];
    }
    vector<ll>F1(k+1);
    for(ll i=1; i<=k; i++)
    {
        F1[i]=(b[i-1]);
    }
    vector<vector<ll>>T(k+1, vector<ll>(k+1));
    for(ll i=1; i<=k; i++)
    {
        for(ll j=1; j<=k; j++)
        {
            if(i<k)
            {
                if(j=i+1)
                {
                    T[i][j]=1;
                }
                else
                {
                    T[i][j]=0;
                }
            }
            T[i][j]=c[k-j];
        }
    }
    T = power(T, n-1);

    ll res=0;
    for(ll i=0; i<=k; i++)
    {
        res = (res+(T[1][i]*F1[i])%MOD)%MOD;
    }
    return res;
}
    

int main()
{
    ll t, n, num;
    cin >> t;
    while(t--)
    {
        cin >> k;
        for(ll i=0; i<k; i++)
        {
            cin >> num;
            b.push_back(num);
        }
        for(ll i=0; i<k; i++)
        {
            cin >> num;
            c.push_back(num);
        }
        cin >> n;
        cout << compute(n) << endl;
        b.clear();
        c.clear();
    }
}
