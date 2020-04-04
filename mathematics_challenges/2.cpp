#include<iostream>
using namespace std;
int paradox(float p)
{
    if(p==1)
    {
        return 366;
    }
    else
    {
        float x=1;
        int n=0;
        float num=365;
        float deno=365;
        while(x>=(1-p))
        {
            x=x*(num/deno);
            num--;
            n++;
        }
        return n;
    }
}
int main()
{
    float x;
    cin >> x;
    cout << paradox(x) << endl;
}
