#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ll t;
    cin >> t;
    for(ll i=0; i<t; i++)
    {
        ll n, s, k;
        cin >> n >> s >> k;
        ll closed_restaurants[k];
        for(ll i=0; i<k; i++)
        {
            cin >> closed_restaurants[i];
        }
        sort(closed_restaurants, closed_restaurants+k);
        if(binary_search(closed_restaurants, closed_restaurants+k, s)==false)
        {
            cout << 0 << endl;
        }
        else
        {
            ll up, down, steps_up, steps_down;
            for(int up=(s+1); up<=n; up++)
            {
                if(binary_search(closed_restaurants, closed_restaurants+k, up)==false)
                {
                    steps_up=abs(up-s);
                    break;
                }
                else
                {
                    continue;
                }
                
            }
            for(int down=(s-1); down>=1; down--)
            {
                if(binary_search(closed_restaurants, closed_restaurants+k, down)==false)
                {
                    steps_down=abs(down-s);
                    break;
                }
                else
                {
                    continue;
                }
                
            }
            cout << min(steps_up, steps_down) << endl;
        }
        
    }
}