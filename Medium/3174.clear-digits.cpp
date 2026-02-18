/*
 * @lc app=leetcode id=3174 lang=cpp
 *
 * [3174] Clear Digits
 */

// @lc code=start
class Solution
{
public:
    string clearDigits(string s)
    {
        for (int i = 0; i < s.size();)
        {
            if (isdigit(s[i]) && i > 0)
            {
                s.erase(i - 1, 2);
                i--;
            }
            else
            {
                i++;
            }
        }
        return s;
    }
};
// @lc code=end

