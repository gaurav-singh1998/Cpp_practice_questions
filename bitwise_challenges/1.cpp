#include<bits/stdc++.h>
using namespace std;

int CountBits(int n)
{
    int count=0;
    while(n>0)
    {
        n=(n&(n-1));
        count++;
    }
    return count;
}

int Range(int a, int b)
{
    int i=0;
    for(int k=a; k<=b; k++)
    {
        i+=CountBits(k);
    }
    return i;
}

int main()
{
   int a, b;
   int query;
   cin >> query;
   for(int i=0; i<query; i++)
   {
       cin >> a >> b;
       cout << Range(a, b) << endl;
   }
}
