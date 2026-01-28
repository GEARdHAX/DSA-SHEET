/*
 * @lc app=leetcode id=2114 lang=cpp
 *
 * [2114] Maximum Number of Words Found in Sentences
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int mostWordsFound(vector<string> &sentences)
    {
        int words = 0;
        for (int i = 0; i < sentences.size(); i++)
        {
            int count = 1;
            vector<char> chars(sentences[i].begin(), sentences[i].end());
            for (auto c : chars)
            {
                if (c == ' ')
                    count++;
            }
            if (count > words)
            {
                words = count;
            }
        }
        return words;
    }
};
// @lc code=end
