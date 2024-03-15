/*
 * 1. Two Sum
 * https://leetcode.com/problems/two-sum/
 */
#include <iostream>
#include <vector>
#include <unordered_map>

class Solution
{
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target)
    {
        std::unordered_map<int, int> numIndexMap;
        std::vector<int> result;

        for (int i = 0; i < nums.size(); ++i)
        {
            int complement = target - nums[i];
            if (numIndexMap.find(complement) != numIndexMap.end())
            {
                result.push_back(numIndexMap[complement]);
                result.push_back(i);
                break;
            }
            numIndexMap[nums[i]] = i;
        }

        return result;
    }
};

void test(const std::string& name, std::vector<int>& nums, int target, std::vector<int>& expected)
{
    Solution solution;
    std::vector<int> result = solution.twoSum(nums, target);
    std::cout << name << ": " << (result == expected ? "Passed" : "Failed") << std::endl;
}

int main()
{
    std::vector<int> testNums1 = {2, 7, 11, 15};
    std::vector<int> testExpected1 = {0, 1};
    test("Test 1", testNums1, 9, testExpected1);

    std::vector<int> testNums2 = {3, 2, 4};
    std::vector<int> testExpected2 = {1, 2};
    test("Test 2", testNums2, 6, testExpected2);

    std::vector<int> testNums3 = {3, 3};
    std::vector<int> testExpected3 = {0, 1};
    test("Test 3", testNums3, 6, testExpected3);

    return 0;
}
