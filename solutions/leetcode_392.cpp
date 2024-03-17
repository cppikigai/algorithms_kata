/*
 * 392. Is Subsequence
 * https://leetcode.com/problems/is-subsequence/
 */

#include <iostream>
#include <string>

class Solution
{
public:
    bool isSubsequence(std::string s, std::string t)
    {
        int sIndex = 0;
        int tIndex = 0;

        while (sIndex < s.length() && tIndex < t.length())
        {
            if (s[sIndex] == t[tIndex])
            {
                ++sIndex;
            }
            ++tIndex;
        }

        return sIndex == s.length();
    }
};

void test(const std::string& name, std::string s, std::string t, bool expected)
{
    Solution solution;
    bool result = solution.isSubsequence(s, t);
    std::cout << name << ": " << (result == expected ? "Passed" : "Failed") << std::endl;
}

int main()
{
    test("Test 1", "abc", "ahbgdc", true);
    test("Test 2", "axc", "ahbgdc", false);

    return 0;
}
