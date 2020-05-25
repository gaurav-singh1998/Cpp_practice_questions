//https://online.codingblocks.com/app/player/30547/content/87834/5067/code-challenge
//Concept:- Totient

#include <bits/stdc++.h> 
using namespace std;  


int phi(int n) 
{ 
    float result = n;

    for (int p = 2; p * p <= n; ++p) { 
        if (n % p == 0) { 
            while (n % p == 0) 
                n /= p; 
            result *= (1.0 - (1.0 / (float)p)); 
        } 
    } 
    if (n > 1) 
        result *= (1.0 - (1.0 / (float)n)); 
  
    return (int)result; 
}  
  
int main()  
{  
    int t; cin >> t;
    while(t--)
    {
        int num; cin >> num;
        cout << phi(num) << endl;
    }  
}  