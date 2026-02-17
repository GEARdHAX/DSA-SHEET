/*
 * @lc app=leetcode id=682 lang=cpp
 *
 * [682] Baseball Game
 */

// @lc code=start
class Solution
{
public:
    int calPoints(vector<string> &operations)
    {
        int score = 0;
        stack<int> st; // ✅ FIXED

        for (int i = 0; i < operations.size(); i++)
        {

            if (operations[i] == "C")
            {
                st.pop();
            }
            else if (operations[i] == "D")
            {
                st.push(2 * st.top());
            }
            else if (operations[i] == "+")
            {
                int a = st.top();
                st.pop();
                int b = st.top();
                st.push(a);
                st.push(a + b); // ✅ FIXED
            }
            else
            {
                st.push(stoi(operations[i])); // ✅ FIXED
            }
        }

        while (!st.empty())
        {
            score += st.top();
            st.pop();
        }

        return score;
    }
};

// @lc code=end
