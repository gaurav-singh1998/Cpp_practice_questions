#include<bits/stdc++.h>
using namespace std;

void XOR_swapping(int &a, int &b)
{
    a = a^b;
    b = b^a;
    a= a^b;
}
int main()
{
    int a, b; cin >> a >> b;
    cout << "Before Swapping: " << a << " " << b << endl;
    XOR_swapping(a, b);
    cout << "After Swapping: " << a << " " << b << endl;
}

