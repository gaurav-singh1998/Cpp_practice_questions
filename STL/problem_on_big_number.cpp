#include<iostream>
using namespace std;

void multiply(int *arr, int &n, int number)
{
    int carry=0;
    for(int i=0; i<n; i++)
    {
        int product = arr[i]*number +carry;
        arr[i] = product%10;
        carry=product/10;
    }

    while(carry)
    {
        arr[n] = carry%10;
        carry = carry/10;
        n++;
    }
}

void big_factorial(int number)
{
    int *a = new int[1000]{0};
    a[0]=1;
    int n=1;
    for(int i=2; i<=number; i++)
    {
        multiply(a, n, i);
    }
    for(int i=n-1; i>=0; i--)
    {
        cout << a[i];
    }
    cout << endl;
}

int main()
{
    int p;
    cin >> p;
    big_factorial(p);
}
