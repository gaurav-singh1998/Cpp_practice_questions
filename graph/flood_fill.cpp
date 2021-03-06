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
	freopen("apple.txt", "r", stdin);
#endif
}

int R, C;
//W N E S
int dx[] = { -1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

//ch is the color to be replaced.
//color is the character to be added.
void floodFill(char mat[][50], int i, int j, char ch, char color)
{
	//Base case Matrix bounds
	if (i < 0 || j < 0 || i >= R || j >= C)
	{
		return;
	}
	//Boundary condition Figure boundary
	if (mat[i][j] != ch)
	{
		return;
	}
	//Recursive call
	mat[i][j] = color;
	for (int k = 0; k < 4; k++)
	{
		floodFill(mat, i + dx[k], j + dy[k], ch, color);
	}
}

int32_t main()
{
	c_p_c();
	//clock_t begin, end;    double time_spent;
	//begin = clock();
	cin >> R >> C;
	char in[50][50];
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			cin >> in[i][j];
		}
	}
	floodFill(in, 8, 13, '.', 'R');
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			cout << in[i][j];
		}
		cout << endl;
	}

	//end = clock();
	//time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	//cout << "Time spent = " << time_spent << endl;
	return 0;
}