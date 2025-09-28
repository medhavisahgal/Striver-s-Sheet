#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode()
    {
        val = 0;
        left = nullptr;
        right = nullptr;
    }
    TreeNode(int x)
    {
        val = x;
        left = nullptr;
        right = nullptr;
    }
    TreeNode(int x, TreeNode *left, TreeNode *right)
    {
        val = x;
        this->left = left;
        this->right = right;
    }
};
class Solution
{
public:
    TreeNode *searchBST(TreeNode *root, int val)
    {
        // Property of BST is that on left subtree the elements are smaller and in the right subtree it is larger
        if (!root)
            return nullptr;
        while (root)
        {
            if (root->val == val)
            {
                return root;
            }
            else if (root->val > val)
            {
                root = root->left;
            }
            else if (root->val < val)
            {
                root = root->right;
            }
        }
        return nullptr;
    }
};
int main()
{
    TreeNode *root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    Solution sol;
    TreeNode *result = sol.searchBST(root, 2);
    if (result)
    {
        cout << "Found: " << result->val << endl;
    }
    else
    {
        cout << "Not Found" << endl;
    }
    return 0;
}