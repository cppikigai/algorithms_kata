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
    std::vector<int> test1_nums = {2, 7, 11, 15};
    std::vector<int> test1_expected = {0, 1};
    test("Test 1", test1_nums, 9, test1_expected);

    std::vector<int> test2_nums = {3, 2, 4};
    std::vector<int> test2_expected = {1, 2};
    test("Test 2", test2_nums, 6, test2_expected);

    std::vector<int> test3_nums = {3, 3};
    std::vector<int> test3_expected = {0, 1};
    test("Test 3", test3_nums, 6, test3_expected);

    return 0;
}
