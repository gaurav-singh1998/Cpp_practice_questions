#include<bits/stdc++.h>
using namespace std;

int fibonacci_with_bottom_up(int n)
{
    int *dp = new int[1000]{0};
    dp[0]=0;
    dp[1]=1;
    for(int i=2; i<=n; i++)
    {
        dp[i]=dp[i-1]+dp[i-2];
    }
    return dp[n];
}

int fibonacci_with_bottom_up_space_optimization(int n)
{
    int a=0;
    int b=1;
    int c;
    for(int i=2; i<=n; i++)
    {
        c=a+b;
        a=b;
        b=c;
    }
    return c;
}

int main()
{
    cout << fibonacci_with_bottom_up(45) << endl;
    cout << fibonacci_with_bottom_up_space_optimization(45) << endl;
}