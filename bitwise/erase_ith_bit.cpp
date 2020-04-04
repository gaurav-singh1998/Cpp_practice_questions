#include<iostream>
using namespace std;

void earse_ith_bit(int &n, int i)
{
    int x=1;
    x=x<<i;
    x=~(x);
    n=n&x;
}

int main()
{
    int n; cin >> n;
    int pos; cin>>pos;
    cout << n << endl;
    earse_ith_bit(n, pos);
    cout << n << endl;
}
