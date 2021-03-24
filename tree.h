#include <iostream>
#include <vector>
#include <stack>
#include <queue>

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
    if (t1 == nullptr || t2 == nullptr)
        return false;
    return (t1->val == t2->val) && isMirror(t1->right, t2->left) && isMirror(t1->left, t2->right);
}

bool isSymmetric(TreeNode *root)
{
    queue<TreeNode *> queue;

    queue.push(root);
    queue.push(root);

    while (!queue.empty())
    {
        auto t1_p = queue.front();
        queue.pop();
        auto t2_p = queue.front();
        queue.pop();
        if (t1_p == nullptr && t2_p == nullptr)
            continue;
        if (t1_p == nullptr || t2_p == nullptr)
            return false;
        if (t1_p->val != t2_p->val)
            return false;
        queue.push(t1_p->right);
        queue.push(t2_p->left);
        queue.push(t1_p->left);
        queue.push(t2_p->right);
    }
    return true;
}