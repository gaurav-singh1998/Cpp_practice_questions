#include<bits/stdc++.h>
using namespace std;

string bracket1="(";
string bracket2=")";

void generate_parenthesis(string bracket, int open, int close, int pos, int base)
{
    //Base case
    if(pos==(2*base))
    {
        if(open==close) cout << bracket << endl;
        else return;
    }
    //Recursive case
    cout << bracket << endl;
    if(open>close) generate_parenthesis(bracket+bracket2, open, close+1, pos+1, base);
    if(open<base) generate_parenthesis(bracket+bracket1, open+1, close, pos+1, base);
}


int main()
{
    int n;
    cin >> n;
    generate_parenthesis("", 0, 0, 0, n);
}