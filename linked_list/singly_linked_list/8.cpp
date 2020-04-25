//https://www.geeksforgeeks.org/write-a-function-to-get-nth-node-in-a-linked-list/

#include<bits/stdc++.h>
using namespace std;
int i;

class Node
{
    public:
    int data;
    Node* next;
};

void push(Node** head_ref, int data)
{
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next=*head_ref;
    *head_ref=newNode;
}

void printList(Node *head)
{
    Node *node = head;
    while(node->next != NULL)
    {
        cout << node->data << " ";
        node=node->next;
    }
    cout << node->data << endl;
}

void getNthNode(Node* node, int pos)
{
    //Base case
    if(i==pos)
    {
        cout << node->data << endl;
        return;
    }
    if(node->next == NULL)
    {
        return;
    }

    //Recursive case
    i++;
    getNthNode(node->next, pos);
}

int main()
{
    Node *head = NULL;
    push(&head, 4);
    push(&head, 3);
    push(&head, 2);
    push(&head, 1);
    printList(head);
    getNthNode(head, 0);
}