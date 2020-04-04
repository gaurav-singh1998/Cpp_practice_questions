#include<bits/stdc++.h>
#define ll long long
using namespace std;

bool isValidConfig(ll books[], ll n, ll k, ll ans)
{
    ll student=1;
    ll current_pages=0;
    for(ll i=0; i<n; i++)
    {
        if(current_pages+books[i]>ans)
        {
            current_pages=books[i];
            student++;
            if(student>k)
            {
                return false;
            }
        }
        else
        {
            current_pages += books[i];
        }
    }
    return true;
}


ll binarysearchBooks(ll books[], ll n, ll k)
{
    ll total_pages=0;
    ll s=0, e=0;
    for(ll i=0; i<n; i++)
    {
        total_pages+=books[i];
        s=max(s, books[i]);
    }
    e=total_pages;
    ll finalAns=0;
    while(s<=e)
    {
        ll mid=(s+e)/2;
        if(isValidConfig(books, n, k, mid))
        {
            finalAns=mid;
            e=mid-1;
        }
        else
        {
            s=mid+1;
        }

    }
    return finalAns;
}    

int main()
{
    ll n, k;
    cin >> n >> k;
    
    ll books[100005];
    for(int i=0; i<n; i++)
    {
        cin >> books[i];
    }
    cout << binarysearchBooks(books, n, k) << endl;
}
