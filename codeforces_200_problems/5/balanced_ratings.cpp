//look at how numbers behave addition and subtraction
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n];
    for(int i=0; i<n; i++) cin >> a[i];
    int b[n], j=0;
    fill(b, b+n, 1165);
    for(int i=0; i<n; i++) 
    {
        if(!(a[i]&1))
        {
            b[i]=a[i]/2;
            j++;
        }
    }
    int odd_terms=n-j;
    int odd_terms_add=odd_terms/2;
    while(odd_terms_add!=0)
    {
        for(int i=0; i<n; i++)
        {
            if((a[i]&1) && b[i]==1165)
            {
                double x=double(a[i]);
                b[i]=floor(x/2);
                break;
            }
        }
        odd_terms_add--;
    }
    int odd_terms_sub=odd_terms/2;
    while(odd_terms_sub!=0)
    {
        for(int i=0; i<n; i++)
        {
            if((a[i]&1) && b[i]==1165)
            {
                double x=double(a[i]);
                b[i]=ceil(x/2);
                break;
            }
        }
        odd_terms_sub--;
    }
    for(int i=0; i<n; i++)
    {
        cout << b[i] << endl;
    }
}