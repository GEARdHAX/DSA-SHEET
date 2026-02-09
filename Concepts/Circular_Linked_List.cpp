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
};

void insertNode(Node *&tail, int d, int element)
{
    if (tail == NULL)
    {
        Node *newNode = new Node(d);
        tail = newNode;
        newNode->next = newNode;
    }
    else
    {
        Node *curr = tail;
        do
        {
            if (curr->data == element)
                break;
            curr = curr->next;
        } while (curr != tail);

        if (curr->data != element)
        {
            cout << "Element not found" << endl;
            return;
        }
        Node *temp = new Node(d);
        temp->next = curr->next;
        curr->next = temp;
    }
}
void deleteNode(Node *&tail, int value)
{
    if (tail == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }
    else
    {
        Node *prev = tail;
        Node *curr = prev->next;
        while (curr->data != value)
        {
            prev = curr;
            curr = curr->next;
        }
        prev->next = curr->next;
        // for 1 Node Only :-
        if (curr == prev)
            tail == NULL;

        // for 2 Node Only :-
        if (curr == tail)
            tail = prev;

        curr->next = NULL;
        delete curr;
    }
}
void print(Node *tail)
{
    if (tail == NULL)
        return;

    Node *temp = tail;
    do
    {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != tail);

    cout << endl;
}

int main()
{
    Node *tail = NULL;
    insertNode(tail, 5, 3);
    insertNode(tail, 7, 5);
    insertNode(tail, 12, 7);
    insertNode(tail, 10, 12);
    insertNode(tail, 15, 10);
    insertNode(tail, 16, 16);
    print(tail);
}