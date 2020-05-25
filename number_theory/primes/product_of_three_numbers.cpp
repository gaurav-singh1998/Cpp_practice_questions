//https://codeforces.com/problemset/problem/1294/C

#include<bits/stdc++.h>
using namespace std;


int main()
{
    int t; cin >> t;
    while(t--)
    {
        int num; cin >> num;
        int temp=num;
        vector<int> divisors;
        int cnt=0;
        for(int i=2; i*i<=num; i++)
        {
            if(num%i==0)
            {
                divisors.push_back(i);
                while(num%i==0)
                {
                    cnt++;
                    num=num/i;
                }
            }
        }

        if(num!=1)
        {
            divisors.push_back(num);
        }


        if(divisors.size()==1)
        {
            if(cnt>=6)
            {
                cout << "YES" << endl;
                cout << divisors[0] << " " << pow(divisors[0], 2) << " " << pow(divisors[0], (cnt-3)) << endl;
            }

            else
            {
                cout << "NO" << endl;
            }
            
        }

        else if(divisors.size()==2)
        {
            if((temp%(accumulate(divisors.begin(), divisors.end(), 1, multiplies<int>())))==0)
            {
                if(find(divisors.begin(), divisors.end(), 
                   temp/accumulate(divisors.begin(), divisors.end(), 1, multiplies<int>())) == divisors.end() &&
                   temp/accumulate(divisors.begin(), divisors.end(), 1, multiplies<int>()) != 1)
                {
                   cout << "YES" << endl;
                   cout << divisors[0] << " " << divisors[1] << " " << 
                   temp/accumulate(divisors.begin(), divisors.end(), 1, multiplies<int>()) << endl;
                }

                else
                {
                    cout << "NO" << endl;
                }
                
            }
            else
            {
                cout << "NO" << endl;
            }
            
        }

        else if(divisors.size()>=3)
        {
            cout << "YES" << endl;
            cout << divisors[0] << " " << divisors[1] << " ";
            cout << temp/(divisors[0]*divisors[1]) << endl;
        }

        else
        {
            cout << "NO" << endl;
        }
        
    }
}