/*
 * @lc app=leetcode id=2095 lang=cpp
 *
 * [2095] Delete the Middle Node of a Linked List
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
    int getLength(ListNode *head)
    {
        int len = 0;
        ListNode *temp = head;
        while (temp != NULL)
        {
            len++;
            temp = temp->next;
        }
        return len;
    }
    ListNode *deleteMiddle(ListNode *head)
    {
        if (head->next == NULL || !head)
        {
            return nullptr;
        }
        ListNode *curr = head;
        ListNode *prev = nullptr;
        int mid = getLength(head) / 2;
        int count = 0;
        while (count < mid)
        {
            prev = curr;
            curr = curr->next;
            count++;
        }
        prev->next = curr->next;
        curr->next = nullptr;
        delete curr;
        return head;
    }
};
// @lc code=end

