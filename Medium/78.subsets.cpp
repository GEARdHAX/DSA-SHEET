/*
 * @lc app=leetcode id=78 lang=cpp
 *
 * [78] Subsets
 */

// @lc code=start

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void set(vector<int> &nums, vector<int> output, int index,
             vector<vector<int>> &ans)
    {

        // base case
        if (index == nums.size())
        {
            ans.push_back(output);
            return;
        }

        // excluding current element
        set(nums, output, index + 1, ans);

        // including current element
        output.push_back(nums[index]);
        set(nums, output, index + 1, ans);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> output;
        set(nums, output, 0, ans);
        return ans;
    }
};
// @lc code=end

