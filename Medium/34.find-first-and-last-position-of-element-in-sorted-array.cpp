/*
 * @lc app=leetcode id=34 lang=cpp
 *
 * [34] Find First and Last Position of Element in Sorted Array
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int findFirst(vector<int> &nums, int target, int left, int right)
    {
        if (left > right)
            return -1;

        int mid = left + (right - left) / 2;

        if (nums[mid] == target)
        {
            int leftAns = findFirst(nums, target, left, mid - 1);
            return (leftAns == -1) ? mid : leftAns;
        }
        else if (nums[mid] < target)
        {
            return findFirst(nums, target, mid + 1, right);
        }
        else
        {
            return findFirst(nums, target, left, mid - 1);
        }
    }

    int findLast(vector<int> &nums, int target, int left, int right)
    {
        if (left > right)
            return -1;

        int mid = left + (right - left) / 2;

        if (nums[mid] == target)
        {
            int rightAns = findLast(nums, target, mid + 1, right);
            return (rightAns == -1) ? mid : rightAns;
        }
        else if (nums[mid] < target)
        {
            return findLast(nums, target, mid + 1, right);
        }
        else
        {
            return findLast(nums, target, left, mid - 1);
        }
    }

    vector<int> searchRange(vector<int> &nums, int target)
    {
        int n = nums.size();
        int first = findFirst(nums, target, 0, n - 1);
        int last = findLast(nums, target, 0, n - 1);
        return {first, last};
    }
};

// @lc code=end
