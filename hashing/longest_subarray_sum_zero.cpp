#include<bits/stdc++.h>
using namespace std;


int main()
{
    int N; cin >> N;
    int *arr = new int[N];
    for(int i=0; i<N; i++)
    {
        cin >> arr[i];
    }
    unordered_map<int, int> mp;
    int pre=0;
    int len=0;
    for(int i=0; i<N; i++)
    {
        pre+=arr[i];
        if(arr[i]==0 && len==0) len=1;
        if(pre==0) len=max(len, i+1);
        if(mp.find(pre) != mp.end())
        {
            len=max(len, i-mp[pre]);
        }
        else
        {
            mp[pre]=i;
        }
        
    }
    cout << len << endl;
}
/**
6
0, -1, 1, 2, 5, -5
**/