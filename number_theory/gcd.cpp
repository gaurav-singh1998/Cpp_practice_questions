//a%b = a - std::floor(a/b)*b
//min vlaue of a%b = a-b
//see the time complexity derivation multiple times.
#include<bits/stdc++.h>
using namespace std;

int GCD(int a, int b)
{
    //terminating condition
    if(b==0) return a;

    //recursive condition
    return GCD(b, a%b);
}

int main()
{
    cout << GCD(12, 20) << endl;
    int lcm = 12*20/GCD(12, 20);
    cout << lcm << endl;
}