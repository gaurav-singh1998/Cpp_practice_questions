#include<bits/stdc++.h>
using namespace std;

int main()
{
    char s[100] = "Today is a rainy day.";
    auto ptr = strtok(s, " ");
    cout << ptr << endl;
    char a[100] = "Today is not a rainy day.";
    while(ptr != NULL){
        auto ptr = strtok(NULL, " ");
        cout << ptr << endl;
    }
}