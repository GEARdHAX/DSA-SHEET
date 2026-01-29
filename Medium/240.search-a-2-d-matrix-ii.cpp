/*
 * @lc app=leetcode id=240 lang=cpp
 *
 * [240] Search a 2D Matrix II
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int rows = matrix.size();
        int cols = matrix[0].size();

        int r = 0;
        int c = cols - 1;

        while (r < rows && c >= 0)
        {
            if (matrix[r][c] == target)
                return true;
            else if (matrix[r][c] > target)
                c--; // move left
            else
                r++; // move down
        }
        return false;
    }
};

// @lc code=end
