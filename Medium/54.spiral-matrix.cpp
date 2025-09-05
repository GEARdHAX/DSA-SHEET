/*
 * @lc app=leetcode id=54 lang=cpp
 *
 * [54] Spiral Matrix
 */

// @lc code=start
class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        vector<int> ans;
        int rows = matrix.size();
        int cols = matrix[0].size();

        int count = 0;
        int total = rows * cols;

        int startingRow = 0;
        int startingCol = 0;
        int endingRow = rows - 1;
        int endingCol = cols - 1;

        while (count < total)
        {
            // Starting Row
            for (int i = startingCol; count < total && i <= endingCol; i++)
            {
                ans.push_back(matrix[startingRow][i]);
                count++;
            }
            startingRow++;
            // Ending Col
            for (int i = startingRow; count < total && i <= endingRow; i++)
            {
                ans.push_back(matrix[i][endingCol]);
                count++;
            }
            endingCol--;
            // Ending Row
            for (int i = endingCol; count < total && i >= startingCol; i--)
            {
                ans.push_back(matrix[endingRow][i]);
                count++;
            }
            endingRow--;
            // Reverse Starting Row
            for (int i = endingRow; count < total && i >= startingRow; i--)
            {
                ans.push_back(matrix[i][startingCol]);
                count++;
            }
            startingCol++;
        }
        return ans;
    }
};
// @lc code=end

