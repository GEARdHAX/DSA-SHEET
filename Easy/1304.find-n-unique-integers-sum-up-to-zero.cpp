/*
 * @lc app=leetcode id=1304 lang=cpp
 *
 * [1304] Find N Unique Integers Sum up to Zero
 */

// @lc code=start
class Solution
{
public:
    vector<int> sumZero(int n)
    {
        vector<int> ans;
        if (n % 2 == 0)
        {
            n /= 2;
            for (int i = 1; i <= n; i++)
            {
                ans.push_back(i);
                ans.push_back(-i);
            }
        }
        else
        {
            n /= 2;
            ans.push_back(0);
            for (int i = 1; i <= n; i++)
            {
                ans.push_back(i);
                ans.push_back(-i);
            }
        }
        return ans;
    }
};
// @lc code=end
