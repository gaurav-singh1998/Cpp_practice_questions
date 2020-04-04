#include<bits/stdc++.h>
using namespace std;


int main()
{
    int T;
    cin >> T;
    vector<string> ans(T);
    while(T--)
    {
        int N;
        int i;
        int z=0;
        int f=0;
        string a ="foo";
        cin >> N;
        queue<int> q;
        for(int j=0; j<N; j++)
        {
           cin >> i;
           q.push(i);
        }
        if(N<=6)
        {
            while(!q.empty())
            {
                int b = q.front();
                q.pop();
                if(b==1)
                {
                    z+=1;
                }
            }
            if (z>1) ans.push_back("NO");
            else ans.push_back("YES");
        }
        else
        {
            while(q.front() != 1)
            {
                q.pop();
                f++;
            }
            q.pop();
            f++;
            while(!q.empty())
            {
                int b = q.front();
                z+=1;
                q.pop();
                f++;
                if(b==1 && z<6)
                {
                    a="NO";
                    ans.push_back(a);
                    break;
                }
                else if(b==1 && z>=6)
                {
                    z=0;
                }
            }
            if(f == N && a=="foo")
            {
                ans.push_back("YES");
            }
        } 
    }
    for(string S: ans)
    {
       cout << S << endl;
    }
}