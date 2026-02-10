/*
 * @lc app=leetcode id=203 lang=cpp
 *
 * [203] Remove Linked List Elements
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
#include <bits/stdc++.h>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution
{
public:
    ListNode *deleteNode(ListNode *curr, ListNode *prev)
    {
        prev->next = curr->next;
        curr->next = NULL;
        prev = curr;
        return prev;
    }
    ListNode *removeElements(ListNode *head, int val)
    {
        if (!head)
            return head;
        while (head != NULL && head->val == val)
        {
            head = head->next;
        }
        ListNode *curr = head;
        ListNode *prev = NULL;

        while (curr != NULL)
        {
            if (curr->val == val)
            {
                deleteNode(curr, prev);
                curr = prev->next;
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
