#include<bits/stdc++.h>
using namespace std;

int multiply(int a, int b)
{
    //base_case
    if(b==0)
    {
        return 0;
    }
    //recursive_cases
    else if(a<b)
    {
        return multiply(b, a);
    }
    else if(a<0 && b<0)
    {
        int x=abs(a);
        int y=abs(b);
        return multiply(x, y);
    }
    else if(a<0 || b<0)
    {
        int x=abs(a);
        int y=abs(b);
        return -(multiply(x, y));
    }
    else
    {
        return a+multiply(a, b-1);
    }
    
    
}

int main()
{
    int a; int b;
    cin >> a >> b;
    cout << multiply(a, b) << endl;
}