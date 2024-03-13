/*
 * 26. Remove Duplicates from Sorted Array
 * https://leetcode.com/problems/remove-duplicates-from-sorted-array/
 */

#include <iostream>
#include <vector>

int removeDuplicates(std::vector<int>& nums)
{
    if (nums.empty())
        return 0;

    int uniqueCount = 1; // At least one unique element
    int current = nums[0];

    for (int i = 1; i < nums.size(); ++i)
    {
        if (nums[i] != current)
        {
            current = nums[i];
            nums[uniqueCount++] = current;
        }
    }

    return uniqueCount;
}

void test(const std::string& name, std::vector<int> nums, int expected)
{
    int result = removeDuplicates(nums);
    std::cout << name << ": " << (result == expected ? "Passed" : "Failed") << std::endl;
}

int main()
{
    test("Test 1", { 1, 1, 2 }, 2);
    test("Test 2", { 0, 0, 1, 1, 1, 2, 2, 3, 3, 4 }, 5);
    test("Test 3", { }, 0);
    test("Test 4", { 1 }, 1);
    test("Test 5", { 1, 2, 3 }, 3);
    return 0;
}
