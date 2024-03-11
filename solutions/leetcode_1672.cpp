/*
 * 1672. Richest Customer Wealth
 * https://leetcode.com/problems/richest-customer-wealth/
 */

#include <iostream>
#include <vector>
#include <numeric>

int maximumWealth(std::vector<std::vector<int>>& accounts)
{
    int maxWealth = 0;

    for(const auto& customer : accounts)
    {
        const int customerWealth = std::accumulate(customer.begin(), customer.end(), 0);
        maxWealth = std::max(maxWealth, customerWealth);
    }

    return maxWealth;
}

void test(const std::string& name, const std::vector<std::vector<int>>& input, int output)
{
    std::vector<std::vector<int>> accounts = input; // copying for only simplify filling tests
    std::cout << name << ": " << (maximumWealth(accounts) == output ? "Passed" : "Failed") << std::endl;
}

int main()
{
    test("Test 1", { { 1, 2, 3 }, { 3, 2, 1 } }, 6);
    test("Test 2", { { 1, 5 }, { 7, 3 }, { 3, 5 } }, 10);
    test("Test 3", { { 2, 8, 7 }, { 7, 1, 3 }, { 1, 9, 5 } }, 17);
}
