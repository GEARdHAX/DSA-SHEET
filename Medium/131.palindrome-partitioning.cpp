/*
 * @lc app=leetcode id=131 lang=cpp
 *
 * [131] Palindrome Partitioning
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool isPalindrome(string s)
    {
        string r = s;
        reverse(r.begin(), r.end());
        return s == r;
    }

    void solve(string s, vector<vector<string>> &ans, vector<string> &path)
    {
        // ✅ base case
        if (s.length() == 0)
        {
            ans.push_back(path);
            return;
        }

        // try all prefixes
        for (int i = 1; i <= s.length(); i++)
        {
            string prefix = s.substr(0, i);

            if (isPalindrome(prefix))
            {
                path.push_back(prefix);

                // recurse on remaining string
                solve(s.substr(i), ans, path);

                // backtrack
                path.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s)
    {
        vector<vector<string>> ans;
        vector<string> path;
        solve(s, ans, path);
        return ans;
    }
};

// @lc code=end

