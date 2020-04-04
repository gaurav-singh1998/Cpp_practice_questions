#include<bits/stdc++.h>
using namespace std;

bool compare(int a, int b)
{
    cout << "Compare " << a << " and " << b << endl; 
    return a>b;
}
int main()
{
    int a[5] = {5, 4, 3, 2, 1};
    int n = sizeof(a)/sizeof(int);
    sort(a, a+n);//in ascending order
    for(int x: a)
    {
        cout << x << endl;
    }
    // Remember sort function uses the idea of iterator in which the last point is always excluded.
    sort(a, a+n, compare); //in descending order
    for(int x: a)
    {
        cout << x << endl;
    }
}
