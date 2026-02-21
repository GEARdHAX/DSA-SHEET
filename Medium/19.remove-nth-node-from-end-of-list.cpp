/*
 * @lc app=leetcode id=19 lang=cpp
 *
 * [19] Remove Nth Node From End of List
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
        int length = 0;
        ListNode *temp = head;
        while (temp != NULL)
        {
            length++;
            temp = temp->next;
        }
        return length;
    }

    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        int length = getLength(head);

        // Case: delete head
        if (n == length)
        {
            ListNode *temp = head;
            head = head->next;
            delete temp;
            return head;
        }

        ListNode *curr = head;
        ListNode *prev = NULL;
        int range = length - n;
        int count = 0;

        while (count < range)
        {
            prev = curr;
            curr = curr->next;
            count++;
        }

        prev->next = curr->next;
        delete curr;

        return head;
    }
};
// @lc code=end

