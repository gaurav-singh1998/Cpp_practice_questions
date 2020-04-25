//https://www.geeksforgeeks.org/path-rectangle-containing-circles/

#include<bits/stdc++.h>
using namespace std;

map<pair<int, int>, bool> visited;
int m, n, k, r;
int dx[]={-1, 0, 1, 0, 1, -1, 1, -1};
int dy[]={0, -1, 0, 1, -1, 1, 1, -1};
bool ans=false;

bool isValid(int R, int C, int i, int j)
{
    return (i<=R) && (j<=C) && (i>=0) && (j>=0);
}

void dfs(int matrix[][100], int R, int C, int i, int j)
{
    //Base case
    if(i==R-1 && j==C-1)
    {
        ans=true;
        return;
    }
    if(matrix[i][j]==0)
    {
        return;
    }

    //Out of Bounds case
    if(!isValid(R, C, i, j))
    {
        return;
    }

    //Recursive case
    if(!visited[{i, j}])
    {
        visited[{i, j}]=true;
        for(int k=0; k<4; k++)
        {
            dfs(matrix, R, C, i+dx[k], j+dy[k]);
        }
    }
}

int main()
{
    cin >> m >> n >> k >> r;
    vector<pair<int, int>> centres;
    for(int i=0; i<k; i++)
    {
        int x, y; cin >> x >> y;
        centres.push_back({x, y});
    }

    int matrix[100][100];
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            matrix[i][j]=1;
        }
    }

    for(int i=0; i<k; i++)
    {
        pair<int, int> centre = centres[i];
        matrix[centre.first-1][centre.second-1]=0;
        for(int k=0; k<8; k++)
        {
            if(isValid(m, n, (centre.first-1) + (dx[k]*r), (centre.second-1) + (dy[k]*r)))
            {
                matrix[(centre.first-1) + (dx[k]*r)][(centre.second-1) + (dy[k]*r)]=0;
            }
        }
    }
    if(matrix[0][0]==0)
    {
        cout << "Not Possible" << endl;
        return 0;
    }
    dfs(matrix, m, n, 0, 0);
    
    if(ans)
    {
        cout << "Possible" << endl;
        return 0;
    }
    cout << "Not Possible" << endl;
}