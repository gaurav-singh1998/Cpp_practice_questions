#include<bits/stdc++.h>
using namespace std;
#define prime 119
#define ll long long

ll createHashFunction(string str, int n)
{
    ll result=0;
    for(int i=0; i<n; i++)
    {
        result+=(ll) (str[i] * (ll) (pow(prime, i)));
    }
    return result;
}

ll recalculateHash(string str, int oldIndex, int newIndex, ll oldHash, int patLength)
{
    ll newHash = oldHash - str[oldIndex];
    newHash/=prime;
    newHash += (ll) (str[newIndex] * (ll)(pow(prime, patLength-1)));

    return newHash;
}

bool checkEqual(string s1, string s2, int start1, int end1, int start2, int end2)
{
    if(end1-start1 != end2-start2)
    {
        return false;
    }

    while(start1<=end1 && start2<=end2)
    {
        if(s1[start1] != s2[start2])
        {
            return false;
        }
        start1++;
        start2++;
    }
    return true;
}

int main()
{
    string str="ababcabdab";
    string pat="abd";
    ll patHash = createHashFunction(pat, pat.length());
    ll strHash = createHashFunction(str, pat.length());
    
    for(int i=0; i<=str.length()-pat.length(); i++)
    {
        if(patHash==strHash && checkEqual(str, pat, i, i+pat.length()-1, 0, pat.length()-1))
        {
            cout << "Found at " << "index " << i << endl;
            break;
        }
        if(i<str.length()-pat.length())
        {
            strHash=recalculateHash(str, i, i+pat.length(), strHash, pat.length());
        }
    }

    return 0;
}