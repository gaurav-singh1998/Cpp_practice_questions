// --------------------------------------------------<TEMPLATE>--------------------------------------------------
// --------------------<optimizations>--------------------
//if anything breaks refresh from https://ideone.com/Usi84v
#pragma GCC optimize("O3")
//(UNCOMMENT WHEN HAVING LOTS OF RECURSIONS)\
#pragma comment(linker, "/stack:200000000")
//(UNCOMMENT WHEN NEEDED)\
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")\
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
// -------------------</optimizations>--------------------

// ---------------<Headers and namespaces>----------------
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define mod 1000000007
#define int long long
#define lcm(a, b) (a/__gcd(a, b))*b
#define endl '\n'
#define cntbits(x) __builtin_popcountll(x)
#define cntzero(x) __builtin_ctzll(x) //count the number of zeros before the first occurence of '1' form right (S & (-S))
#define isOn(S, j) (S & (1 << j))
#define setBit(S, j) (S |= (1 << j))
#define clearBit(S, j) (S &= ~(1 << j))
#define toggleBit(S, j) (S ^= (1 << j))
#define setAll(S, n) (S = (1 << n) - 1)
#define modulo(S, N) ((S) & (N - 1))   // returns S % N, where N is a power of 2
#define isPowerOfTwo(S) (!(S & (S - 1)))
#define nearestPowerOfTwo(S) ((int)pow(2.0, (int)((log((double)S) / log(2.0)) + 0.5)))
#define turnOffLastBit(S) ((S) & (S - 1))
#define turnOnLastZero(S) ((S) | (S + 1))
#define turnOffLastConsecutiveBits(S) ((S) & (S + 1))
#define turnOnLastConsecutiveZeroes(S) ((S) | (S - 1))
#define mk(arr, n, type) type *arr=new type[n]
#define vi vector<int>
#define mp make_pair
#define pi pair<int,int>
#define vc vector<char>
#define pb push_back
#define F first
#define S second
#define w(x) int x; cin >> x; while(x--)
#define print(t) cout << t << endl
#define print2(t1, t2) cout << t1 << " " << t2 << endl
#define in(arr, n) for(int i=0; i<n; i++) cin >> arr[i];
#define deb(x) cout<< #x << " " << x << "\n";
#define deb2(x, y) cout << #x << " = " << x << ", " << #y << " = " << y << "\n";
#define deb3(x, y, z) cout << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << "\n";
#define PI 3.1415926535897932384626
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count()); //shuffle(arr, arr+n, rng);

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

/**
 * Limits in C++ for reference
 * _____________________________________________________________________________________
 * |Sr| Macro Name | Description                     | Value
 * |No|____________|_________________________________|__________________________________
 * |1.| ULLONG_MAX | Maximum value unsigned long long| 18,446,744,073,709,551,615 (10^20)
 * |2.| LLONG_MAX  | Maximum value long long         | 9,223,372,036,854,775,807 (10^19)
 * |3.| LLONG_MIN  | Minimum value long long         |-9,223,372,036,854,775,808 -1*(10^19)
 * |4.| INT_MAX    | Maximum value int               | 2,147,483,647 (10^10)
 * |5.| INT_MIN    | Minimum value int               |-2,147,483,648 (10^10)
*/

void c_p_c()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

class Graph
{
	int V;
	map<int, list<int>> adjList;
public:
	Graph(int V)
	{
		this->V = V;
	}

	void addEdge(int u, int v)
	{
		adjList[u].push_back(v);
		adjList[v].push_back(u);
	}

	void helper(int curr, int parent, vector<int>& dp)
	{
		dp[curr] = curr;
		for (auto elem : adjList[curr])
		{
			if (elem != parent)
			{
				helper(elem, curr, dp);
				dp[curr] = min(dp[curr], dp[elem]);
			}
		}
	}

	vector<int> dfs()
	{
		vector<int> dp(V + 1);
		dp.clear();
		helper(1, 0, dp);
		return dp;
	}
};


int32_t main()
{
	//c_p_c();
	//clock_t begin, end;    double time_spent;
	//begin = clock();

	int n; cin >> n;
	Graph g(n);
	for (int i = 0; i < n - 1; i++)
	{
		int u, v; cin >> u >> v;
		g.addEdge(u, v);
	}
	vi dp = g.dfs();
	for (int i = 1; i <= n; i++)
	{
		cout << i << " " << dp[i] << endl;
	}


	//end = clock();
	//time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	//cout << "Time spent = " << time_spent << endl;
	return 0;
}