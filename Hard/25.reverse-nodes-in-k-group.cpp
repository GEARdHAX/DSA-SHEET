/*
 * @lc app=leetcode id=25 lang=cpp
 *
 * [25] Reverse Nodes in k-Group
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
class Solution
{
public:
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        // Base Case :-
        ListNode *temp = head;
        int cnt = 0;
        while (temp != NULL && cnt < k)
        {
            temp = temp->next;
            cnt++;
        }

        // If less than k nodes, do not reverse
        if (cnt < k)
        {
            return head;
        }
        if (head == NULL)
        {
            return NULL;
        };
        ListNode *prev = NULL;
        ListNode *curr = head;
        ListNode *next = NULL;
        int count = 0;
        while (curr != NULL && count < k)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count++;
        }
        if (next != NULL)
        {
            head->next = reverseKGroup(next, k);
        }
        return prev;
    }
};
// @lc code=end
