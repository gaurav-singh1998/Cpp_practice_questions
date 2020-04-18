#include<bits/stdc++.h>
using namespace std;

void NaiveSearch(string str, string pat)
{
    for(int i=0; i<=str.size()-pat.size(); i++)
    {
        int j;
        for(j=0; j<pat.size(); j++)
        {
            if(str[i+j]!=pat[j])
            {
                break;
            }
        }
        if(j==pat.size())
        {
            cout << "Pattern is found at: " << i << endl;
        }
    }
    //cout << "Pattern is not found." << endl;
}

int main()
{
    string str, pat; cin >> str >> pat;
    NaiveSearch(str, pat);
}