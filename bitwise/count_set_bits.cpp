#include<bits/stdc++.h>
using namespace std;

//Any number can have log(N)+1 bits at maximum; for eg:- 8 then log(8)+1=3 which is true.
//Long long int has (10)^18 digits. Log(10^18)==64 which is true for 64 bit system.


//time complexity = O(no of bits)
int countBits(int n)
{
    int count=0;
    while(n>0)
    {
        count+=(n&1);
        n=n>>1;
    }
    return count;
}
//time complexity = O(no of set bits)
int efficientCountBits(int n)
{
    int count=0;
    while(n>0)
    {
        n=n&(n-1);
        count++;
    }
    return count;
}


int main()
{
    //Calculating the difering bits in two numbers;
    int a, b;
    cin >> a >> b;
    int n = a^b;
    cout << countBits(n) << endl;
    cout << efficientCountBits(n) << endl;
    cout << __builtin_popcount(n) << endl;
}
