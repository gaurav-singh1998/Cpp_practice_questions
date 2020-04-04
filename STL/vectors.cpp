#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    vector <char> c(10);
    for(int i=0; i<10; i++)
    {
        cin >> c[i];
    }
    vector <char> c2(10);
    reverse_copy(c.begin(), c.end(), c2.begin());
    for(int i=0; i<10; i++)
    {
        cout << c2[i] << endl;
    }
}
