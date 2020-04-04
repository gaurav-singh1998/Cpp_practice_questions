#include<bits/stdc++.h>
using namespace std;

int checkPrime(int N)
{
    if (N==1) return 0;
    for(int i=2; i*i<=N; i++)
    {
        if(N%i == 1) return 0;
    }
    
    return 1;
}

int main()
{
    cout << checkPrime(36) << endl;
}