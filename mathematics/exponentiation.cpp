#include<bits/stdc++.h>
using namespace std;

int power(int a, int b)
{
    if(b==0)
    {
        return 1;
    }
    int smallerAnswer = power(a, b/2);
    smallerAnswer *= smallerAnswer;
    if(b&1)
    {
        smallerAnswer *= a;
    }
    return smallerAnswer;
}

int main()
{
    int a, b;
    cin >> a >> b;
    cout << power(a, b) << endl;
}
