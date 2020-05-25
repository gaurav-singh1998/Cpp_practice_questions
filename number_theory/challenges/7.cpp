//https://online.codingblocks.com/app/player/30547/content/87834/5106/code-challenge
//Concept:-Counting divisors
#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long

int main()
{
    ll t; cin >> t;
    while(t--)
    {
        ll j; cin >> j;
        ll* arr=new ll[j];
        map<ll, ll> div_cnt;
        for(ll i=0; i<j; i++)
        {
            cin >> arr[i];
        }

        for(ll i=0; i<j; i++)
        {
            ll temp=arr[i];

            for(ll j=2; j*j<=temp; j++)
            {
                if(temp%j==0)
                {
                    ll cnt=0;
                    while(temp%j==0)
                    {
                        cnt+=1;
                        temp=temp/j;
                    }
                    div_cnt[j]+=(cnt);
                }
            }
            if(temp!=1)
            {
                div_cnt[temp]+=1;
            }
        }
        ll res=1;
        for(auto elem: div_cnt)
        {
            res=(res*(elem.second+1))%mod;
        }
        cout << res%mod << endl;
    }
}