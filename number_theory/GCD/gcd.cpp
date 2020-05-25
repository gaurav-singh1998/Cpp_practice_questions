//Proof is important
#include<bits/stdc++.h>
using namespace std;


int GCD(int a, int b)
{
    //Base case
    if(b==0)
    {
        return a;
    }

    //Recursive case
    return GCD(b, a%b);
}

int LCM(int a, int b)
{
    return a*b/GCD(a, b);
}

int main()
{
    int a, b; cin >> a >> b;
    cout << GCD(a, b) << endl;
    cout << LCM(a, b) << endl;
    cout << __gcd(a, b) << endl;
}