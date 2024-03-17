/*
 * 121. Best Time to Buy and Sell Stock
 * https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
 */

#include <iostream>
#include <vector>
#include <limits>

class Solution
{
public:
    int maxProfit(std::vector<int>& prices)
    {
        int minPrice = std::numeric_limits<int>::max();
        int maxProfit = 0;

        for (int price : prices)
        {
            minPrice = std::min(minPrice, price);
            maxProfit = std::max(maxProfit, price - minPrice);
        }

        return maxProfit;
    }
};

void test(const std::string& name, std::vector<int>& prices, int expected)
{
    Solution solution;
    int result = solution.maxProfit(prices);
    std::cout << name << ": " << (result == expected ? "Passed" : "Failed") << std::endl;
}

int main()
{
    std::vector<int> testPrices1 = {7, 1, 5, 3, 6, 4};
    test("Test 1", testPrices1, 5);

    std::vector<int> testPrices2 = {7, 6, 4, 3, 1};
    test("Test 2", testPrices2, 0);

    return 0;
}
