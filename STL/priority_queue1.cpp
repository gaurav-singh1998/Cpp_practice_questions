#include<iostream>
#include<bits/stdc++.h>
using namespace std;



int main()
{
    priority_queue<int> pq_max;
    priority_queue<int, vector<int>, greater<int>>pq_min;
    int a[10] = {5, 6, 17, 18, 9, 11};
    for(int i=0; i<6; i++)
    {
        pq_max.push(a[i]);
    }
    while(!pq_max.empty())
    {
        cout << pq_max.top() << endl;
        pq_max.pop();
    }
}

