/*
 * @lc app=leetcode id=160 lang=cpp
 *
 * [160] Intersection of Two Linked Lists
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
;
#include <bits/stdc++.h>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        map<ListNode *, bool> visited;
        while (headA != NULL)
        {
            visited[headA] = true;
            headA = headA->next;
        }
        while (headB != NULL)
        {
            if (visited[headB])
            {
                return headB;
            }
            else
            {
                headB = headB->next;
            }
        }
        return NULL;
    }
};
// @lc code=end
