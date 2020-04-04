#include<iostream>
using namespace std;

float square_root(int number, int p)
{
    int s=0, e=number;
    int mid;
    float ans;
    while(s<=e)
    {
        mid=(s+e)/2;
        if(mid*mid==number)
        {
            ans=mid;
            break;
        }
        else if(mid*mid<number)
        {
            s=mid+1;
//            ans=mid;
        }
        else
        {
            e=mid-1;
        }
    }
    //fractional part
    float inc=0.1;
    for(int i=0; i<p; i++)
    {
        while(ans*ans<=number)
        {
            ans+=inc;
        }
        ans=ans-inc;
        inc=inc/10;
    }
    return ans;
}

int main()
{
    cout << square_root(49, 1) << endl;
    cout << square_root(10, 3) << endl;
    cout << square_root(2, 2) << endl;
    cout << square_root(512, 3) << endl;
}
