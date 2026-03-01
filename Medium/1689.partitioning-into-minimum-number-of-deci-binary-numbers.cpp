/*
 * @lc app=leetcode id=1689 lang=cpp
 *
 * [1689] Partitioning Into Minimum Number Of Deci-Binary Numbers
 */

// @lc code=start
class Solution
{
public:
    int minPartitions(string n)
    {
        int ans = 0;
        for (auto x : n)
        {
            int curr = x - 48;
            ans = max(ans, curr);
        }
        return ans;
    }
};
// @lc code=end

