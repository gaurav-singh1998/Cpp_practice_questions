#include<bits/stdc++.h>
using namespace std;

int main()
{
    int N; cin >> N;
    int *arr = new int[N];
    for(int i=0; i<N; i++)
    {
        cin >> arr[i];
    }
    set<int> memo;
    map<int, int> index;
    memo.insert(arr[0]);
    index[arr[0]]=0;
    int prefix=arr[0];
    for(int i=1; i<N; i++)
    {
        prefix+=arr[i];
        if(prefix == 0)
        {
            cout << 0 << " to " << i << endl;
            break;
        }
        else if(memo.find(prefix) != memo.end())
        {
            cout << index[prefix]+1 << " to " << i << endl;
            break;
        }
        else
        {
            memo.insert(prefix);
            index[prefix]=i;
        }
    }
}