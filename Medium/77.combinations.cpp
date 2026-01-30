/*
 * @lc app=leetcode id=77 lang=cpp
 *
 * [77] Combinations
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void solve(vector<vector<int>> &ans, int n, int k, int start,
               vector<int> &path)
    {
        // base case :-
        if (path.size() == k)
        {
            ans.push_back(path);
            return;
        }

        for (int i = start; i <= n; i++)
        {
            path.push_back(i);
            solve(ans, n, k, i + 1, path);
            path.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k)
    {
        vector<vector<int>> ans;
        vector<int> path;
        solve(ans, n, k, 1, path);
        return ans;
    }
};
// @lc code=end
