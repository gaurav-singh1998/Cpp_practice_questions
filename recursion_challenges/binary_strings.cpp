#include<bits/stdc++.h>
using namespace std;
//Here since we have to remember the past state so we have to make use of dp.

int generate_binary_strings(int n)
{
    int dp[n+1][2]={0};
    //Base case
    dp[1][0]=1;
    dp[1][1]=1;
    //recursive case
    for(int i=2; i<=n; i++)
    {
        dp[i][0]=dp[i-1][0]+dp[i-1][1];
        dp[i][1]=dp[i-1][0];
    }
    return dp[n][0]+dp[n][1];
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        cout << generate_binary_strings(n) << endl; 
    }
}