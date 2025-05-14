/*
 * @lc app=leetcode id=231 lang=cpp
 *
 * [231] Power of Two
 */
//⌚ Time Complexity : O(log n)
//🚀 Space Complexity : O(1)
//❓ Link : https://leetcode.com/problems/power-of-two/description
// @lc code=start
class Solution
{
public:
    bool isPowerOfTwo(int n)
    {
        if (n == 0)
        {
            return false;
        }

        double c = ceil(log2(n));
        double f = floor(log2(n));
        return c == f;
    }
};
// @lc code=end
