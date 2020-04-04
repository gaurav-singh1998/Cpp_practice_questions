#include<bits/stdc++.h>
using namespace std;

int exponentiation(int a, int b)
{
    //base case
    if(b==0)
    {
        return 1;
    }
    int ans=a*exponentiation(a, b-1);
    return ans;
    
}

int main()
{
    int a; int b;
    cin >> a >> b;
    cout << exponentiation(a, b) << endl;
}