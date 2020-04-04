#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<long> a(n);
    for(auto &i : a)
        cin >> i;
    long maxSum = 0;
    vector<long> dp = a;
    for(int i=0; i<n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    for(int i=0; i<n; i++)
    {
        cout << dp[i] << " ";
    }
    cout << endl;
    for(int i = k; i < n; i += k) {
        int max_i = i - k, smax_i = -1;
        //cout << dp[i] << endl;
        for(int j = i - k + 1; j < i; j++) {
            cout << dp[j] << " " << dp[max_i] << endl;
            if(dp[j] > dp[max_i]) {
                smax_i = max_i;
                max_i = j;
            }
            else if(smax_i == -1 or dp[j] > dp[smax_i]) {
                smax_i = j;
            }
        }
        cout << max_i <<" "<< smax_i << endl;
        cout << dp[smax_i] << endl;
        cout << endl;
        for(int j = i; j < i + k and j < n; j++) {
			if(a[j] < 0) {dp[j] = dp[max_i]; cout << "True1" << endl;}
            else if(j - max_i != k) {dp[j] = a[j] + dp[max_i]; cout << "True2" << endl;}
            else {dp[j] = a[j] + dp[smax_i];cout <<dp[smax_i] << endl; cout << "True3" << endl;}
            maxSum = max(maxSum, dp[j]);
        }
    }
    for(auto &i: dp)
    {
        cout << dp[i] << " ";
    }
    cout << endl;
    cout << maxSum << endl;
}