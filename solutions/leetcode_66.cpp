/*
 * 66. Plus One
 * https://leetcode.com/problems/plus-one/
 */

#include <iostream>
#include <vector>

class Solution
{
public:
    std::vector<int> plusOne(std::vector<int>& digits)
    {
        for(int i = digits.size() - 1; i >= 0; --i)
        {
            if(digits[i] < 9)
            {
                ++digits[i];
                break;
            }
            else
            {
                digits[i] = 0;
            }
        }

        if(digits[0] == 0)
        {
            digits.insert(digits.begin(), 1);
        }

        return digits;
    }
};

void test(const std::string& name, std::vector<int>& digits, std::vector<int>& expected)
{
    Solution solution;
    std::vector<int> result = solution.plusOne(digits);
    std::cout << name << ": " << (result == expected ? "Passed" : "Failed") << std::endl;
}

int main()
{
    std::vector<int> testDigits1 = {1, 2, 3};
    std::vector<int> testExpected1 = {1, 2, 4};
    test("Test 1", testDigits1, testExpected1);

    std::vector<int> testDigits2 = {4, 3, 2, 1};
    std::vector<int> testExpected2 = {4, 3, 2, 2};
    test("Test 2", testDigits2, testExpected2);

    std::vector<int> testDigits3 = {9};
    std::vector<int> testExpected3 = {1, 0};
    test("Test 3", testDigits3, testExpected3);

    return 0;
}
