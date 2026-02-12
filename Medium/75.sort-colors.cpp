/*
 * @lc app=leetcode id=75 lang=cpp
 *
 * [75] Sort Colors
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        map<int, int> count;
        for (auto i : nums)
        {
            count[i]++;
        }
        int index = 0;
        for (auto i : count)
        {
            int value = i.first;
            int freq = i.second;
            while (freq--)
            {
                nums[index] = value;
                index++;
            }
        }
        // return nums;
    }
};
// @lc code=end

