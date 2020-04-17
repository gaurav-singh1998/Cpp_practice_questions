#include<bits/stdc++.h>
using namespace std;


int main()
{
    int N;
    cin >> N;
    int *arr = new int[N];
    for(int i=0; i<N; i++)
    {
        cin >> arr[i];
    }
    int k; cin >> k;
    unordered_map<int, int> mp;
    int pre=0;
    int len=0;
    for(int i=0; i<N; i++)
    {
        pre+=arr[i];
        if(pre == k) len=max(len, i+1);
        if(mp.find(pre-k) != mp.end())
        {
            len = max(len, i-mp[pre - k]);
        }
        else
        {
            mp[pre] = i;
        }
        
    }
    cout << len << endl;
}