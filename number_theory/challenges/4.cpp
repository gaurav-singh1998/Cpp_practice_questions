//https://online.codingblocks.com/app/player/30547/content/87834/5159/code-challenge
//Concept:-factorization
//We can also check if the sqrt(array num) are prime or not because only square of prime numbers have three divisors
#include<bits/stdc++.h>
#define ll long long
using namespace std;


int main()
{
    int n; cin >> n;
    ll *arr=new ll[n];
    for(ll i=0; i<n; i++)
    {
        cin >> arr[i];
    }

    for(ll i=0; i<n; i++)
    {
        ll cnt=2;
        for(ll j=2; j*j<=arr[i]; j++)
        {
            if(arr[i]%j==0)
            {
                if(j*j!=arr[i])
                {
                    cnt+=2;
                }
                else
                {
                    cnt+=1;
                }
                
            }
        }
        if(cnt == 3)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
        
    }
}