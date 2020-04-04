#include<bits/stdc++.h>
using namespace std;

int memo[1000];

int fib_with_memoization(int n)
{
    if(n==0) return 0;
    if(n==1) return 1;
    if(memo[n] != -1)
    {
        return memo[n];
    }
    int ans=fib_with_memoization(n-1)+fib_with_memoization(n-2);
    memo[n]=ans;
    return ans;
}
int fib_without_memoization(int n)
{
    if(n==0) return 0;
    if(n==1) return 1;
    int ans=fib_without_memoization(n-1) + fib_without_memoization(n-2);
    return ans;
}

int main()
{
    for(int i=0; i<=45; i++)
    {
        memo[i]=-1;
    }
    cout << fib_with_memoization(45) << endl;
    cout << fib_without_memoization(45) << endl;
}