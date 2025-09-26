#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    // vector<int> v;
    // void preorder(TreeNode *temp)
    // {
    //     if (!temp)
    //         return;
    //     v.push_back(temp->val);
    //     preorder(temp->left);
    //     preorder(temp->right);
    // }
    void flatten(TreeNode *root)
    {
        // My approach is to store the preorder traversal in a vector
        // then making the the treenode again
        // if (!root)
        //     return;
        // preorder(root);
        // How to use the same TreeNode class where the right child pointer points to the next node in the list and the left child pointer is always null
        // TreeNode *temp2 = root;
        // temp2->val = v[0];
        // temp2->left = nullptr;
        // for (int i = 1; i < v.size(); i++)
        // {
        //     temp2->right = new TreeNode(v[i]);
        //     temp2 = temp2->right;
        // }
        // Problem with this approach is that it uses extra space
        // and we are rebuilding it again thats not the actual flattening
        // Optimal approach is Morris Traversal
        TreeNode *curr = root;
        while (curr)
        {
            if (curr->left)
            {
                // Find the rightmost node in left subtree
                TreeNode *pred = curr->left;
                while (pred->right)
                {
                    pred = pred->right;
                }
                // Rewire: attach curr->right to rightmost node
                pred->right = curr->right;
                curr->right = curr->left;
                curr->left = nullptr;
            }
            curr = curr->right; // move to next
        }
    }
};
