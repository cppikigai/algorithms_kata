/*
 * 14. Longest Common Prefix
 * https://leetcode.com/problems/longest-common-prefix/
 */

#include <iostream>
#include <vector>
#include <string>

class Solution
{
public:
    std::string longestCommonPrefix(std::vector<std::string>& strs)
    {
        if (strs.empty()) return "";

        std::string prefix = strs[0];
        for (const std::string& str : strs)
        {
            while (str.find(prefix) != 0)
            {
                prefix = prefix.substr(0, prefix.length() - 1);
                if (prefix.empty()) return "";
            }
        }

        return prefix;
    }
};

void test(const std::string& name, std::vector<std::string>& strs, const std::string& expected)
{
    Solution solution;
    std::string result = solution.longestCommonPrefix(strs);
    std::cout << name << ": " << (result == expected ? "Passed" : "Failed") << std::endl;
}

int main()
{
    std::vector<std::string> test1 = {"flower", "flow", "flight"};
    test("Test 1", test1, "fl");

    std::vector<std::string> test2 = {"dog", "racecar", "car"};
    test("Test 2", test2, "");

    return 0;
}
