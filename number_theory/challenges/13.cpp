//https://online.codingblocks.com/app/player/30547/content/87834/5047/code-challenge
//Concept:-Bitwise operators

#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ll n; cin >> n;
    ll *arr=new ll[n]{0};
    for(ll i=0; i<n; i++)
    {
        cin >> arr[i];
    }

    ll ans=0;
    for(ll i=0; i<n; i++)
    {
        ans=ans^arr[i];
    }

    ll temp=ans;
    ll mx=INT_MIN;
    for(ll i=0; i<n; i++)
    {
        ans=temp^arr[i];
        mx=max(mx, ans);
    }
    cout << mx << endl;
}