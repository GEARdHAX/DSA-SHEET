/*
 * @lc app=leetcode id=138 lang=cpp
 *
 * [138] Copy List with Random Pointer
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
#include <bits/stdc++.h>
using namespace std;
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        // if (head == NULL ||  || head->next == NULL) {
        //     return head;
        // }
        map<Node *, Node *> copyMap;
        Node *temp = head;
        while (temp != NULL)
        {
            Node *newNode = new Node(temp->val);
            copyMap[temp] = newNode;
            temp = temp->next;
        }
        temp = head;
        while (temp != NULL)
        {
            Node *copyNode = copyMap[temp];
            copyNode->next = copyMap[temp->next];
            copyNode->random = copyMap[temp->random];
            temp = temp->next;
        }
        return copyMap[head];
    }
};
// @lc code=end
