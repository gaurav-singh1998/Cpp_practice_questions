#include<bits/stdc++.h>
using namespace std;

int getting_the_ith_bit(int n, int i)
{
    int x=1;
    x=x<<i;
    if((n&x))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    int n; cin >> n;
    int position; cin >> position;
    cout << getting_the_ith_bit(n, position) << endl;
}
