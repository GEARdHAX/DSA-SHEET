#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string reverse(const string &S)
    {
        stack<char> st;
        for (auto i : S)
        {
            st.push(i);
        }
        string ans = "";
        while (!st.empty())
        {
            ans += st.top();
            st.pop();
        }
        return ans;
    }
};