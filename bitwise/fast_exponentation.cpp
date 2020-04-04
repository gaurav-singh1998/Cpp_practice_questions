#include<bits/stdc++.h>
using namespace std;

void fast_exponentiation(int a, int n)
{
    int ans=1;
    while(n>0)
    {
        if(n&1)
        {
            ans*=a;
        }
        a=a*a;
        n=(n>>1);
    }
    cout << ans << endl;
}

int main()
{
    int a, n;
    cin >> a >> n;
    fast_exponentiation(a, n);
}