#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int s[n];
    for(int i=0; i<n; i++)
    {
        cin >> s[i];
    }
    int z=0;
    for(int i=0; i<n; i++)
    {
        for(int j=i; j<n; j++)
        {
            vector<int>ss;
            for(int k=i; k<=j; k++)
            {
                ss.push_back(s[k]);
            }
	    sort(ss.begin(), ss.end());
            auto it = unique(ss.begin(), ss.end());
            if(it == ss.end())
            {
                z+=ss.size();
            }
        }        
    }
    cout << z <<  endl;
}
