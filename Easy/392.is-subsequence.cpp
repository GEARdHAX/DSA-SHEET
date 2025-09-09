/*
 * @lc app=leetcode id=392 lang=cpp
 *
 * [392] Is Subsequence
 */

// @lc code=start
class Solution
{
public:
    bool isSubsequence(string s, string t)
    {
        int index = 0; // where we are in t

        for (auto ch : s)
        {
            bool found = false; // reset for each character in s

            for (int j = index; j < t.length(); j++)
            {
                
                if (ch == t[j])
                {
                    found = true;
                    index = j + 1; // move past this character in t
                    break;
                }
            }

            if (!found)
            {
                return false; // current character not found → not a subsequence
            }
        }

        return true; // all characters found in order
    }
};


// @lc code=end
