/*
 * @lc app=leetcode id=121 lang=cpp
 *
 * [121] Best Time to Buy and Sell Stock
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int minPrice = prices[0];
        int maxProfit = 0;

        for (int currentPrice : prices)
        {
            minPrice = min(minPrice, currentPrice);
            maxProfit = max(maxProfit, currentPrice - minPrice);
        }

        return maxProfit;
    }
};

// @lc code=end

