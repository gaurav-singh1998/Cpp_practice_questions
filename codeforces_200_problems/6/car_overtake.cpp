
//look at the permutations
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int in[n+1], out[n+1];
    unordered_map<int, int>in_index;
    unordered_map<int, int>out_index;
    for(int i=1; i<=n; i++)
    {
        cin >> in[i];
        in_index[in[i]]=i;
    }
    for(int i=1; i<=n; i++)
    {
        cin >> out[i];
        out_index[out[i]]=i;
    }
    int j=0;
    for(int i=1; i<=n; i++)
    {
        if(in_index[in[i]]==out_index[in[i]])
        {
            j++;
        }
    }
    //cout << j << endl;
    if(j==n)
    {
        cout << 0 << endl;
    }
    else
    {
        int max=-1;
        int ans=0;
        for(int i=1; i<=n; i++)
        {
            if(out_index[in[i]]>max)
            {
                max=out_index[in[i]];
            }
            else
            {
                ans++;
            }
            
        }
        cout << ans << endl;
    }
    





/*
    //redundant delete later
    cout << "For in going: " << endl;
    for(int i=1; i<=n; i++)
    {
        cout << i << ": " << in_index[i] << endl;
    }
    cout << "For outgoing: " << endl;
    for(int i=1; i<=n; i++)
    {
        cout << i << ": " << out_index[i] << endl;
    }
    */
}