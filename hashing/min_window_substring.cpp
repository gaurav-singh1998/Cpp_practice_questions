#include<bits/stdc++.h>
using namespace std;


void min_window_substring(string s1, string s2)
{
    int len1 = s1.size(); int len2 = s2.size();

    if(len1 < len2) cout << "Not Possible." << endl;

    int hash_str[256]={0}; int hash_ptr[256]={0};

    for(int i=0; i<len2; i++)
    {
        hash_ptr[s2[i]] += 1;
    }

    int start=0; int start_index=-1; int min_len=INT_MAX; int count=0;
    for(int i=0; i<s1.size(); i++)
    {
        hash_str[s1[i]]+=1;
        if(hash_ptr[s1[i]] != 0 && hash_str[s1[i]] <= hash_ptr[s1[i]])
        {
            count++;
        }
        if(count == len2)
        {
            while(hash_str[s1[start]] > hash_ptr[s1[start]] || hash_ptr[s1[start]]==0)
            {
                if(hash_str[s1[start]] > hash_ptr[s1[start]])
                {
                    hash_str[s1[start]] -= 1;
                }
                start++;
            }

            int len_window = i-start+1;
            if(min_len > len_window)
            {
                min_len = len_window;
                start_index=start;
            }
        }
    }
    if(start_index==-1) cout << "Not Possible" << endl;
    cout << s1.substr(start_index, min_len) << endl;
}

int main()
{
    string s1, s2; cin >> s1 >> s2;
    min_window_substring(s1, s2);
}