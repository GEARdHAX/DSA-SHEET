/*
 * @lc app=leetcode id=35 lang=cpp
 *
 * [35] Search Insert Position
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int binarySearch(vector<int> &nums, int target, int left, int right)
    {
        if (left > right)
        {
            return left; // insert position
        }

        int mid = left + (right - left) / 2;

        if (nums[mid] == target)
        {
            return mid;
        }
        else if (nums[mid] < target)
        {
            return binarySearch(nums, target, mid + 1, right);
        }
        else
        {
            return binarySearch(nums, target, left, mid - 1);
        }
    }

    int searchInsert(vector<int> &nums, int target)
    {
        return binarySearch(nums, target, 0, nums.size() - 1);
    }
};

// @lc code=end

