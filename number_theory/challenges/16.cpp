#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
 
ll calcProgression(ll a, ll d, ll n) {
    return ((2 * a) + (d * (n - 1))) * n / 2;
}
 
void run() 
{
    int a, b, c, d; cin >> a >> b >> c >> d;
 
    ll ans = 0;
    for (int z = c; z <= d; ++z) 
    {
        int minX = std::max(a, z - c + 1);
        cout << "minX: " << minX << endl;
        if (minX > b) 
        {
            continue;
        }
 
        int mid = z - b + 1;
        cout << "mid: " << mid << endl;
       // int start = c - std::max(b, z - minX + 1) + 1;
 
        if (mid <= minX) 
        {
            ans += 1ll * (c - b + 1) * (b - minX + 1);
        } 
        else if (mid > b) 
        {
            ans += calcProgression(start, 1, b - minX + 1);
        }
        else 
        {
            ans += calcProgression(start, 1, mid - minX + 1);
            ans += 1ll * (b - mid) * (c - b + 1);
        }
    }    
 
    cout << ans << endl;
}
 
int main()
{
    run();
}