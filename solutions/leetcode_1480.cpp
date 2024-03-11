/*
 * 1480. Running Sum of 1d Array
 * https://leetcode.com/problems/running-sum-of-1d-array/
 */

#include <iostream>
#include <vector>

std::vector<int> runningSum(std::vector<int>& nums)
{
    for(size_t i = 1; i < nums.size(); ++i)
    {
        nums[i] += nums[i - 1];
    }

    return nums;
}

void test(const std::string& name, const std::vector<int>& nums, const std::vector<int>& expected)
{
    std::vector<int> copyNums = nums; // copying for only simplify filling tests
    std::cout << name << ": " << (runningSum(copyNums) == expected ? "Passed" : "Failed") << std::endl; 
}

int main()
{
    test("Test 1", { 1, 2, 3, 4 }, { 1, 3, 6, 10 });
    test("Test 2", { 1, 1, 1, 1, 1}, { 1, 2, 3, 4, 5 });
    test("Test 3", { 3, 1, 2, 10, 1 }, { 3, 4, 6, 16, 17});
}
