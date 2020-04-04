#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool f(int x, int y)
{
    return y < x;
}
int main()
{
    ///////////////////////////////////VECTOR DEMO///////////////////////////////////////////////////////
    vector<int> A = {3, 5, 4, 1, 2};
    for(int i=0; i<4; i++)
    {
        cout << A[i] << endl;
    }

    sort(A.begin(), A.end());

    bool present = binary_search(A.begin(), A.end(), 3);
    A.push_back(100);
    present = binary_search(A.begin(), A.end(), 100);
    A.push_back(100);
    A.push_back(100);
    A.push_back(100);
    A.push_back(100);
    A.push_back(123);
    
    auto it = lower_bound(A.begin(), A.end(), 100);//pointer to number greater than equal to 100 in the vector;
    // Lower bound and Upper bound uses binary search so we will have to sort the vector first

    auto it2 = upper_bound(A.begin(), A.end(), 100);//pointer to number greater than 100 in the vector;
    cout << *it << "  " << *it2 << endl;
    
    sort(A.begin(), A.end(), f);
    vector<int>::iterator it3;
    for(it3 = A.begin(); it3 != A.end(); it3++)
    {
        cout << *it3 << endl;
    }
    cout << "*********************************************************************" << endl;
    for(int x: A)
    {
        cout << x << endl;
    }
    cout << "*********************************************************************" << endl;
    for(int &x: A) // by reference to make changes while iterating through to the elements of the vector
    {
        x++;
        cout << x << endl;
    }
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    



    ////////////////////////SET DEMO////////////////////////////////////////////////////////////////////////////////////
    set<int> s;
    s.insert(1);
    s.insert(2);
    s.insert(-10);
    s.insert(-1);
    for(int x: s)
    {
        cout << x<< endl;
    }
    auto it4 = s.find(-1);
    if(it4 == s.end())
    {
        cout << "Not Found" << endl;
    }
    else
    {
        cout << "Found" << endl;
    }
    auto it5 = lower_bound(s.begin(), s.end(), -1);    
    cout << *it5 << endl;
    auto it6 = upper_bound(s.begin(), s.end(), 2);
    if(it6 == s.end())
    {
        cout << "Not Found" << endl;
    }

    s.insert(2);
    s.insert(2);
    for(int x: s)
    {
        cout << x << endl;
    }
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//
///////////////////////////////////////////MAP DEMO///////////////////////////////////////////////////////////////////////////////
    map<char, int> cnt;
    string x = "Gaurav Singh";
    for(char s: x)
    {
        cnt[s]++;
    }
    cout << cnt['G'] << "  " <<  cnt['a'] << endl;

    auto it10 = cnt.find('G');

}

