//How many people are in a room such that the probability of atleast two persons
//having birthday on the same day is 50%?
#include<iostream>
using namespace std;

int main()
{
    float num = 365;
    float deno = 365;

    float p = 1;//probablity that birthday are on different dates.
    int n=0;
    while(p>=0.5)
    {
        p = p*(num/deno);
        num--;
        n++;
    }
    cout << n << endl;
}


