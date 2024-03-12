/*
 * 383. Ransom Note
 * https://leetcode.com/problems/ransom-note/
 */

#include <iostream>

bool canConstruct(std::string ransomNote, std::string magazine)
{
    constexpr short offset = static_cast<short>('a');
    short dict[26]{0};
    for(const char& ch : magazine)
    {
        ++dict[static_cast<short>(ch) - offset];
    }
    
    for(const char& ch : ransomNote)
    {
        short index = static_cast<short>(ch) - offset;
        if(dict[index] == 0)
            return false;
        --dict[index];
    }

    return true;
}

void test(const std::string& name, const std::string& ransomNote, const std::string& magazine, bool expected)
{
    bool result = canConstruct(ransomNote, magazine);
    std::cout << name << ": " << (result == expected ? "Passed" : "Failed") << std::endl;
}

int main()
{
    test("Test 1", "a", "b", false);
    test("Test 2", "aa", "ab", false);
    test("Test 3", "aa", "aab", true);
}