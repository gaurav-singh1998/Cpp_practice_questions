#include<bits/stdc++.h>
using namespace std;

string find_min_len(string str, string pat)
{
    int strlen = str.length();
    int pat_len = pat.length();
    if(strlen < pat_len)
    {
        cout << "No string" << endl;
        return "";
    }
    unordered_map<char, int>p;
    unordered_map<char, int>s;
    for(char x: pat)
    {
        p[x]++;
    }

    int start=0, start_index=-1, min_len=INT_MAX;
    int count=0;
    for(int j=0; j<strlen; j++)
    {
        s[str[j]]++;
        if(p[str[j]]!=0 && s[str[j]] <= p[str[j]])
        {
            count++;
        }
        if(count == pat_len)
        {
            while(s[str[start]]>p[str[start]] || p[str[start]] == 0)
            {
                if(s[str[start]] > p[str[start]])
                {
                    s[str[start]]--;
                }
                start++;
            }
            int len_window = j-start+1;
            if(min_len>len_window)
            {
                min_len=len_window;
                start_index=start;
            }
        }
    }

    if(start_index == -1)
    {
        cout << "No string" << endl;
        return "";
    }
    return str.substr(start_index, min_len);
}

int main()
{
    string str;
    string pat;
    getline(cin, str);
    getline(cin, pat);
    cout << find_min_len(str, pat) << endl;
}
