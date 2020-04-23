//https://www.geeksforgeeks.org/linked-list-set-2-inserting-a-node/

#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int data;
    Node* next;
};

void PrintList(Node *node)
{
    while(node->next != NULL)
    {
        cout << node->data << " ";
        node = node->next;
    }
    cout << node->data << " " << endl;
}

void push(Node** head_ref, int new_data)
{
    Node *node = new Node();
    node->data=new_data;
    node->next=*head_ref;
    *head_ref=node;
}

void insertAfter(Node *prev_node, int new_data)
{
    Node *node = new Node();
    node->data = new_data;
    node->next = prev_node->next;
    prev_node->next = node;
}

void insertEnd(Node** head_ref, int new_data)
{
    Node* node = new Node();
    node->data = new_data;
    node->next = NULL;

    //If the linked list is empty.
    if(*head_ref==NULL)
    {
        *head_ref = node;
        return;
    }

    Node* last = *head_ref;
    while(last->next != NULL)
    {
        last=last->next;
    }
    last->next=node;
}

int main()
{
    Node *head = new Node();
    Node *second = new Node();
    Node *third = new Node();

    head->data=1;
    head->next=second;

    second->data=2;
    second->next=third;

    third->data=3;
    third->next=NULL;
    PrintList(head);

    push(&head, 45);
    PrintList(head);

    insertAfter(second, 88);
    PrintList(head);

    insertEnd(&head, 19);
    PrintList(head);
}