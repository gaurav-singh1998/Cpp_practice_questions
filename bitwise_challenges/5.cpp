#include<bits/stdc++.h>
using namespace std;
void getinput(vector<int> &p, vector<int> &q)
{
    string buffer_p;
    cin >> buffer_p;
    int x=buffer_p.length();
    for(int i=0; i<x; i++)
    {
        int z=(int)buffer_p[i];
        if(z==48)
        {
            p.push_back(0);
        }
        else
        {
            p.push_back(1);
        }
    }
    string buffer_q;
    cin >> buffer_q;
    int d=buffer_q.length();
    for(int i=0; i<d; i++)
    {
        int z=(int)buffer_q[i];
        if(z==48)
        {
            q.push_back(0);
        }
        else
        {
            q.push_back(1);
        }
    }
    vector<int>r;
    for(int i=0; i<d; i++)
    {
        int z=p[i]^q[i];
        r.push_back(z);
    }
    for(int x: r)
    {
        cout << x;
    }
    cout << endl;
    p.clear();
    q.clear();
}
int main()
{
    int t;
    cin >> t;
    while(t--)
    {    
        vector<int>p;
        vector<int>q;
        getinput(p, q);
    }

}
