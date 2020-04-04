//take care of indices even though the logic is correct

#include<bits/stdc++.h>
#define ll long long
using namespace std;

bool canbeEqual(ll *a, ll *b, ll size)
{
    int ans=0;
    int i;
    for(i=1; i<=size; i++)
    {
        if(a[i]==b[i])
        {
            ans+=1;
        }
        else
        {
            break;
        }
    }
    if(ans==size)
    {
        return true;
    }
    else
    {
        if(a[i]<b[i])
        {
            int k=b[i]-a[i];
            for(int j=i; j<=size; i++)
            {
                if(a[i]!=b[i])
                {
                    if((a[i]+k)==b[i])
                    {
                        ans+=1;
                    }
                    else
                    {
                        break;
                    }
                }
                else
                {
                    ans+=1;
                }
                cout <<"Index: " << i << endl;
            }
            cout << "Ans: " << ans << endl;
            if(ans==size)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            return false;
        }
        
    }
    
}


int main()
{
    ll t;
    cin >> t;
    for(ll i=0; i<t; i++)
    {
        ll size;
        cin >> size;
        ll a[size+1];
        ll b[size+1];
        for(ll i=1; i<=size; i++)
        {
            cin >> a[i];
        }
        for(ll i=1; i<=size; i++)
        {
            cin >> b[i];
        }
        bool ans=canbeEqual(a, b, size);
        if(ans)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
        
    }
}