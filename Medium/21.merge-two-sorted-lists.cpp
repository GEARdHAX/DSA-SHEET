/*
 * @lc app=leetcode id=21 lang=cpp
 *
 * [21] Merge Two Sorted Lists
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
class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {

        if (list1 == NULL)
            return list2;
        if (list2 == NULL)
            return list1;

        ListNode *slow = list1;
        ListNode *fast = list2;

        ListNode *newNode = NULL; // head of merged list
        ListNode *tail = NULL;    // last node of merged list

        while (slow != NULL && fast != NULL)
        {

            ListNode *chosen;

            if (slow->val <= fast->val)
            {
                chosen = slow;
                slow = slow->next;
            }
            else
            {
                chosen = fast;
                fast = fast->next;
            }

            // first node case
            if (newNode == NULL)
            {
                newNode = chosen;
                tail = chosen;
            }
            else
            {
                tail->next = chosen;
                tail = tail->next;
            }
        }

        // attach remaining nodes
        if (slow != NULL)
            tail->next = slow;
        else
            tail->next = fast;

        return newNode;
    }
};

// @lc code=end

