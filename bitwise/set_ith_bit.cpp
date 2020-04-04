#include<bits/stdc++.h>
using namespace std;

void set_ith_bit(int &n, int i)
{
    int x=1;
    x= x<<i;
    n=n|x;
}

int main()
{
    int n; cin>>n;
    int pos; cin >> pos;
    cout << n << endl;
    set_ith_bit(n, pos);
    cout << n << endl;
}

