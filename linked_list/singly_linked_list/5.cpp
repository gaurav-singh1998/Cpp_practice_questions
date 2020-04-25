//https://www.geeksforgeeks.org/write-a-function-to-delete-a-linked-list/

#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int data;
    Node* next;
};

void push(Node** head_ref, int data)
{
    Node* newNode = new Node();
    newNode->data=data;
    newNode->next=*head_ref;
    *head_ref=newNode;
}

void printList(Node* head)
{
    Node *n=head;
    while(n->next != NULL)
    {
        cout << n->data << " ";
        n=n->next;
    }
    cout << n->data << endl;
}

void deleteList(Node **head_ref)
{
    Node *current = *head_ref;
    Node *next;
    while(current->next != NULL)
    {
        next->next=current->next;
        free(current);
        current=next;
    }
    *head_ref=NULL;
}

int main()
{
    Node *head=NULL;
    push(&head, 4);
    push(&head, 3);
    push(&head, 2);
    push(&head, 1);

    printList(head);
    deleteList(&head);
}