#include<bits/stdc++.h>
using namespace std;
#define ll long long

typedef pair<ll, ll> ii;

int main()
{
    ll T;
    cin >> T;
    while(T--)
    {
        ll n; cin >> n;
        vector<ii> pos;
        pos.push_back(ii(-1, 0));
        pos.push_back(ii(-1, 0));
        for (int i = 0; i < n; i++)
        {
            ll x; cin >> x;
            x = fabs(x);
            if (x % 4 == 2) pos.push_back(ii(i, 1));
            else if (x % 4 == 0) pos.push_back(ii(i, 0));
        }
        pos.push_back(ii(n, 0));
        ll res = n * (n + 1);
        res /= 2LL;
        ll len = pos.size();
        for (ll i = 1; i < len - 1; i++) {
            if (pos[i].second == 0) continue;
            ll tmp = (pos[i].first - pos[i - 1].first);
            tmp *= (pos[i + 1].first - pos[i].first);
            res -= tmp;
        }
        cout << res << '\n';
    }
}