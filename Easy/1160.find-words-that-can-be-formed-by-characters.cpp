/*
 * @lc app=leetcode id=1160 lang=cpp
 *
 * [1160] Find Words That Can Be Formed by Characters
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int countCharacters(vector<string> &words, string chars)
    {
        unordered_map<char, int> freq;
        for (auto c : chars)
        {
            freq[c]++;
        }
        int sum = 0;
        for (int i = 0; i < words.size(); i++)
        {
            unordered_map<char, int> count;
            for (auto c : words[i])
            {
                count[c]++;
            }
            bool flag = true;
            for (auto it : count)
            {
                if (it.second > freq[it.first])
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
            {
                sum += words[i].size();
            }
        }
        return sum;
    }
};
// @lc code=end
