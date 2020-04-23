//https://www.geeksforgeeks.org/linked-list-set-3-deleting-node/?ref=lbp

#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int data;
    Node* next;
};

void push(Node** head_ref, int value)
{
    Node *node = new Node();
    node->data=value;
    node->next=*head_ref;
    *head_ref=node;
}

void deleteNode(Node** head_ref, int key)
{
    Node* temp = *head_ref, *prev;
    if (temp != NULL && temp->data == key) 
    { 
        *head_ref = temp->next; 
        free(temp);             
        return; 
    } 

    while (temp != NULL && temp->data != key) 
    { 
        prev = temp; 
        temp = temp->next; 
    } 
  
    if (temp == NULL) return;
    prev->next = temp->next;
    free(temp);
}

void PrintList(Node *node)
{
    while(node->next != NULL)
    {
        cout << node->data << " ";
        node = node->next;
    }
   // cout << node->data << " " << endl;
   cout << endl;
}

int main()
{
    Node* head = new Node();
    push(&head, 7); 
    push(&head, 1); 
    push(&head, 3); 
    push(&head, 2);

    PrintList(head);
    deleteNode(&head, 1);
    PrintList(head);
}