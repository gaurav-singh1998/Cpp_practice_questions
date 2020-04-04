#include<bits/stdc++.h>
using namespace std;

//You are given  two 32 bits numbers, N and M and two bit positions i and j
//Write a method to set all  bits between  i and j in N equal to M.

// Example
// Input : N=100000000;
// M=10101, i=2, j=6
// Output : N=101010100

void replace_N_with_M(int &N, int &M, int i, int j)
{
    int mask1=(~0)<<(j+1);
    int mask2=(1<<i)-1;
    int mask=(mask1)|(mask2);
    int N_=N&(mask<<i);
    int ans=N_|M;
    cout << ans << endl;
}

int main()
{
    int N, M, i, j;
    cin >> N >> M >> i >> j;
    replace_N_with_M(N, M, i, j);
}