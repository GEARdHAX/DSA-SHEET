/*
 * @lc app=leetcode id=229 lang=cpp
 *
 * [229] Majority Element II
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> majorityElement(vector<int> &nums)
    {
        unordered_map<int, int> freq;
        vector<int> ans;
        int n = nums.size();
        for (auto i : nums)
            freq[i]++;
        for (auto it : freq)
        {
            if (it.second > n / 3)
            {
                // cout << it.first << " : " << it.second << endl;
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};
// @lc code=end

