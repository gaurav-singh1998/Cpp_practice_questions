#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ll n;
    vector<ll> v;
    cin >> n;
    if(n>=130)
    {
        cout << "yes"<<endl;
    }
    else
    {
        for(int i=0; i<n; i++)
        {
            ll no;
            cin>>no;
            v.push_back(no);
        }
        for(ll i=0; i<n; i++)
        {
            for(ll j=i+1; j<n; j++)
            {
                for(ll k=j+1; k<n; k++)
                {
                    for(ll l=k+1; l<n; l++)
                    {
                        if((v[i]^v[j]^v[k]^v[l])==0)
                        {
                            cout << "yes" << endl;
                        }
                        else
                        {
                            cout << "no" << endl;
                        }
                    }
                }
            }
        }
    }
}
        
