//https://www.codechef.com/LTIME83B/problems/FFL
#include<bits/stdc++.h>
using namespace std;

bool compare(pair<int, int> P1, pair<int, int> P2)
{
    return P1.first < P2.first;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T; cin >> T;
    while(T--)
    {
        int N, S; cin >> N >> S;
        vector<int> prices;
        for(int i=0; i<N; i++)
        {
            int price; cin >> price;
            prices.push_back(price);
        }
        vector<int> df;
        for(int i=0; i<N; i++)
        {
            int d; cin >> d;
            df.push_back(d);
        }
        vector<pair<int, int>> maped;
        for(int i=0; i<N; i++)
        {
            maped.push_back({prices[i], df[i]});
        }
        sort(maped.begin(), maped.end(), compare);
        int left=100-S;

        if(left-maped[0].first >= 0)
        {
            left -= maped[0].first;
            int i = maped[0].second;
            int j = 1;
            int ans=0;
            while(left>=0 && j<N)
            {
                if(maped[j].second == 1-i)
                {
                    if(left-maped[j].first >= 0)
                    {
                        left -= maped[j].first;
                        ans=1;
                        break;
                    }
                }
                j++;
            }
            if(ans==1)
            {
                cout << "yes" << endl;
                continue;
            }
        }
        cout << "no" << endl;
        continue;
    }
}
