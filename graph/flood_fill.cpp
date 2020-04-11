#include<bits/stdc++.h>
using namespace std;


int R, C;
//W N E S
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

//ch is the color to be replaced.
//color is the character to be added.
void floodFill(char mat[][50], int i, int j, char ch, char color)
{
    //Base case Matrix bounds
    if(i<0 || j<0 || i>=R || j>=C)
    {
        return;
    }
    //Boundary condition Figure boundary
    if(mat[i][j] != ch)
    {
        return;
    }
    //Recursive call
    mat[i][j]=color;
    for(int k=0; k<4; k++)
    {
        floodFill(mat, i+dx[k], j+dy[k], ch, color);
    }
}