#include<bits/stdc++.h>
using namespace std;

int min_coins_required(int n, int *coins, int T, int *dp)
{
    if(n==0)
    {
        return 0;
    }
    if(dp[n]!=0)
    {
        return dp[n];
    }
    int ans=INT_MAX;
    for(int i=0; i<T; i++)
    {
        if(n-coins[i]>=0)
        {
            int subprob=min_coins_required(n-coins[i], coins, T, dp);
            ans=min(ans, subprob);
        }
    }
    dp[n]=ans+1;
    return ans+1;
}

int min_coins_bottom_up(int N, int *coins, int T)
{
    int *dp=new int[100]{0};
    for(int n=1; n<=N; n++)
    {
        dp[n]=INT_MAX;
        for(int i=0; i<T; i++)
        {
            if(n-coins[i]>=0)
            {
                int subproblem=dp[n-coins[i]];
                dp[n]=min(dp[n], subproblem+1);
            }
        }
    }
    return dp[N];
}


int main()
{
    int input=15;
    int coins[]={1, 7, 10};
    int *dp=new int[100]{0};
    cout << min_coins_required(15, coins, 3, dp) << endl;
    cout << min_coins_bottom_up(15, coins, 3) << endl;
}