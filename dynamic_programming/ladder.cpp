#include<bits/stdc++.h>
using namespace std;

int number_of_ways(int n, int k, int *dp)
{
    if(n==0) return 1;
    if(dp[n]!=0) return dp[n];
    int ways=0;
    for(int i=1; i<=k; i++)
    {
        if(n-i>=0)
        {
            ways+=number_of_ways(n-i, k, dp);
        }
    }
    return dp[n]=ways;
}

int number_of_ways_bottom_up(int n, int k)
{
    int *dp=new int[100]{0};
    dp[0]=1;
    for(int i=1; i<=n; i++)
    {
        dp[i]=0;
        for(int j=1; j<=k; j++)
        {
            if(i-j>=0)
            {
                dp[i]+=dp[i-j];
            }
        }
    }
    for(int i=0; i<=n; i++)
    {
        cout << dp[i] << " ";
    }
    cout << endl;
    return dp[n];
}

int main()
{
    int n, k;
    cin >> n >> k;
    int *dp=new int[100]{0};
    cout << number_of_ways(n, k, dp) << endl;
    cout << number_of_ways_bottom_up(n, k) << endl;
}