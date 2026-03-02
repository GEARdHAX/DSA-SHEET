/*
 * @lc app=leetcode id=462 lang=cpp
 *
 * [462] Minimum Moves to Equal Array Elements II
 */

// @lc code=start
class Solution
{
public:
    int minMoves2(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int size = nums.size();
        int mid = nums[size / 2];
        int moves = 0;
        for (auto x : nums)
        {
            moves += abs(x - mid);
        }
        return moves;
    }
};
// @lc code=end
