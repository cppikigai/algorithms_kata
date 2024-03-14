/*
 * 58. Length of Last Word
 * https://leetcode.com/problems/length-of-last-word/
 */

#include <iostream>
#include <string>

class Solution
{
public:
    int lengthOfLastWord(std::string s)
    {
        int length = 0;
        for (int i = s.size() - 1; i >= 0; --i)
        {
            if (s[i] != ' ')
            {
                ++length;
            }
            else if (length > 0)
            {
                break;
            }
        }

        return length;
    }
};

void test(const std::string& name, const std::string& s, int expected)
{
    Solution solution;
    int result = solution.lengthOfLastWord(s);
    std::cout << name << ": " << (result == expected ? "Passed" : "Failed") << std::endl;
}

int main()
{
    test("Test 1", "Hello World", 5);
    test("Test 2", "   fly me   to   the moon  ", 4);
    test("Test 3", "luffy is still joyboy", 6);

    return 0;
}
