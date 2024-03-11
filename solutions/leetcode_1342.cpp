/*
 * 1342. Number of Steps to Reduce a Number to Zero
 * https://leetcode.com/problems/number-of-steps-to-reduce-a-number-to-zero/
 */

#include <iostream>
#include <vector>

int numberOfSteps(int num)
{
    int steps = 0;

    while (num != 0)
    {
        if (num & 1)
        {
            --num;
        }
        else
        {
            num >>= 1;
        }
        ++steps;
    }

    return steps;
}

void test(const std::string& name, int num, int expected)
{
    std::cout << name << ": " << (numberOfSteps(num) == expected ? "Passed" : "Failed") << std::endl; 
}

int main()
{
    test("Test 1", 14, 6);
    test("Test 2", 8, 4);
}
