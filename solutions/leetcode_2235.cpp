/*
 * 2235. Add Two Integers
 * https://leetcode.com/problems/add-two-integers/
 */

#include <iostream>

int sum(int num1, int num2)
{
    return num1 + num2;
}

void test(const std::string& name, int num1, int num2, int expected)
{
    int result = sum(num1, num2);
    std::cout << name << ": " << (result == expected ? "Passed" : "Failed") << std::endl;
}

int main()
{
    test("Test 1", 12, 5, 17);
    test("Test 2", -10, 4, -6);
}
