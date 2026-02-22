/*
 * @lc app=leetcode id=1290 lang=cpp
 *
 * [1290] Convert Binary Number in a Linked List to Integer
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
    int decimal(string ans)
    {
        int decimal = 0;
        for (char bit : ans)
        {
            decimal = decimal * 2 + (bit - '0');
        }
        return decimal;
    }
    int getDecimalValue(ListNode *head)
    {
        if (!head || head->next == NULL)
        {
            return head->val;
        }
        ListNode *temp = head;
        string ans = "";
        while (temp != NULL)
        {
            ans += char(temp->val + '0');
            temp = temp->next;
        }
        return decimal(ans);
    }
};
// @lc code=end
