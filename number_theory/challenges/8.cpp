//https://online.codingblocks.com/app/player/30547/content/87834/5169/code-challenge
//Concept:-Seive
#include<bits/stdc++.h>
using namespace std;

void createCountArray(int arr[], int n, int maxi, int ans[]) {
    int count[maxi+1];
    memset(count, 0, (maxi+1)*sizeof(int));
    
    for(int i=0; i<n; i++)  {
        count[arr[i]]++;
    }
    
    for(int i=1; i<=maxi; i++) {
        for(int j=i; j<=maxi; j+=i) {
            ans[i] += count[j];
        }
    }
    
}

int main() {
    int n; cin>>n;
    int arr[n]; for(int i=0; i<n; i++)  cin>>arr[i];
    int q; cin>>q;
    
    int maxi = 100005;
    int ans[maxi+1];
    memset(ans, 0, (maxi+1)*sizeof(int));
    
    createCountArray(arr, n, maxi, ans);
    
    while(q--) {
        int k; cin>>k;
        cout<<ans[k]<<"\n";
    }
	return 0;
}