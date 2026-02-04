#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    // Constructor :-
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    // Destructor

    ~Node()
    {
        if (next != NULL)
        {
            delete next; // deletes remaining list
            next = NULL;
        }
        cout << "Deleted node with data " << data << endl;
    }
};

// Insert at Head
void insertAtHead(Node *&head, int d)
{
    Node *newNode = new Node(d);
    newNode->next = head;
    head = newNode;
}

// Insert at Tail
void insertAtTail(Node *&tail, int d)
{
    Node *newNode = new Node(d);
    tail->next = newNode;
    tail = newNode;
}

// Insert at Position
void insertAtPosition(Node *&head, Node *&tail, int pos, int d)
{
    if (pos == 1)
    {
        insertAtHead(head, d);
        return;
    }

    Node *temp = head;
    int cnt = 1;

    while (cnt < pos - 1 && temp->next != NULL)
    {
        temp = temp->next;
        cnt++;
    }

    if (temp->next == NULL)
    {
        insertAtTail(tail, d);
        return;
    }

    Node *newNode = new Node(d);
    newNode->next = temp->next;
    temp->next = newNode;
}

// Deletation of a node :-
void deleteNode(Node *&head, Node *&tail, int value)
{
    // Delete At postion = 1 / HEAD :-
    // if (pos == 1)
    // {
    //     Node *temp = head;
    //     head = head->next;
    //     temp->next = NULL;
    //     delete temp;
    //     return;
    // }

    {
        Node *curr = head;
        Node *prev = NULL;
        // Delete at position = x / TAIL :-
        int cnt = 1;
        while (curr->data != value)
        {
            prev = curr;
            curr = curr->next;
            cnt++;
        }
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}
// Print Linked List
void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main()
{
    Node *head = new Node(10);
    Node *tail = head;

    insertAtTail(tail, 20);
    insertAtTail(tail, 30);
    insertAtTail(tail, 40);
    insertAtHead(head, 5);
    insertAtPosition(head, tail, 3, 15);

    print(head);
    // deleteNode(head, tail, 1);
    print(head);
    deleteNode(head, tail, 5);
    print(head);
    // deleteNode(head, tail, 3);
    print(head);
    return 0;
}
