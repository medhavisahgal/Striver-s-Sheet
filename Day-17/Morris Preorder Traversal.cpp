#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
vector<int> morrisPreorder(TreeNode *root)
{
    vector<int> ans;
    TreeNode *curr = root;
    while (curr)
    {
        if (!curr->left)
        {
            ans.push_back(curr->val);
            curr = curr->right;
        }
        else
        {
            TreeNode *pred = curr->left;
            while (pred->right && pred->right != curr)
            {
                pred = pred->right;
            }
            if (!pred->right)
            {
                ans.push_back(curr->val); // visit before threading
                pred->right = curr;
                curr = curr->left;
            }
            else
            {
                pred->right = nullptr; // remove thread
                curr = curr->right;
            }
        }
    }
    return ans;
}

int main()
{
    /*
            1
             \
              2
             /
            3
        Preorder = [1, 2, 3]
    */
    TreeNode *root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);
    vector<int> preorder = morrisPreorder(root);
    cout << "Morris Preorder Traversal: ";
    for (int val : preorder)
        cout << val << " ";
    cout << "\n";
    return 0;
}
