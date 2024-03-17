/*
 * 80. Remove Duplicates from Sorted Array II
 * https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/
 */

#include <iostream>
#include <vector>

class Solution
{
public:
    int removeDuplicates(std::vector<int>& nums)
    {
        int n = nums.size();
        if (n <= 2) return n;
        
        int index = 2;
        for (int i = 2; i < n; ++i)
        {
            if (nums[i] != nums[index - 2])
            {
                nums[index++] = nums[i];
            }
        }
    
        return index;
    }
};

void test(const std::string& name, std::vector<int>& nums, int k, const std::vector<int>& expectedNums)
{
    Solution solution;
    int result = solution.removeDuplicates(nums);
    std::cout << name << ": ";
    if (result == k)
    {
        bool passed = true;
        for (int i = 0; i < result; ++i)
        {
            if (nums[i] != expectedNums[i])
            {
                passed = false;
                break;
            }
        }
        if (passed)
        {
            std::cout << "Passed" << std::endl;
            return;
        }
    }
    std::cout << "Failed" << std::endl;
}

int main()
{
    std::vector<int> testNums1 = {1, 1, 1, 2, 2, 3};
    std::vector<int> testExpectedNums1 = {1, 1, 2, 2, 3};
    test("Test 1", testNums1, 5, testExpectedNums1);

    std::vector<int> testNums2 = {0, 0, 1, 1, 1, 1, 2, 3, 3};
    std::vector<int> testExpectedNums2 = {0, 0, 1, 1, 2, 3, 3};
    test("Test 2", testNums2, 7, testExpectedNums2);

    return 0;
}
