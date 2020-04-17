#include<bits/stdc++.h>
#define ll long long
using namespace std;


ll cnt=0;

//W N E S
ll dx[] = {-1, 0, 1, 0};
ll dy[] = {0, -1, 0, 1};

//To check if inside labyrinth.
bool isValid(ll x, ll y, ll R, ll C)
{
    return (x<R) && (x>=0) && (y<C) && (y>=0);
}

void dfs(char labyrinth[][1000], bool visited[][1000], ll R, ll C, ll i, ll j)
{
    //Base case
    if(labyrinth[i][j]=='#') return;

    //Boundary case
    if(!isValid(i, j, R, C)) return;

    //Recursive case
    if(!visited[i][j])
    {
        visited[i][j]=true;
        labyrinth[i][j]='x';
        for(ll k=0; k<4; k++)
        {
            dfs(labyrinth, visited, R, C, i+dx[k], j+dy[k]);
        }
    }
}

int main()
{
    ll T; cin >> T;

    //the main labyrinth
    char labyrinth[1000][1000];

    //visited array to keep track of visited elements
    bool visited[1000][1000]={false};
    while(T--)
    {
        ll R, C;
        cin >> C >> R;
    
        for(ll i=0; i<R; i++)
        {
            for(ll j=0; j<C; j++)
            {
                cin >> labyrinth[i][j];
                visited[i][j]=false;
            }
        }
        pair<ll, ll> index;
        for(ll i=0; i<C; i++)
        {
            ll present=0;
            for(ll j=0; j<R; j++)
            {
                if(labyrinth[i][j]=='.')
                {
                    present=1;
                    index.first=i; index.second=j;
                    break;
                }
            }
            if(present)
                break;
        }
        dfs(labyrinth, visited, R, C, index.first, index.second);
        for(ll i=0; i<R; i++)
        {
            for(ll j=0; j<C; j++)
            {
                cout << labyrinth[i][j] << " ";
            }
            cout << endl;
        }      
    }
}