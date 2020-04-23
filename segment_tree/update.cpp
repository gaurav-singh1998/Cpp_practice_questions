#include<bits/stdc++.h>
using namespace std;

void updateNode(int *tree, int ss, int se, int i, int increment, int index)
{
    //base case: out of bounds
    if(i>se || i<ss) return;
    //base case leaf node
    if(ss==se)
    {
        tree[index] += increment;
        return;
    }

    //left and right
    int mid=(ss+se)/2;
    updateNode(tree, ss, mid, i, increment, 2*index);
    updateNode(tree, mid+1, se, i, increment, 2*index+1);
    tree[index] = min(tree[2*index], tree[2*index+1]);
    return;
}

void updateRange(int *tree, int ss, int se, int l, int r, int inc, int index)
{
    //base case out of bounds
    if(l>se || r<ss)
    {
        return;
    }

    //base case leaf node
    if(ss==se)
    {
        tree[index] += inc;
        return;
    }

    //left and right
    int mid = (ss+se)/2;
    updateRange(tree, ss, mid, l, r, inc, 2*index);
    updateRange(tree, mid+1, se, l, r, inc, 2*index+1);
    tree[index] = min(tree[2*index], tree[2*index+1]);
    return;
}

void makeTree(int *a, int s, int e, int *tree, int index)
{
    //Base case
    if(s==e)
    {
        tree[index]=a[s];
        return;
    }

    //recursive case
    int mid=(s+e)/2;
    makeTree(a, s, mid, tree, 2*index);
    makeTree(a, mid+1, e, tree, 2*index+1);
    tree[index]=min(tree[2*index], tree[2*index+1]);
    return;
}

int main()
{
    int a[]={1, 3, 2, -5, 6, 4};
    int n=sizeof(a)/sizeof(int);
    int *tree = new int[4*n+1];
    makeTree(a, 0, n-1, tree, 1);
    for(int i=1; i<=13; i++)
    {
        cout << tree[i] << " ";
    }
    cout << endl;

    int i, inc; cin >> i >> inc;
    updateNode(tree, 0, n-1, i, inc, 1);
    for(int i=1; i<=13; i++)
    {
        cout << tree[i] << " ";
    }
    cout << endl;
    updateRange(tree, 0, n-1, 2, 3, 10, 1);
    for(int i=1; i<=13; i++)
    {
        cout << tree[i] << " ";
    }
    cout << endl;
}