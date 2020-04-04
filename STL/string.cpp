#include<iostream>
#include<algorithm>
using namespace std;

bool compare(string a, string b)
{
    return b<a;
}//lexograpphically in descending order

bool compare_length_wise(string a, string b)
{
    return b.length() < a.length();
}// in terms of the length of the string

int main()
{
    string s;
    getline(cin, s);
    int x = s.length();
    cout << s << endl;
    for(int i=0; i<x; i++)
    {
        cout << s[i] << "-";
    }
    cout << endl;
    string a[] = {"Apple", "Guava", "Banana", "Grapes"};
    for(int i=0; i<4; i++)
    {
        cout << a[i] << endl;
    }
    cout << "*******************************************************" << endl;
    sort(a, a+4, compare);
    for(int i=0; i<4; i++)
    {
        cout << a[i] << endl;
    }
    sort(a, a+4, compare_length_wise);
    for(int i=0; i<4; i++)
    {
        cout << a[i] << endl;
    }
}
