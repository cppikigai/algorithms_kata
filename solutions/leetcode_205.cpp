/*
 * 205. Isomorphic Strings
 * https://leetcode.com/problems/isomorphic-strings/
 */
#include <iostream>
#include <string>
#include <unordered_map>

class Solution
{
public:
    bool isIsomorphic(std::string s, std::string t)
    {
        if (s.length() != t.length()) return false;
        
        int sToTMap[128] = {0}; // Mapping from characters in s to characters in t
        int tMapped[128] = {0}; // Keep track of characters in t that have been mapped from s

        int length = s.size();
        for (int i = 0; i < length; ++i)
        {
            if (sToTMap[s[i]] != tMapped[t[i]]) 
                return false;
            
            sToTMap[s[i]] = i + 1;
            tMapped[t[i]] = i + 1;
        }

        return true;    
    }
    /*
    bool isIsomorphic(std::string s, std::string t)
    {
        if (s.length() != t.length()) return false;

        std::unordered_map<char, char> sToTMap;
        std::unordered_map<char, bool> tMapped;

        for (int i = 0; i < s.length(); ++i)
        {
            char sChar = s[i];
            char tChar = t[i];

            if (sToTMap.find(sChar) != sToTMap.end())
            {
                if (sToTMap[sChar] != tChar)
                    return false;
            }
            else
            {
                if (tMapped[tChar])
                    return false;

                sToTMap[sChar] = tChar;
                tMapped[tChar] = true;
            }
        }

        return true;
    }
    */
};

void test(const std::string& name, const std::string& s, const std::string& t, bool expected)
{
    Solution solution;
    bool result = solution.isIsomorphic(s, t);
    std::cout << name << ": " << (result == expected ? "Passed" : "Failed") << std::endl;
}

int main()
{
    test("Test 1", "egg", "add", true);
    test("Test 2", "foo", "bar", false);
    test("Test 3", "paper", "title", true);
    test("Test 4", "badc", "baba", false);

    return 0;
}