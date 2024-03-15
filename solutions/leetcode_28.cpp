/*
 * 28. Find the Index of the First Occurrence in a String
 * https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/
 */

#include <iostream>
#include <string>

class Solution
{
public:
    int strStr(std::string haystack, std::string needle)
    {
        const int haystackLength = haystack.length();
        const int needleLength = needle.length();

        if (needleLength > haystackLength)
            return -1;

        for(int i = 0; i <= haystackLength - needleLength; ++i)
        {
            bool equal = true;
            for(int j = 0; j < needleLength; ++j)
            {
                if(haystack[i + j] != needle[j])
                {
                    equal = false;
                    break;
                }
            }

            if(equal)
            {
                return i;
            }
        }

        return -1;
    }
};

void test(const std::string& name, const std::string& haystack, const std::string& needle, int expected)
{
    Solution solution;
    int result = solution.strStr(haystack, needle);
    std::cout << name << ": " << (result == expected ? "Passed" : "Failed") << std::endl;
}

int main()
{
    test("Test 1", "sadbutsad", "sad", 0);
    test("Test 2", "leetcode", "leeto", -1);

    return 0;
}
