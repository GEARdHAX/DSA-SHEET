/*
 * @lc app=leetcode id=7 lang=cpp
 *
 * [7] Reverse Integer
 */

// ⌚ Time Complexity : O(log n)
// 🚀 Space Complexity : O(1)
// ❓ Link : https://leetcode.com/problems/reverse-integer/description/

// @lc code=start
class Solution
{
public:
    int reverse(int x)
    {
        int revNum = 0;
        while (x != 0)
        {
            int digit = x % 10;
            if ((revNum > INT_MAX / 10) || (revNum < INT_MIN / 10))
            {
                return 0;
            }
            revNum = (10 * revNum) + digit;

            x /= 10;
        }

        return revNum;
    }
};
// @lc code=end
