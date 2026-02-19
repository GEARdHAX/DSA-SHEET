/*
 * @lc app=leetcode id=14 lang=cpp
 *
 * [14] Longest Common Prefix
 */

// @lc code=start
class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        string news = strs[0];

        for (int i = 1; i < strs.size(); i++)
        {
            string ans = "";
            for (int j = 0; j < news.size() && j < strs[i].size(); j++)
            {
                if (news[j] == strs[i][j])
                {
                    ans += news[j];
                }
                else
                {
                    break;
                }
            }
            news = ans;
            if (news == "")
                return "";
        }
        return news;
    }
};
// @lc code=end

