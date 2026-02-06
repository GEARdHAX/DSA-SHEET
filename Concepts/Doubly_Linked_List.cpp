#include <bits/stdc++.h>
using namespace std;
// Node Initialization :-
class Node
{
public:
    int data;
    Node *prev;
    Node *next;
    // Constructor :-
    Node(int d)
    {
        this->data = d;
        this->prev = NULL;
        this->next = NULL;
    }
};
// Print All Nodes :-
void printNode(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
// Length of List :-
int length(Node *head)
{
    int len = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        len++;
        temp = temp->next;
    }
    return len;
}
// Insert at Head :-
void insertAtHead(Node *&head, Node *&tail, int d)
{
    Node *newNode = new Node(d);
    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
        return;
    }

    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}
void insertAtTail(Node *&head, Node *&tail, int d)
{
    Node *newNode = new Node(d);
    if (tail == NULL)
    {
        head = newNode;
        tail = newNode;
        return;
    }

    newNode->prev = tail;
    tail->next = newNode;
    tail = newNode;
}
void insertAtPos(Node *&head, Node *&tail, int pos, int d)
{
    if (pos == 1)
    {
        insertAtHead(head, tail, d);
        return;
    }

    Node *temp = head;
    int cnt = 1;

    while (cnt < pos - 1 && temp != NULL)
    {
        temp = temp->next;
        cnt++;
    }

    // Invalid position
    if (temp == NULL)
        return;

    if (temp->next == NULL)
    {
        insertAtTail(head, tail, d);
        return;
    }

    Node *newNode = new Node(d);
    newNode->next = temp->next;
    temp->next->prev = newNode;
    temp->next = newNode;
    newNode->prev = temp;
}
void deleteNode(int pos, Node *&head)
{
    if (pos == 1)
    {
        Node *temp = head;
        temp->next->prev = NULL;
        head = temp->next;
        temp->next = NULL;
        delete temp;
    }
    int cnt = 1;
    Node *curr = head;
    Node *prev = NULL;
    while (cnt < pos)
    {
        prev = curr;
        curr = curr->next;
        cnt++;
    }
    curr->prev = NULL;
    prev->next = curr->next;
    curr->next = NULL;
    delete curr;
}
int main()
{
    Node *node1 = new Node(10);
    Node *head = node1;
    Node *tail = node1;
    insertAtHead(head, tail, 20);
    insertAtHead(head, tail, 30);
    insertAtHead(head, tail, 40);
    cout << "HEAD : ";
    printNode(head);
    insertAtTail(head, tail, 50);
    insertAtTail(head, tail, 60);
    insertAtTail(head, tail, 70);
    cout << "TAIL : ";
    printNode(head);
    insertAtPos(head, tail, 5, 80);
    insertAtPos(head, tail, 1, 90);
    insertAtPos(head, tail, 11, 100);
    cout << "POSITION : ";
    printNode(head);
    cout << "DELETE : ";
    deleteNode(9, head);
    printNode(head);
}
