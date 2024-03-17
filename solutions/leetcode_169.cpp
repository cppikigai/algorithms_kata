/*
 * 169. Majority Element
 * https://leetcode.com/problems/majority-element/
 */

#include <iostream>
#include <vector>

class Solution
{
public:
    // Boyer-Moore Voting Algorithm
    int majorityElement(std::vector<int>& nums)
    {
        int count = 0;    
        int element = 0; 

        for (int i = 0; i < nums.size(); ++i)
        {
            if (count == 0)
            {
                element = nums[i];
                count = 1;
            }
            else if (element == nums[i])
            {
                ++count;
            }
            else
            {
                --count;
            }
        }

        return element; 
    }
};

void test(const std::string& name, std::vector<int>& nums, int expected)
{
    Solution solution;
    int result = solution.majorityElement(nums);
    std::cout << name << ": " << (result == expected ? "Passed" : "Failed") << std::endl;
}

int main()
{
    std::vector<int> testNums1 = {3, 2, 3};
    test("Test 1", testNums1, 3);

    std::vector<int> testNums2 = {2, 2, 1, 1, 1, 2, 2};
    test("Test 2", testNums2, 2);

    return 0;
}
