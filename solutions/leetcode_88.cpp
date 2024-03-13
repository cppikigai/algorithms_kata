/*
 * 88. Merge Sorted Array
 * https://leetcode.com/problems/merge-sorted-array/
 */

#include <iostream>
#include <vector>

void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n)
{
    int i = m - 1;
    int j = n - 1;
    int k = m + n - 1;
    
    // Continue merging until both arrays have elements
    while (i >= 0 && j >= 0)
    {
        if (nums1[i] > nums2[j])
        {
            nums1[k--] = nums1[i--];
        }
        else
        {
            nums1[k--] = nums2[j--];
        }
    }

    // If there are remaining elements in nums2, copy them to nums1
    while (j >= 0)
    {
        nums1[k--] = nums2[j--];
    }
}
/*
void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n)
{
    for(int i = 0; i < n; ++i)
    {
        nums1[m + i] = nums2[i];
    }
    
    sort(nums1.begin(), nums1.end());
}
*/
void test(const std::string& name,
          const std::vector<int>& nums1, int m, 
          const std::vector<int>& nums2, int n,
          const std::vector<int>& expected)
{
    // copying for only simplify filling tests
    std::vector<int> copyNums1 = nums1;
    std::vector<int> copyNums2 = nums2;

    merge(copyNums1, m, copyNums2, n);
    std::cout << name << ": " << (copyNums1 == expected ? "Passed" : "Failed") << std::endl;
}

int main()
{
    test("Test 1", { 1, 2, 3, 0, 0, 0 }, 3, { 2, 5, 6 }, 3, { 1, 2, 2, 3, 5, 6 });
    test("Test 2", { 1 } , 1, {}, 0, { 1 });
    test("Test 3", { 0 }, 0, { 1 }, 1, { 1 });
}