#include<bits/stdc++.h>
using namespace std;

int memo[100][100];

int max_profit_with_memoization(int *a, int s, int e, int year)
{
    if(s>e)
    {
        return 0;
    }
    if(memo[s][e]!=-1) return memo[s][e];
    int q1=(a[s]*year)+(max_profit_with_memoization(a, s+1, e, year+1));
    int q2=(a[e]*year)+(max_profit_with_memoization(a, s, e-1, year+1));
    memo[s][e]=max(q1, q2);
    int ans=max(q1, q2);
    return ans;
}

int max_profit_with_bottom_up(int *arr, int n)
{
    int dp[100][100]={};
    int year=n;

    for(int i=0; i<n; i++)
    {
        dp[i][i]=year*arr[i];
    }

    year--;
    for(int len=2; len<=n; len++)
    {
        int s=0;
        int e=n-len;
        while(s<=e)
        {
            int endWindow=s+len-1;
            dp[s][endWindow]=max(arr[s]*year + dp[s+1][endWindow],
             arr[endWindow]*year + dp[s][endWindow-1]);
            s++;
        }
        year--;
    }
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    return dp[0][n-1];
}

int max_profit_without_memoization(int *arr, int s, int e, int year)
{
    if(s>e)
    {
        return 0;
    }

    int q1=(arr[s]*year) + (max_profit_without_memoization(arr, s+1, e, year+1));
    int q2=(arr[e]*year) + (max_profit_without_memoization(arr, s, e-1, year+1));
    return max(q1, q2);
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    memset(memo, -1, sizeof(memo));
    for(int i=0; i<n; i++)
    {
        cin >> arr[i];
    }
    cout << max_profit_with_memoization(arr, 0, n-1, 1) << endl;
    cout << max_profit_without_memoization(arr, 0, n-1, 1) << endl;
    cout << max_profit_with_bottom_up(arr, n) << endl;
}
