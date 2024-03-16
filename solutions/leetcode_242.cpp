/*
 * 242. Valid Anagram
 * https://leetcode.com/problems/valid-anagram/
 */

#include <iostream>
#include <string>

class Solution
{
public:
    bool isAnagram(std::string s, std::string t)
    {
        const int alphabetSize = 26;

        if (s.size() != t.size())
            return false;

        int sFrequency[alphabetSize] = {0};
        int tFrequency[alphabetSize] = {0};

        for (int i = 0; i < s.size(); ++i)
        {
            ++sFrequency[s[i] - 'a'];
            ++tFrequency[t[i] - 'a'];
        }

        for (int i = 0; i < alphabetSize; ++i)
        {
            if (sFrequency[i] != tFrequency[i])
            {
                return false;
            }
        }

        return true;
    }
};

void test(const std::string& name, const std::string& s, const std::string& t, bool expected)
{
    Solution solution;
    bool result = solution.isAnagram(s, t);
    std::cout << name << ": " << (result == expected ? "Passed" : "Failed") << std::endl;
}

int main()
{
    test("Test 1", "anagram", "nagaram", true);
    test("Test 2", "rat", "car", false);

    return 0;
}
