/*
 * @lc app=leetcode id=71 lang=cpp
 *
 * [71] Simplify Path
 */

// @lc code=start
class Solution
{
public:
    string simplifyPath(string path)
    {
        stringstream ss(path);
        string token;

        vector<string> output;
        while (getline(ss, token, '/'))
        {
            if (token == ".." && !output.empty())
            {
                output.pop_back();
            }
            else if (token != "" && token != "." && token != "..")
            {
                output.push_back(token);
            }
        }
        string ans = "";
        for (auto i : output)
        {
            ans.append("/");
            ans.append(i);
        }
        return output.size() == 0 ? "/" : ans;
    }
};
// @lc code=end
