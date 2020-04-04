#include<bits/stdc++.h>
using namespace std;

void tower_of_hanoi(int n, char src, char helper, char dest)
{
    //base case
    if(n==0) return;

    //recursive case
    tower_of_hanoi(n-1, src, dest, helper);
    cout << "Move " << n << " disk from " << src << " to " << dest << endl;
    tower_of_hanoi(n-1, helper, src, dest);
}


int main()
{
    int N;
    cin >> N;
    tower_of_hanoi(N, 'A', 'B', 'C');
    return 0;
}