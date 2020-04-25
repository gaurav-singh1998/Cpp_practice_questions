//https://www.programminggeek.in/2018/08/codevita-2018-round-1-question-bride-hunting.html?m=1#.XqGnDvIzbeR

#include<bits/stdc++.h>
using namespace std;
map<pair<int, int>, int> qualities;
map<pair<int, int>, bool> visited;
int x[]={-1, 0, 1, 0, 1, -1, 1, -1};
int y[]={0, -1, 0, 1, -1, 1, 1, -1};

bool isValid(int R, int C, int x, int y)
{
    return (x<=R) && (y<=C) && (x>=0) && (y>=0);
}

void dfs(int matrix[][1000], int R, int C, int i, int j)
{
    //Base case
    if(!isValid(R, C, i, j))
    {
        return;
    }

    //Recursive case
    if(!visited[{i, j}])
    {
        visited[{i, j}]=true;
        if(matrix[i][j]==1)
        {
            for(int k=0; k<8; k++)
            {
                if(matrix[i+x[k]][j+y[k]] == 1)
                {
                    qualities[{i, j}] += 1;
                }
            }
        }
        for(int k=0; k<8; k++)
        {
            dfs(matrix, R, C, i+x[k], j+y[k]);
        }
    }
}

int main()
{
    int matrix[1000][1000];
    int row, col; cin >> row >> col;
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<col; j++)
        {
            cin >> matrix[i][j];
        }
    }
    matrix[0][0]=0;
    dfs(matrix, row, col, 0, 0);
    
    int final_quality=INT_MIN;
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<col; j++)
        {
            matrix[i][j]=qualities[{i, j}];
            final_quality=max(final_quality, qualities[{i,j}]);
        }
    }
    int b=0;
    pair<int, int> start;
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<col; j++)
        {
            if(matrix[i][j]==final_quality)
            {
                start.first=i; start.second=j;
                b=1;
                break;
            }
        }
        if(b==1)
        {
            break;
        }
    }
    if(final_quality==0)
    {
        cout << "No suitable girl found" << endl;
        return 0;
    }
    cout << start.first+1 << ":" << start.second+1 << ":" << final_quality << endl;
}