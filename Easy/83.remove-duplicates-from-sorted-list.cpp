/*
 * @lc app=leetcode id=83 lang=cpp
 *
 * [83] Remove Duplicates from Sorted List
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void deleteNode(ListNode *&curr, ListNode *&prev)
    {
        ListNode *temp = curr;
        prev->next = curr->next;
        curr = curr->next;
        delete temp;
    }

    ListNode *deleteDuplicates(ListNode *head)
    {
        if (head == NULL)
            return head;

        ListNode *prev = head;
        ListNode *curr = head->next;

        while (curr != NULL)
        {
            if (prev->val == curr->val)
            {
                deleteNode(curr, prev);
            }
            else
            {
                prev = curr;
                curr = curr->next;
            }
        }
        return head;
    }
};

// @lc code=end
