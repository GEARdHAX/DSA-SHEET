/*
 * @lc app=leetcode id=17 lang=cpp
 *
 * [17] Letter Combinations of a Phone Number
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void phone(vector<string>& ans, string output, string digits, int index, string mapping[])
    {
        if (index == digits.size())
        {
            ans.push_back(output);
            return;
        }
        int digit = digits[index] - '0';
        string value = mapping[digit];
        for (int i = 0; i < value.size(); i++)
        {
            output.push_back(value[i]);
            phone(ans, output, digits, index + 1, mapping);
            output.pop_back();
        }
    }
    vector<string> letterCombinations(string digits)
    {
        vector<string> ans;
        if (digits.size() == 0)
        {
            return ans;
        }
        string combination = "";
        string output = "";
        int index = 0;
        string mapping[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        phone(ans, output, digits, index, mapping);
        return ans;
    }
};
// @lc code=end
