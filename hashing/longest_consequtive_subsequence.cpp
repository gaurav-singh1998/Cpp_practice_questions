#include<bits/stdc++.h>
using namespace std;

int longest_consequtive_subsequence(int *arr, int n)
{
    unordered_set<int> s;
    for(int i=0; i<n; i++)
    {
        s.insert(arr[i]);
    }
    int ans=0;
    for(int i=0; i<n; i++)
    {
        if(s.find(arr[i] - 1) != s.end())
        {
            continue;
        }

        else
        {
            int count=0;
            int x=arr[i];
            while(s.find(x) != s.end())
            {
                count++;
                x++;
            }
            ans=max(ans, count);
        }
        
    }

    return ans;
}

int main()
{
    int N; cin >> N;
    int *arr = new int[N];
    for(int i=0; i<N; i++)
    {
        cin >> arr[i];
    }

    int ans = longest_consequtive_subsequence(arr, N);
    cout << ans << endl;
}

/**
6
10 3 20 1 2 4
**/