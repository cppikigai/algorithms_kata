/*
 * 202. Happy Number
 * https://leetcode.com/problems/happy-number/
 */

#include <iostream>
#include <unordered_set>

class Solution
{
public:
    bool isHappy(int n)
    {
        std::unordered_set<int> seen; // To detect cycles
        while (n != 1 && !seen.count(n))
        {
            seen.insert(n);
            int sum = 0;
            while (n > 0)
            {
                int digit = n % 10;
                sum += digit * digit;
                n /= 10;
            }
            n = sum;
        }

        return n == 1;
    }
};

void test(const std::string& name, int n, bool expected)
{
    Solution solution;
    bool result = solution.isHappy(n);
    std::cout << name << ": " << (result == expected ? "Passed" : "Failed") << std::endl;
}

int main()
{
    test("Test 1", 19, true);
    test("Test 2", 2, false);

    return 0;
}
