// --------------------------------------------------<TEMPLATE>--------------------------------------------------
// --------------------<optimizations>--------------------
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
using namespace std;
using namespace __gnu_pbds;
#define mod 1000000007
#define int long long
#define lcm(a, b) (a/__gcd(a, b))*b
#define endl '\n'
#define cntbits(x) __builtin_popcountll(x)
#define cntzero(x) __builtin_ctzll(x) //count the number of zeros before the first occurence of '1' form right
#define mk(arr, n, type) type *arr=new type[n]
#define vi vector<int>
#define mp make_pair
#define pi pair<int,int>
#define vc vector<char>
#define pb push_back
#define F first
#define S second
#define w(x) int x; cin >> x; while(x--)
#define in(arr, n) for(int i=0; i<n; i++) cin >> arr[i];
#define deb(x) cout<< #x << " " << x << "\n";
mt19937         rng(chrono::steady_clock::now().time_since_epoch().count()); //shuffle(arr, arr+n, rng);

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;


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
	map<int, list<int>> adjList;
	int X;
public:
	Graph()
	{
		this->X = 0;
	}

	void addEdge(int u, int v)
	{
		adjList[u].pb(v);
		adjList[v].pb(u);
	}


	void helper(int node, map<int, bool>& visited, int& max_cnt, int& cnt)
	{
		visited[node] = true;
		cnt++;
		for (auto elem : adjList[node])
		{
			if (!visited[elem])
			{
				if (cnt >= max_cnt)
				{
					max_cnt = cnt;
					X = elem;
				}
				helper(elem, visited, max_cnt, cnt);
			}
		}
	}

	void dfs(int node, int& max_cnt)
	{
		map<int, bool> visited;
		int cnt = 0;
		helper(node, visited, max_cnt, cnt);
	}

	int diameter()
	{
		int max_cnt = INT_MIN;

		dfs(1, max_cnt);

		dfs(X, max_cnt);

		return max_cnt;
	}
};



int32_t main()
{
	c_p_c();
	//clock_t begin, end;    double time_spent;
	//begin = clock();

	Graph g;
	g.addEdge(1, 2);
	g.addEdge(1, 3);
	g.addEdge(2, 4);
	g.addEdge(2, 5);
	cout << g.diameter() - 1 << endl;


	//end = clock();
	//time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	//cout << "Time spent = " << time_spent << endl;
	return 0;
}