/*
 * 2485. Find the Pivot Integer
 * https://leetcode.com/problems/find-the-pivot-integer/
 */

#include <iostream>

int pivotInteger(int n)
{
    int sum = ((1 + n) * n)/2;
    int result = sqrt(sum);
    return (result * result == sum) ? result : -1;
}

void test(const std::string& name, int n, int expected)
{
    std::cout << name << ": " << (pivotInteger(n) == expected ? "Passed" : "Failed") << std::endl;
}

int main()
{
    test("Test 1", 8, 6);
    test("Test 2", 1, 1);
    test("Test 3", 4, -1);
}
