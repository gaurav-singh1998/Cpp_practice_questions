//look at how numbers behave.
#include<bits/stdc++.h>
#define ll long long
using namespace std;

double max_profit(ll contestants)
{
    ll t=1;
    double ans=0.0;
    while(contestants)
    {
        ans+=((double)t/(double)contestants);
        contestants--;
    }
    return ans;
}

int main()
{
    ll contestants;
    cin >> contestants;
    cout << max_profit(contestants) << endl;
}