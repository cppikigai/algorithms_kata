/*
 * 125. Valid Palindrome
 * https://leetcode.com/problems/valid-palindrome/
 */

#include <iostream>
#include <string>

class Solution
{
public:
    bool isPalindrome(std::string s)
    {
        if (s.length() <= 1)
            return true;

        int left = 0;
        int right = s.length() - 1;

        while (left < right)
        {
            while (!isalnum(s[left]) && left < right)
            {
                ++left;
            }

            while (!isalnum(s[right]) && left < right)
            {
                --right;
            }

            if (tolower(s[left]) != tolower(s[right]))
            {
                return false;
            }

            ++left;
            --right;
        }

        return true;
    }
};

void test(const std::string& name, const std::string& s, bool expected)
{
    Solution solution;
    bool result = solution.isPalindrome(s);
    std::cout << name << ": " << (result == expected ? "Passed" : "Failed") << std::endl;
}

int main()
{
    test("Test 1", "A man, a plan, a canal: Panama", true);
    test("Test 2", "race a car", false);
    test("Test 3", " ", true);

    return 0;
}
