#include<bits/stdc++.h>
#define ll long long
using namespace std;

unsigned long reverse(unsigned long num) {
  unsigned long s = 8*sizeof(num); // bit size; must be power of 2
  cout << s << endl;
  unsigned long mask = ~0;
  while ((s >>= 1) > 0) {
    mask ^= (mask << s);
    num = ((num >> s) & mask) | ((num << s) & ~mask);
  }
  return num;
}


int main()
{
    ll num; cin >> num;
    ll rnum=reverse(num);
    cout << rnum << endl;
}