/*
 * 27. Remove Element
 * https://leetcode.com/problems/remove-element/
 */

#include <iostream>
#include <vector>
#include <algorithm>

int removeElement(std::vector<int>& nums, int val)
{
    int k = 0;

    for (int i = 0; i < nums.size(); ++i)
    {
        if (nums[i] != val)
        {
            nums[k++] = nums[i];
        }
    }

    return k;
}

void test(const std::string& name, std::vector<int> nums, int val, int expected)
{
    int result = removeElement(nums, val);
    std::sort(nums.begin(), nums.begin() + result); // Sorting first k elements
    std::cout << name << ": " << (result == expected ? "Passed" : "Failed") << std::endl;
}

int main()
{
    test("Test 1", { 3, 2, 2, 3 }, 3, 2);
    test("Test 2", { 0, 1, 2, 2, 3, 0, 4, 2 }, 2, 5);
    test("Test 3", { }, 5, 0);
    test("Test 4", { 1, 1, 1, 1, 1 }, 1, 0);
    test("Test 5", { 1, 2, 3, 4, 5 }, 6, 5);
    return 0;
}
