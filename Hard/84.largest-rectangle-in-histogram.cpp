/*
 * @lc app=leetcode id=84 lang=cpp
 *
 * [84] Largest Rectangle in Histogram
 */

// @lc code=start
class Solution
{
public:
    vector<int> nextSmallerElement(vector<int> &heights, int n)
    {
        stack<int> st;
        st.push(-1);
        vector<int> ans(n);

        for (int i = n - 1; i >= 0; i--)
        {
            int curr = heights[i];

            while (st.top() != -1 && heights[st.top()] >= curr)
            {
                st.pop();
            }

            ans[i] = st.top();
            st.push(i);
        }

        return ans;
    }

    vector<int> prevSmallerElement(vector<int> &heights, int n)
    {
        stack<int> st;
        st.push(-1);
        vector<int> ans(n);

        for (int i = 0; i < n; i++)
        {
            int curr = heights[i];

            while (st.top() != -1 && heights[st.top()] >= curr)
            {
                st.pop();
            }

            ans[i] = st.top();
            st.push(i);
        }

        return ans;
    }

    int largestRectangleArea(vector<int> &heights)
    {

        int n = heights.size();

        vector<int> next = nextSmallerElement(heights, n);
        vector<int> prev = prevSmallerElement(heights, n);

        int ans = 0;

        for (int i = 0; i < n; i++)
        {

            int l = heights[i];

            if (next[i] == -1)
                next[i] = n;

            int b = next[i] - prev[i] - 1;

            int area = l * b;

            ans = max(ans, area);
        }

        return ans;
    }
};
// @lc code=end
