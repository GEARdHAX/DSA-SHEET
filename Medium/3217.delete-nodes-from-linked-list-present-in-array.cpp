/*
 * @lc app=leetcode id=3217 lang=cpp
 *
 * [3217] Delete Nodes From Linked List Present in Array
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
    ListNode *modifiedList(vector<int> &nums, ListNode *head)
    {
        if (!head || head->next == NULL)
        {
            return head;
        }
        map<int, int> freq;
        for (auto i : nums)
        {
            freq[i]++;
        }
        ListNode *dummy = new ListNode(0);
        ListNode *tail = dummy;

        ListNode *temp = head;
        while (temp != NULL)
        {
            if (freq[temp->val] == 0)
            {
                tail->next = new ListNode(temp->val);
                tail = tail->next;
            }
            temp = temp->next;
        }
        return dummy->next;
    }
};
// @lc code=end

