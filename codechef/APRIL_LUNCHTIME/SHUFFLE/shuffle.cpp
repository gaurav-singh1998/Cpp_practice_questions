//https://www.codechef.com/LTIME83B/problems/SHUFFLE

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int mod = 1e9+7;
 
int main(){
 
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    ll t;
    cin>>t;
 
    while(t--){
 
 		ll n, k;
    	cin>>n>>k;

    	ll A[n];
    	ll A1[k];
    	for(ll i=0; i<n; i++){
    		cin>>A[i];
    	}


    	for(ll i=0; i<n; i++){
    		if(A[i%k]>A[i]){
    			swap(A[i%k], A[i]);
    		}
    	}

    	ll flag = 0;
    	for(ll i=1; i<k ;i++){
    		if(A[i]<A[i-1]){

    			flag = 1;
    			break;
    		}
    	}

    	// cout<<A[k-1]<<endl;
    	if(!flag){
	    	for(ll i=k; i<n; i++){
	    		if(A[i]<A[k-1]){
	    			flag = 1;

	    			break;
	    		}
	    	}
    		
    	}

    	if(flag)
    		cout<<"no"<<endl;
    	else cout<<"yes"<<endl;

    }
	return 0;
}
