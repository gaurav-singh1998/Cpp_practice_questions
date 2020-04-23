//1 update O(log n)
//range update O(n)
//Query O(log n)

#include<bits/stdc++.h>
using namespace std;

int query(int *tree, int ss, int se, int qs, int qe, int index)
{
    //case 1: Complete overlap
    if(ss>=qs && se<=qe)
    {
        return tree[index];
    }

    //case 2: No overlap
    if(qe<ss || qs>se)
    {
        return INT_MAX;
    }

    //case 3: Partial overlap - Call on both the sides and update the current ans
    int mid = (ss+se)/2;
    int leftAns=query(tree, ss, mid, qs, qe, 2*index);
    int rightAns=query(tree, mid+1, se, qs, qe, 2*index+1);
    return min(leftAns, rightAns);
}

void buildTree(int *a, int s, int e, int *tree, int index)
{
    //Base index
    if(s==e)
    {
        tree[index] = a[s];
        return;
    }

    //Recursive case
    int mid = (s+e)/2;
    buildTree(a, s, mid, tree, 2*index);
    buildTree(a, mid+1, e, tree, 2*index+1);
    tree[index]=min(tree[2*index], tree[2*index+1]);
    return;
}

int main()
{
    int a[]={1, 3, 2, -5, 6, 4};
    int n = sizeof(a)/sizeof(int);
    int *tree = new int[4*n+1];
    buildTree(a, 0, n-1, tree, 1);
    for(int i=1; i<=13; i++)
    {
        cout << tree[i] << " ";
    }
    cout << endl;

    int l, r; cin >> l >> r;
    cout << query(tree, 0, n-1, l, r, 1) << endl;
}