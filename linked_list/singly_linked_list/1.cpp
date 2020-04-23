//https://www.geeksforgeeks.org/linked-list-set-1-introduction/

#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int data;
    Node* next;
};

void PrintList(Node* node)
{
    while(node->next != NULL)
    {
        cout << node->data << " ";
        node = node->next;
    }
    cout << node->data << " ";
    cout << endl;
}

int main()
{
    Node* head = NULL;
    Node* first =  NULL;
    Node* second = NULL;

    head = new Node();
    first = new Node();
    second = new Node();

    head->data=1;
    head->next=first;
    

    first->data=2;
    first->next=second;


    second->data=3;
    second->next=NULL;

    PrintList(head);
}