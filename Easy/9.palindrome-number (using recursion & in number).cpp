/*
 * @lc app=leetcode id=9 lang=cpp
 *
 * [9] Palindrome Number - Using Recursion + Modification in numbers
 */

// @lc code=start
class Solution
{
public:
    long long reverseNumber(long long x, long long rev = 0)
    {
        if (x == 0)
            return rev;
        return reverseNumber(x / 10, rev * 10 + x % 10);
    }

    bool isPalindrome(int x)
    {
        if (x < 0)
            return false;

        long long rev = reverseNumber(x);
        return x == rev;
    }
};

// @lc code=end

