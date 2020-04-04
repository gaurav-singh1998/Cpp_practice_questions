#include<bits/stdc++.h>
using namespace std;

void clear_last_i_bits(int &N, int i)
{
    int mask = (~0)<<i;
    N=N&mask;
    cout << N << endl;
}

void clear_range_of_bits(int &N, int i, int j)
{
    int mask1=(~0)<<(j+1);
    int mask2=(1<<i)-1;
    int mask=(mask1)|(mask2);
    N=N&mask;
    cout << N << endl;
}

int main()
{
    int N;
    int i;
    int j;
    cin >> N;
    cin >> i;
    cout << (~0) << endl;
    clear_last_i_bits(N, i);
    clear_range_of_bits(N, i, j);
}