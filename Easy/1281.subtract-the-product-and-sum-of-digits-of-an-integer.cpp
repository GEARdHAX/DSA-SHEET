/*
 * @lc app=leetcode id=1281 lang=cpp
 *
 * [1281] Subtract the Product and Sum of Digits of an Integer
 */

// @lc code=start

// ⌚ Time Complexity = O(log n)
// 🚀 Space Complexity = O(1)
// ❓ Link = https://leetcode.com/problems/subtract-the-product-and-sum-of-digits-of-an-integer/description/

class Solution
{
public:
    int subtractProductAndSum(int n)
    {
        int product = 1;
        int sum = 0;
        while (n > 0)
        {
            int newNum = n % 10;
            product *= newNum;
            sum += newNum;
            n /= 10;
        }
        return product - sum;
    }
};
// @lc code=end
