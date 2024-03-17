/*
 * 290. Word Pattern
 * https://leetcode.com/problems/word-pattern/
 */

#include <iostream>
#include <unordered_map>
#include <sstream>
#include <vector>

class Solution
{
public:
    bool wordPattern(std::string pattern, std::string s)
    {
        std::unordered_map<char, std::string> charToWord;
        std::unordered_map<std::string, char> wordToChar;

        std::istringstream iss(s);
        std::string word;
        std::vector<std::string> words;

        while (iss >> word)
        {
            words.push_back(word);
        }

        if (pattern.length() != words.size())
        {
            return false;
        }

        for (int i = 0; i < pattern.length(); ++i)
        {
            char ch = pattern[i];
            word = words[i];

            if (charToWord.find(ch) == charToWord.end() && wordToChar.find(word) == wordToChar.end())
            {
                charToWord[ch] = word;
                wordToChar[word] = ch;
            }
            else
            {
                if (charToWord[ch] != word || wordToChar[word] != ch)
                {
                    return false;
                }
            }
        }

        return true;
    }
};

void test(const std::string& name, std::string pattern, std::string s, bool expected)
{
    Solution solution;
    bool result = solution.wordPattern(pattern, s);
    std::cout << name << ": " << (result == expected ? "Passed" : "Failed") << std::endl;
}

int main()
{
    test("Test 1", "abba", "dog cat cat dog", true);
    test("Test 2", "abba", "dog cat cat fish", false);
    test("Test 3", "aaaa", "dog cat cat dog", false);

    return 0;
}
