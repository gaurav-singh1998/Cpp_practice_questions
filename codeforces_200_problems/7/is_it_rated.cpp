#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n], b[n];
    int j=0;
    for(int i=0; i<n; i++)
    {
        cin >> a[i] >> b[i];
        if(a[i]==b[i])
        {
            j++;
        }
    }
    if(j!=n)
    {
        cout << "rated" << endl;
    }
    else
    {
        int k=0;
        for(int i=0; i<n-1; i++)
        {
            for(int j=i+1; j<n; j++)
            {
                if(a[i]<a[j])
                {
                    k++;
                }
            }
        }
        if(k!=0)
        {
            cout << "unrated" << endl;
        }
        else
        {
            cout << "maybe" << endl;
        }
    }
}