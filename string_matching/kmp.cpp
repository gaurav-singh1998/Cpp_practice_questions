#include<bits/stdc++.h>
#define MAX_N 100005
using namespace std;

int reset[MAX_N];
void KMPpreprocess(string pat)
{
    int i=0, j=-1;
    reset[0]=-1;

    while(i<pat.size())
    {
        //Check for resetting
        while(j>=0 && pat[i]!=pat[j])
        {
            j=reset[j];
        }
        i++;
        j++;
        reset[i]=j;
    }
}

void KMPSearch(string str, string pat)
{
    KMPpreprocess(pat);
    int i=0, j=0;
    while(i<str.size())
    {
        while(j>=0 && str[i] != pat[j])
        {
            j=reset[j];
        }
        i++;
        j++;
        if(j==pat.size())
        {
            cout << "Pattern is found at: " << i-j << endl;
            j=reset[j];
        }
    }
}


int main()
{
    for(int i=0; i < MAX_N; i++)
    {
        reset[i]=-1;
    }
    string str, pat;
    cin >> str >> pat;
    KMPSearch(str, pat);
}
