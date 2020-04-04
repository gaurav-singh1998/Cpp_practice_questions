#include<bits/stdc++.h>
using namespace std;
int memo[1000];

int max_profit_with_memoization(int *prize_of_peice, int length)
{
    if (length==0) return 0;
    int best=0;
    if(memo[length]!=-1) return memo[length];

    for(int len=1; len<=length; len++)
    {
        int netProfit=prize_of_peice[len] + max_profit_with_memoization(prize_of_peice, length-len);
        best=max(best, netProfit);
    }
    memo[length] =best;
    return best;
}

int max_profit_bottom_up(int *prize_of_piece, int length)
{
    int dp[100]={};
    int best=0;
    for(int len=1; len<=length; len++)
    {
        for(int cut=1; cut<=len; cut++)
        {
            best = max(best, prize_of_piece[cut]+dp[len-cut]);
        }
        dp[len]=best;
    }
    return dp[length];
}

int max_profit(int *prize_of_peice, int length)
{
    if(length==0) return 0;
    int best=0;
    for(int len=1; len<=length; len++)
    {
        int netProfit=prize_of_peice[len] + max_profit(prize_of_peice, length-len);
        best=max(best, netProfit);
    }
    return best;
}

int main()
{
    int length;
    cin >> length;
    int prize_of_peice[length];
    memset(memo, -1, sizeof(memo));
    for(int i=1; i<=length; i++)
    {
        cin >> prize_of_peice[i];
    }
    cout << max_profit(prize_of_peice, length) << endl;
    cout << max_profit_with_memoization(prize_of_peice, length) << endl;
    cout << max_profit_bottom_up(prize_of_peice, length) << endl;
}