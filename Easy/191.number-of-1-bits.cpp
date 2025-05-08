/*
 * @lc app=leetcode id=191 lang=cpp
 *
 * [191] Number of 1 Bits
 */
// ⌚ Time Complexity : O(log n)
// 🚀 Space Complexity : O(1);
// ❓ Link : https://leetcode.com/problems/number-of-1-bits/description/
//  @lc code=start

class Solution
{
public:
    int hammingWeight(int n)
    {
        int count = 0;
        while (n != 0)
        {
            count += n & 1; // Check if the last bit is 1
            n >>= 1;
        }
        return count;
    }
};
// @lc code=end
