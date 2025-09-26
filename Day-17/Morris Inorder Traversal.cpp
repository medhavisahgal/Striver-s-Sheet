#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
vector<int> morrisInorder(TreeNode *root)
{
    vector<int> ans;
    TreeNode *curr = root;
    while (curr)
    {
        if (!curr->left)
        {
            // No left child, visit node
            ans.push_back(curr->val);
            curr = curr->right;
        }
        else
        {
            // Find inorder predecessor (rightmost node in left subtree)
            TreeNode *pred = curr->left;
            while (pred->right && pred->right != curr)
            {
                pred = pred->right;
            }
            if (!pred->right)
            {
                // First time visiting → make a temporary thread
                pred->right = curr;
                curr = curr->left;
            }
            else
            {
                // Thread exists → break it and visit node
                pred->right = nullptr;
                ans.push_back(curr->val);
                curr = curr->right;
            }
        }
    }
    return ans;
}

int main()
{
    /*
         Constructing the tree:
                 1
                  \
                   2
                  /
                 3
         Inorder = [1, 3, 2]
    */
    TreeNode *root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);
    vector<int> inorder = morrisInorder(root);
    cout << "Morris Inorder Traversal: ";
    for (int val : inorder)
    {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}
