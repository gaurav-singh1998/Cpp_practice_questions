#include<bits/stdc++.h>
using namespace std;

bool isSafe(int board[][10], int i, int j, int n)
{
    //for col
    for(int row=0; row<i; row++)
    {
        if(board[row][j]==1)
        {
            return false;
        }
    }
    //for left diagonal
    int x=i;
    int y=j;
    while(x>=0 && y>=0)
    {
        if(board[x][y]==1)
        {
            return false;
        }
        x--;
        y--;
    }

    //right diagonal
    x=i;
    y=j;
    while(x>=0 && y<n)
    {
        if(board[x][y]==1)
        {
            return false;
        }
        x--;
        y++;
    }

    return true;
}

bool solveNQueen(int board[][10], int i, int n)
{
    //Base case
    if(i==n)
    {
        //for printing the board.
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(board[i][j]==1)
                {
                    if(j==0)
                    {
                        cout << "Q ";
                    }
                    else
                    {
                        cout << " Q ";
                    }
                    
                }
                else
                {
                    if(j==0)
                    {
                        cout <<"x ";
                    }
                    else
                    {
                        cout << " x ";
                    }
                    
                }
            }
            cout << endl;
        }
        cout << endl;
        return false;
    }
    //recursive case
    for(int j=0; j<n; j++)
    {
        if(isSafe(board, i, j, n))
        {
            board[i][j]=1;
            bool nextQueen=solveNQueen(board, i+1, n);
            if(nextQueen) return true;
            //if false then previous config is false
            board[i][j]=0;
        }
    }
    return false;
}


int main()
{
    int n;
    cin >> n;
    int board[10][10]={0};
    solveNQueen(board, 0, n);
}