//https://online.codingblocks.com/app/player/30547/content/87834/5109/code-challenge
//Concept:- Large numbers

#include<bits/stdc++.h>
using namespace std;

string multiply(string num1, string num2) 
{ 
    int len1 = num1.size(); 
    int len2 = num2.size(); 
    if (len1 == 0 || len2 == 0) 
    return "0"; 
   
    vector<int> result(len1 + len2, 0); 
   
    int i_n1 = 0;  
    int i_n2 = 0;  

    for (int i=len1-1; i>=0; i--) 
    { 
        int carry = 0; 
        int n1 = num1[i] - '0'; 
  
        i_n2 = 0;
                  
        for (int j=len2-1; j>=0; j--) 
        { 
            int n2 = num2[j] - '0'; 
  
            int sum = n1*n2 + result[i_n1 + i_n2] + carry; 

            carry = sum/10; 
  
            result[i_n1 + i_n2] = sum % 10; 
  
            i_n2++; 
        } 
  
        if (carry > 0) 
            result[i_n1 + i_n2] += carry; 

        i_n1++; 
    } 
  
    int i = result.size() - 1; 
    while (i>=0 && result[i] == 0) 
    i--; 
  

    if (i == -1) 
    return "0"; 
  
    string s = ""; 
      
    while (i >= 0) 
        s += std::to_string(result[i--]); 
  
    return s; 
}

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

// Returns true if str1 is smaller than str2. 
bool isSmaller(string str1, string str2) 
{ 
    // Calculate lengths of both string 
    int n1 = str1.length(), n2 = str2.length(); 
  
    if (n1 < n2) 
    return true; 
    if (n2 < n1) 
    return false; 
  
    for (int i=0; i<n1; i++) 
    if (str1[i] < str2[i]) 
        return true; 
    else if (str1[i] > str2[i]) 
        return false; 
  
    return false; 
} 
  
// Function for find difference of larger numbers 
string findDiff(string str1, string str2) 
{ 
    // Before proceeding further, make sure str1 
    // is not smaller 
    if (isSmaller(str1, str2)) 
        swap(str1, str2); 
  
    // Take an empty string for storing result 
    string str = ""; 
  
    // Calculate length of both string 
    int n1 = str1.length(), n2 = str2.length(); 
  
    // Reverse both of strings 
    reverse(str1.begin(), str1.end()); 
    reverse(str2.begin(), str2.end()); 
      
    int carry = 0; 
  
    // Run loop till small string length 
    // and subtract digit of str1 to str2 
    for (int i=0; i<n2; i++) 
    { 
        // Do school mathematics, compute difference of 
        // current digits 
          
        int sub = ((str1[i]-'0')-(str2[i]-'0')-carry); 
          
        // If subtraction is less then zero 
        // we add then we add 10 into sub and 
        // take carry as 1 for calculating next step 
        if (sub < 0) 
        { 
            sub = sub + 10; 
            carry = 1; 
        } 
        else
            carry = 0; 
  
        str.push_back(sub + '0'); 
    } 
  
    // subtract remaining digits of larger number 
    for (int i=n2; i<n1; i++) 
    { 
        int sub = ((str1[i]-'0') - carry); 
          
        // if the sub value is -ve, then make it positive 
        if (sub < 0) 
        { 
            sub = sub + 10; 
            carry = 1; 
        } 
        else
            carry = 0; 
              
        str.push_back(sub + '0'); 
    } 
  
    // reverse resultant string 
    reverse(str.begin(), str.end()); 
  
    return str; 
} 

string fx(string x)
{
    string mul=multiply(x, x);
    string a=multiply("3", mul);

    string b=x;
    string c="10";
    string sub=findDiff(a, b);
    return findSum(sub, c);
}

string gx(string x)
{
    string mul=multiply(x, x);
    mul=multiply(mul, x);
    string a=multiply("4", mul);

    string b=multiply("2", multiply(x, x));
    string c=multiply("5", x);
    string d="4";

    string add=findSum(a, b);
    string sub=findDiff(add, c);
    return findSum(sub, "4");
}

string hx(string num)
{
    return findSum(fx(num), gx(num));
}

int main()
{
    string num;
    cin >> num;
    cout << hx(num) << endl;
}