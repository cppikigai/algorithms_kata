/*
 * 9. Palindrome Number
 * https://leetcode.com/problems/palindrome-number/
 */

#include <iostream>

class Solution
{
public:
    bool isPalindrome(int x)
    {
        if (x < 0 || (x % 10 == 0 && x != 0))
        {
            return false;
        }
        
        if(x < 10)
        {
            return true;
        }

        int reversed = 0;
        while (x > reversed)
        {
            reversed = reversed * 10 + x % 10;
            x /= 10;
        }

        return x == reversed || x == reversed / 10;
    }
};

void test(const std::string& name, int x, bool expected)
{
    Solution solution;
    bool result = solution.isPalindrome(x);
    std::cout << name << ": " << (result == expected ? "Passed" : "Failed") << std::endl;
}

int main()
{
    test("Test 1", 121, true);
    test("Test 2", -121, false);
    test("Test 3", 10, false);

    return 0;
}
