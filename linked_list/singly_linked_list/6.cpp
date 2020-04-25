//https://www.geeksforgeeks.org/find-length-of-a-linked-list-iterative-and-recursive/

#include<bits/stdc++.h>
using namespace std;

int length;

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

void findLengthRecursive(Node *head)
{
    //Base case
    if(head->next == NULL)
    {
        return;
    }

    //Recursive case
    length++;
    findLengthRecursive(head->next);
}

int main()
{
    Node *head = NULL;
    push(&head, 4);
    push(&head, 3);
    push(&head, 2);
    push(&head, 1);
    printList(head);
    findLengthRecursive(head);
    cout << length+1 << endl;
    length=0;
    push(&head, 55);
    printList(head);
    findLengthRecursive(head);
    cout << length+1 << endl;
}