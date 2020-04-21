#include<bits/stdc++.h> 
using namespace std; 
  
string findSum(string str1, string str2) 
{
    if(str1.length() > str2.length())
    {
        swap(str1, str2);
    }

    int n1=str1.length(), n2=str2.length();
    string ans="";
    int diff=n2-n1;
    int carry=0;

    for(int i=n1-1; i>=0; i--)
    {
        int sum=(str1[i]-'0')+
                (str2[i+diff]-'0')+
                carry;
        
        carry=sum/10;
        ans+=sum%10 + '0';
    }

    for(int i=n2-n1-1; i>=0; i--)
    {
        int sum = ((str2[i]-'0')+carry); 
        ans+=(sum%10 + '0'); 
        carry = sum/10;
    }

    if(carry)
    {
        ans+=(carry+'0');
    }

    reverse(ans.begin(), ans.end());

    return ans;
}

int main()
{
    string s1, s2; cin >> s1 >> s2;
    cout << findSum(s1, s2) << endl;
}