/*
 * @lc app=leetcode id=85 lang=cpp
 *
 * [85] Maximal Rectangle
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

    int maximalRectangle(vector<vector<char>> &matrix)
    {
        if (matrix.empty())
            return 0;
        int n = matrix[0].size();
        vector<int> heights(n, 0);
        int maxArea = 0;

        for (int i = 0; i < matrix.size(); i++)
        {

            for (int j = 0; j < n; j++)
            {

                if (matrix[i][j] == '1')
                    heights[j] += 1;
                else
                    heights[j] = 0;
            }

            maxArea = max(maxArea, largestRectangleArea(heights));
        }

        return maxArea;
    }
};
// @lc code=end
