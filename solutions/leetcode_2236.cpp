/*
 * 2236. Root Equals Sum of Children
 * https://leetcode.com/problems/root-equals-sum-of-children/
 */

#include <iostream>
#include <memory>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool checkTree(TreeNode* root)
{
    return root->val == root->left->val + root->right->val; 
}

void test(const std::string& name, TreeNode* root, bool expected)
{
    bool result = checkTree(root);
    std::cout << name << ": " << (result == expected ? "Passed" : "Failed") << std::endl;
}

int main()
{
    TreeNode* root1 = new TreeNode(10, new TreeNode(4), new TreeNode(6));
    TreeNode* root2 = new TreeNode(5, new TreeNode(3), new TreeNode(1));

    test("Test 1", root1, true);
    test("Test 2", root2, false);

    // I'm not clearing the memory because this is a test example, 
    // and it will be cleared after the main is completed.

    return 0;
}

