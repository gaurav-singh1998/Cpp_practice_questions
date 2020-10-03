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
	int V;
public:
	Graph(int v)
	{
		this->V = v;
	}

	void addEdge(int u, int v)
	{
		adjList[u].push_back(v);
		adjList[v].push_back(u);
	}

	int helper(int node, map<int, bool>& visited, int* subtree)
	{
		visited[node] = true;
		int size = 1;
		for (auto elem : adjList[node])
		{
			if (!visited[elem])
			{
				size += helper(elem, visited, subtree);
			}
		}
		subtree[node] = size;
		return size;
	}


	void dfs()
	{
		map<int, bool> visited;
		mk(subtree, V + 1, int);
		int size = 1;
		for (auto elem : adjList)
		{
			if (!visited[elem.first])
			{
				helper(elem.first, visited, subtree);
			}
		}
		for (int i = 1; i <= V; i++)
		{
			deb(i); deb(subtree[i]);
		}
	}
};


int32_t main()
{
	//c_p_c();
	//clock_t begin, end;    double time_spent;
	//begin = clock();


	Graph g(7);
	g.addEdge(1, 2);
	g.addEdge(2, 3);
	g.addEdge(3, 7);
	g.addEdge(2, 4);
	g.addEdge(4, 5);
	g.addEdge(4, 6);
	g.dfs();

	//end = clock();
	//time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	//cout << "Time spent = " << time_spent << endl;
	return 0;
}