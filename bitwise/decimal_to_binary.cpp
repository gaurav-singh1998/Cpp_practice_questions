#include<bits/stdc++.h>
using namespace std;

void decimal_to_binary(int &N)
{
    int ans=0;
    int p=1;
    while(N>0)
    {
        if(N&1)
        {
            ans+=1*p;
        }
        else
        {
           ans+=0*p;
        }
        N=(N>>1);
        p*=10;
    }
    cout << ans << endl;
}

int main()
{
    int N;
    cin >> N;
    decimal_to_binary(N);
}