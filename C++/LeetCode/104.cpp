//task https://leetcode.com/problems/maximum-depth-of-binary-tree/?envType=list&envId=rjy5c3hg
#include <iostream>

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

int maxDepth(TreeNode* root);

int main()
{
    return 0;
}

int recursiveRunner(TreeNode* node, int depth)
{
    if(node->left && node->right)
        return max(recursiveRunner(node->left, depth+1), recursiveRunner(node->right, depth+1));
    else if(node->left)
        return recursiveRunner(node->left, depth+1);
    else if(node->right)
        return recursiveRunner(node->right, depth+1);
    else
        return depth;
}

int maxDepth(TreeNode* root)
{
    if(root)
        return recursiveRunner(root, 1);
    else
        return 0;
}