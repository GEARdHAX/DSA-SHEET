/*
 * @lc app=leetcode id=387 lang=cpp
 *
 * [387] First Unique Character in a String
 */

// @lc code=start
class Solution
{
public:
    int firstUniqChar(string s)
    {
        map<char, int> freq;

        // Count frequency
        for (char c : s)
            freq[c]++;

        // Find first non-repeating character
        for (int i = 0; i < s.length(); i++)
        {
            if (freq[s[i]] == 1)
            {
                // cout << i;
                return i;
            }
        }
        return -1;
    }
};
// @lc code=end
