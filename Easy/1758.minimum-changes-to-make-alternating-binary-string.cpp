/*
 * @lc app=leetcode id=1758 lang=cpp
 *
 * [1758] Minimum Changes To Make Alternating Binary String
 */

// @lc code=start
class Solution
{
public:
    int minOperations(string s)
    {

        stack<char> st;
        int count = 0;

        st.push(s[0]);

        for (int i = 1; i < s.size(); i++)
        {

            if (s[i] == st.top())
            {
                count++; // need operation
                st.push(st.top() == '0' ? '1' : '0');
            }
            else
            {
                st.push(s[i]);
            }
        }

        return count;
    }
};
// @lc code=end

