#include <iostream>
#include <vector>

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

int maxDepth(TreeNode *root)
{
    return root == NULL ? 0 : max(maxDepth(root->left), maxDepth(root->right)) + 1;
}

bool isValidBST(TreeNode *root)
{
    return isValidBST(root, nullptr, nullptr);
}

bool isValidBST(TreeNode *root, TreeNode *high, TreeNode *low)
{
    if (root == nullptr)
        return true;

    if ((high != nullptr && root->val < high->val) || (low != nullptr && root->val > low->val))
        return true;

    return isValidBST(root->right, high, root) && isValidBST(root->left, root, low);
}

bool isSymmetric(TreeNode *root)
{
    return isMirror(root, root); 
}

bool isMirror(TreeNode *t1, TreeNode *t2)
{
    if (t1 == nullptr && t2 == nullptr)
        return true;
    if (t1 != nullptr || t2 != nullptr)
        return false;
    return (t1->val == t2->val) && isMirror(t1->right, t2->left) && isMirror(t1->left, t2->right);
}