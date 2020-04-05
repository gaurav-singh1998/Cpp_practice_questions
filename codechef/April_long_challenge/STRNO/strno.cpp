#include <bits/stdc++.h> 
#define ll long long
using namespace std; 

int main()
{
    ll T;
    cin >> T;
    while(T--)
    {
        ll X, K;
        cin >> X >> K;
        ll count = 0;
        while(X%2 == 0)
        {
            X=X/2;
            count++;
        }
        for(ll i=3; i*i<=X; i++)
        {
            while(X%i == 0)
            {
                X=X/i;
                count++;
            }
        }
        if(X>2) ++count;
        if(count<K) cout << "0" << endl;
        else cout << "1" << endl;
    }
}