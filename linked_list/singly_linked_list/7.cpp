//https://www.geeksforgeeks.org/search-an-element-in-a-linked-list-iterative-and-recursive/

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

void searchElement(Node *head, int data)
{
    //Base case
    if(head->data == data)
    {
        cout << "Element is present" << endl;
        return;
    }
    if(head->next==NULL)
    {
        cout << "Element not found" << endl;
        return;
    }

    //Recursive case
    searchElement(head->next, data);
}

int main()
{
    Node *head = NULL;
    push(&head, 4);
    push(&head, 3);
    push(&head, 2);
    push(&head, 1);
    printList(head);
    searchElement(head, 1);
}