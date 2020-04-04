#include<bits/stdc++.h>
using namespace std;

class Hostel
{
        public:
        int x;
        int y;
        Hostel(): x(0), y(0)
    {}
        Hostel(int x, int y): x(x), y(y)
    {}
        int dist()
        {
            return x*x+y*y;
        }
};


class Compare
{
    public:
        bool operator()(Hostel h1, Hostel h2)
        {
            return h1.dist() >  h2.dist();
        }
};



int main()
{
    priority_queue<Hostel, vector<Hostel>, Compare> pq;
    int query, k_dist;
    vector<Hostel>j(query);
    vector<int>result;
    cin >> query >> k_dist;
    int query_type, x_coor, y_coor;
    for(int i=0; i<query; i++)
    {
        cin >> query_type;
        if(query_type == 1)
        {
            cin >> x_coor >> y_coor;
            Hostel hq(x_coor, y_coor);
            pq.push(hq);
        }
        else if(query_type == 2)
        {
            for(int i=0; i<k_dist-1; i++)
            {
                j[i]=pq.top();
                pq.pop();
            }
            Hostel z= pq.top();
            result.push_back(z.dist());
           for(int i=0; i<k_dist-1; i++) 
           {
               pq.push(j[i]);
           }
        }
    }
    for(int x: result)
    {
        cout << x << endl;
    }
}


