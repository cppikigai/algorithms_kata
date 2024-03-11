/*
 * 412. Fizz Buzz
 * https://leetcode.com/problems/fizz-buzz/description/
 */

#include <iostream>
#include <vector>

std::vector<std::string> fizzBuzz(int n)
{
    std::vector<std::string> result(n);

    for(int i = 1; i <= n; ++i)
    {
        std::string value;
        const bool divisibleBy3 = i % 3 == 0;
        const bool divisibleBy5 = i % 5 == 0;

        if(divisibleBy3)
        {
            value += "Fizz";
        }

        if(divisibleBy5)
        {
            value += "Buzz";
        }

        if(value.empty())
        {
            value = std::to_string(i);
        }

        result[i - 1] = value;
    }

    return result;
}

void test(const std::string& name, int n, const std::vector<std::string>& output)
{
    std::cout << name << ": " << (fizzBuzz(n) == output ? "Passed" : "Failed") << std::endl;
}

int main()
{
    test("Test 1", 3, { "1", "2", "Fizz" });
    test("Test 2", 5, { "1", "2", "Fizz", "4", "Buzz" });
    test("Test 3", 15, { "1", "2", "Fizz", "4", "Buzz", "Fizz", "7", "8", "Fizz", "Buzz", "11", "Fizz", "13", "14", "FizzBuzz" });
}
