/*
 * 141. Linked List Cycle
 * https://leetcode.com/problems/linked-list-cycle/description/
 */

#include <iostream>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution
{
public:
    bool hasCycle(ListNode* head)
    {
        if(head == nullptr || head->next == nullptr)
        {
            return false;
        }

        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != nullptr && fast->next != nullptr)
        {
            fast = fast->next->next;
            slow = slow->next;
            if(slow == fast)
                return true;
        }
        
        return false;
    }
};

void test(const std::string& name, ListNode* head, bool expected)
{
    Solution solution;
    bool result = solution.hasCycle(head);
    std::cout << name << ": " << (result == expected ? "Passed" : "Failed") << std::endl;
}

int main()
{
    // Test cases
    ListNode* cycleHead1 = new ListNode(3);
    ListNode* cycleSecond1 = new ListNode(2);
    ListNode* cycleThird1 = new ListNode(0);
    ListNode* cycleFourth1 = new ListNode(-4);

    cycleHead1->next = cycleSecond1;
    cycleSecond1->next = cycleThird1;
    cycleThird1->next = cycleFourth1;
    cycleFourth1->next = cycleSecond1; // Cycle formed

    test("Test 1", cycleHead1, true);

    ListNode* cycleHead2 = new ListNode(1);
    ListNode* cycleSecond2 = new ListNode(2);

    cycleHead2->next = cycleSecond2;
    cycleSecond2->next = cycleHead2; // Cycle formed

    test("Test 2", cycleHead2, true);

    ListNode* noCycleHead = new ListNode(1);

    test("Test 3", noCycleHead, false);

    // I'm not clearing the memory because this is a test example, 
    // and it will be cleared after the main is completed.

    return 0;
}