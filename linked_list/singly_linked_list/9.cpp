//https://www.geeksforgeeks.org/nth-node-from-the-end-of-a-linked-list/

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

void printNthFromLast(Node* head, int n) 
{ 
    int len = 0, i; 
    struct Node* temp = head; 
  
    while (temp != NULL) { 
        temp = temp->next; 
        len++; 
    } 

    if (len < n) 
        return; 
  
    temp = head; 
 
    for (i = 1; i < len - n + 1; i++) 
        temp = temp->next; 
  
    cout << temp->data << endl; 
  
    return; 
} 

int main()
{
    Node *head = NULL;
    push(&head, 4);
    push(&head, 3);
    push(&head, 2);
    push(&head, 1);
    printList(head);
    printNthFromLast(head, 3);
}