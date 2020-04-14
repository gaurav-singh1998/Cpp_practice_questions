#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1010;
int grid[N][N], root[N][N];
bool vis[N][N];
int mark[N*N];
int n, m;
bool isValid(int x, int y)
{
    return x>=0 && x<n && y>=0 && y<m;
}
void dfs(int col, int x, int y)
{
    if(vis[x][y])
        return;
    vis[x][y] = true;
    mark[col]++;
    root[x][y] = col;
    int r[] = {0, 0, 1, -1};
    int c[] = {1, -1, 0, 0};
    for(int i=0; i<4; i++)
    {
        int px = x + r[i];
        int py = y + c[i];
        if(isValid(px, py))
        {
            if(grid[px][py] && !vis[px][py])
            {
                dfs(col, px, py);
            }
        }

    }
}

int main()
{
    cin >> n >> m;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cin >> grid[i][j];
        }
    }
    int col = 0;
    vector <pair<int, int> > vec;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(vis[i][j])
                continue;
            if(!grid[i][j])
            {
                vec.push_back({i, j});
                continue;
            }
            dfs(++col, i, j);
        }
    }
  //  cout << " VECTOR SIZE = " << vec.size() << endl;
    int r[] = {0, 0, -1, 1};
    int c[] = {1, -1, 0, 0};
    vector <pair<int, int> > :: iterator it;
    int ans = 0;
    for(it=vec.begin(); it!=vec.end(); it++)
    {
        int x = it->first, y = it->second;
        set <int> mp;
        for(int i=0; i<4; i++)
        {
            int px = x + r[i];
            int py = y + c[i];
            if(isValid(px, py))
            {
                if(!grid[px][py])
                    continue;
              mp.insert(root[px][py]);
            }
        }
        int cnt = 0;
        for(auto i:mp)
        {
            cnt += mark[i];

        }
        ans = max(ans, cnt);

    }
    cout << ans+1 << endl;
    return 0;
}