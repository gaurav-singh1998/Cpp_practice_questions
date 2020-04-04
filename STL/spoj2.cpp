#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int cases;
    cin >> cases;
    char mat[55][55];

    for(int i=0; i<cases; i++)
    {
        int M, N, K;
        cin >> M >> N >> K;
        vector<int>bulbsLit(M, 0);
        for(int r=0; r<M; r++)
        {
            for(int c=0; c<N; c++)
            {
                cin >> mat[r][c];
                if(mat[r][c] == '*')++bulbsLit[r];
            }
        }
        sort(bulbsLit.begin(), bulbsLit.end(), less<int>());

        int idx=0;
        while(K>0 && idx<M && N-bulbsLit[idx]>bulbsLit[idx])
        {
            bulbsLit[idx] = N-bulbsLit[idx];
            --K;
            ++idx;
        }

        if(K!=0 && K%2==1)
        {
            auto it = min_element(bulbsLit.begin(), bulbsLit.end());
            *it = N-*it;
        }
        cout <<  accumulate(bulbsLit.begin(), bulbsLit.end(), 0) << '\n';

    }
}
