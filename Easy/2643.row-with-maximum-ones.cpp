/*
 * @lc app=leetcode id=2643 lang=cpp
 *
 * [2643] Row With Maximum Ones
 */

// @lc code=start
class Solution
{
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>> &mat)
    {
        vector<int> ans;
        int rows = mat.size();
        int cols = mat[0].size();

        int maxCount = -1;
        int rowNum = -1;

        for (int i = 0; i < rows; i++)
        {
            int count = 0; // reset count for each row
            for (int j = 0; j < cols; j++)
            {
                if (mat[i][j] == 1)
                {
                    count++;
                }
            }
            if (count > maxCount)
            {
                maxCount = count;
                rowNum = i;
            }
        }

        ans.push_back(rowNum);
        ans.push_back(maxCount);
        return ans;
    }
};
// @lc code=end
