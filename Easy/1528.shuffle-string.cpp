/*
 * @lc app=leetcode id=1528 lang=cpp
 *
 * [1528] Shuffle String
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string restoreString(string s, vector<int> &indices)
    {
        vector<char> ans(s.size());
        for (int i = 0; i < s.size(); i++)
        {
            ans[indices[i]] = s[i];
        }
        string result(ans.begin(), ans.end());
        return result;
    }
};
// @lc code=end
