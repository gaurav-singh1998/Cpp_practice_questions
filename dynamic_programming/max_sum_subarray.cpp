#include<bits/stdc++.h>
using namespace std;

int max_sum_subarray(int *a, int n, int *dp)
{
    int max_sum_sofar=0;
    if(a[0]>0)
    {
        dp[0]=a[0];
    }
    for(int i=1; i<n; i++)
    {
        dp[i]=a[i]+dp[i-1];
        if(dp[i]<0)
        {
            dp[i]=0;
        }
        max_sum_sofar=max(max_sum_sofar, dp[i]);
    }
    for(int i=0; i<n; i++)
    {
        cout << dp[i] << " ";
    }
    cout << endl;
    return max_sum_sofar;
}

int max_sum_subarray_optimized(int *a, int n)
{
    int current_sum=0;
    int max_sum_sofar=0;
    for(int i=0; i<n; i++)
    {
        current_sum+=a[i];
        if(current_sum<0)
        {
            current_sum=0;
        }
        max_sum_sofar=max(current_sum, max_sum_sofar);
    }
    return max_sum_sofar;
}


int main()
{
    int a[8]={-2, 3, 4, 5, 6, 8, -28, 13};
    int *dp= new int[100]{0};
    cout << max_sum_subarray(a, 8, dp) << endl;
    cout << max_sum_subarray_optimized(a, 8) << endl;
}