#include<iostream>
using namespace std;
const int inf = (int)1e9;
int memo[1000];
int reduce_to_one_with_memoization(int n)
{
    if(n==1) return 0;
    int q1=inf, q2=inf, q3=inf;
    if(memo[n]!=-1) return memo[n];
    if(n%3==0) q1=1+reduce_to_one_with_memoization(n/3);
    if(n%2==0) q2=1+reduce_to_one_with_memoization(n/2);
    q3=1+reduce_to_one_with_memoization(n-1);
    memo[n]=min(q1, min(q2, q3));
    return memo[n];
}

int reduce_to_one_with_bottom_up(int n)
{
    int dp[10000];
    dp[0]=0, dp[1]=0, dp[2]=1, dp[3]=1;
    for(int i=4; i<=n; i++)
    {
        int q1=inf;
        int q2=inf;
        int q3=inf;
        if(i%3==0)q1=1+dp[i/3];
        if(i%2==0)q2=1+dp[i/2];
        q3=1+dp[i-1];
        dp[i]=min(q1, min(q2, q3));
    }
    return dp[n];
}

int reduce_to_one_without_memoization(int n)
{
    if(n==1) return 0;
    int q1=inf, q2=inf, q3=inf;

    if(n%3==0) q1=1+reduce_to_one_without_memoization(n/3);
    if(n%2==0) q2=1+reduce_to_one_without_memoization(n/2);
    q3=1+reduce_to_one_without_memoization(n-1);

    return min(q1, min(q2, q3)); 
}

int main()
{
    fill(memo, memo+1001, -1);
    cout << reduce_to_one_with_bottom_up(1000) << endl;
    cout << reduce_to_one_with_memoization(1000) << endl;
    cout << reduce_to_one_without_memoization(1000) << endl;
}