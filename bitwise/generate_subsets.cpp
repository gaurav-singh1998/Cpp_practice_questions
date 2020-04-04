#include<bits/stdc++.h>
using namespace std;

//Time complexity is(2^n-1)*n; n = len(string)
void filterChars(string a, int no)
{
    ///a="abc" no=5 --Output should be ac;
    int i=0;
    while(no>0)
    {
        if((no&1))
        {
            cout << a[i];
        }
        else
        {
            cout << "";
        }
        i++;
        no=no>>1;
    }
    cout << endl;
}
void generateSubsets(string a)
{
    int n=a.length();
    int range=(1<<n)-1;
    for(int i=0; i<=range; i++)
    {
        filterChars(a, i);
    }
}

int main()
{
    string a;
    getline(cin, a);
    generateSubsets(a);
}
