//https://www.codechef.com/problems/PRB01

#include<bits/stdc++.h>
using namespace std;



bool ifPrime(int num)
{
    if(num==1)
    {
        return false;
    }
    
    for(int i=2; i*i<=num; i++)
    {
        if(num%i==0)
        {
            return false;
        }
    }
    return true;
}



int main()
{
    int t; cin >> t;
    while(t--)
    {
        int num; cin >> num;
        if(ifPrime(num))
        {
            cout << "yes" << endl;
            continue;
        }
        cout << "no" << endl;
    }
}