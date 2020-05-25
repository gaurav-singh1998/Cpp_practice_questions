//https://online.codingblocks.com/app/player/30547/content/87834/5165/code-challenge
#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;

bitset<1000005>isPrime;
vector<ll>primes;

void seive()
{
    for(ll i=3; i<=1000005; i+=2)
    {
        isPrime[i]=1;
    }
    primes.push_back(2);
    for(ll i=3; i<=1000005; i+=2)
    {
        if(isPrime[i])
        {
            primes.push_back(i);
            for(ll j=i*i; j<=1000005; j+=i)
            {
                isPrime[j]=0;
            }
        }
    }
}


ll fast_exponentiation(ll num, ll pow)
{
    //Base case
    if(pow==0)
    {
        return 1;
    }

    //Recursive case
    ll smallPower = fast_exponentiation(num, pow/2);
    smallPower=smallPower%mod;

    smallPower=(smallPower*smallPower)%mod;

    if(pow&1)
    {
        return (num*smallPower)%mod;
    }
    return smallPower;
}

vector<ll> factorization(ll num)
{
    vector<ll> ans;
    for(ll i=1; i*i<=num; i++)
    {
        if(num%i==0)
        {
            if(i*i==num)
            {
                ans.push_back(i);
            }
            else
            {
                ans.push_back(i);
                ans.push_back(num/i);
            }
            
        }
    }
    return ans;
}

ll cnt_divisors(ll num)
{
    ll res=1;
    for(ll i=2; i*i<=num; i++)
    {
        if(num%i==0)
        {
            ll cnt=0;
            while (num%i==0)
            {
                cnt++;
                num=num/i;
            }
            res=(res*(cnt+1))%mod;
        }
    }

    if(num!=1)
    {
        res=(res*res)%mod;
    }
    return res;
}

int main()
{
    seive();
    ll n; cin >> n;
    ll *arr=new ll[n];
    for(ll i=0; i<n; i++)
    {
        cin >> arr[i];
    }

    ll res=1;
    for(ll i=0; i<n; i++)
    {
        res=(res*fast_exponentiation(primes[i], arr[i]))%mod;
    }
    vector<ll> ans=factorization(res);
    res=1;
    for(auto elem: ans)
    {
        res=(res*elem)%mod;
    }
    cout << cnt_divisors(res)%mod << endl;
}