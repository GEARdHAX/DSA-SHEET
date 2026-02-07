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

void insertNode(Node *&tail, int d,int element)
{
    if (tail == NULL)
    {
        Node *newNode = new Node(d);
        tail = newNode;
        newNode->next = newNode;
    }
    else{
        Node *curr = tail;
        while (curr->data != element)
        {
            curr = curr->next;
        }
        Node *temp = new Node(d);
        temp->next = curr->next;
        curr->next = temp;

    }
}

int main()
{
    Node *node1 = new Node(10);
}