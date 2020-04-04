#include<bits/stdc++.h>
using namespace std;
//Priority queue use heap data structure push and pop take O(logn) time.
struct comparator
{
    bool operator()(int a, int b)
    {
        if(a<b) return false;
        return true;
    }
};
int main()
{
    priority_queue<int, vector<int>, comparator>pq;
    pq.push(2);
    pq.push(3);
    cout << pq.top() << endl;
}
