#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

int Query(int *tree, int ss, int se, int qs, int qe, int index)
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
    int leftAns=Query(tree, ss, mid, qs, qe, 2*index);
    int rightAns=Query(tree, mid+1, se, qs, qe, 2*index+1);
    return min(leftAns, rightAns);
}

void updateNode(int *tree, int ss, int se, int i, int increment, int index)
{
    //base case: out of bounds
    if(i>se || i<ss) return;
    //base case leaf node
    if(ss==se)
    {
        tree[index] = increment;
        return;
    }

    //left and right
    int mid=(ss+se)/2;
    updateNode(tree, ss, mid, i, increment, 2*index);
    updateNode(tree, mid+1, se, i, increment, 2*index+1);
    tree[index] = min(tree[2*index], tree[2*index+1]);
    return;
}

void buildTree(int *a, int *tree, int s, int e, int index)
{
    //Base index
    if(s==e)
    {
        tree[index] = a[s];
        return;
    }

    //Recursive case
    int mid = (s+e)/2;
    buildTree(a, tree, s, mid, 2*index);
    buildTree(a, tree, mid+1, e, 2*index+1);
    tree[index]=min(tree[2*index], tree[2*index+1]);
    return;
}

int main()
{
    int N, Q; cin >> N >> Q;
    int *arr = new int[N];
    for(int i=0; i<N; i++)
    {
        cin >> arr[i];
    }
    int *tree = new int[4*N + 1];
    buildTree(arr, tree, 0, N-1, 1);
    for(int i=0; i<Q; i++)
    {
        int type, q1, q2;
        cin >> type >> q1 >> q2;
        if(type==1)
        {
            cout << Query(tree, 0, N-1, q1-1, q2-1, 1) << endl;
            continue;
        }
        updateNode(tree, 0, N-1, q1-1, q2, 1);
    }
}