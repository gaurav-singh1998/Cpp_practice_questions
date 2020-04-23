//https://www.geeksforgeeks.org/delete-a-linked-list-node-at-a-given-position/

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

void deleteNode(Node **head_ref, int position)
{
    if (*head_ref == NULL) 
      return;

    Node* temp = *head_ref;

    if (position == 0) 
    { 
        *head_ref = temp->next;   
        free(temp);                
        return; 
    }

    for (int i=0; temp!=NULL && i<position-1; i++) 
         temp = temp->next;

    if (temp == NULL || temp->next == NULL) 
         return;

    Node *next = temp->next->next;
    free(temp->next);
    temp->next = next;
}

int main()
{
    Node* head = NULL;
    push(&head, 7); 
    push(&head, 1); 
    push(&head, 3); 
    push(&head, 2); 
    push(&head, 8);

    PrintList(head); 
    deleteNode(&head, 4);
    PrintList(head);
}