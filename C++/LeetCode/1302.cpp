//task https://leetcode.com/problems/deepest-leaves-sum/?envType=list&envId=rj4up7id
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

int recursiveSum(TreeNode* root);
int deepestLeavesSum(TreeNode* root);

int main()
{
    return 0;
}

int findDepth(TreeNode* root, int depth)
{
    if(root->left && root->right)
        return max(findDepth(root->left, depth+1), findDepth(root->right, depth+1));
    else if(root->left)
        return findDepth(root->left, depth+1);
    else if(root->right)
        return findDepth(root->right, depth+1);
    return depth;
}

int recursiveSum(TreeNode* root, int max_depth, int depth)
{
    if(root->left && root->right)
        return recursiveSum(root->left, max_depth, depth+1) + recursiveSum(root->right, max_depth, depth+1);
    else if(root->left)
        return recursiveSum(root->left, max_depth, depth+1);
    else if(root->right)
        return recursiveSum(root->right, max_depth, depth+1);
    return depth == max_depth ? root->val : 0;
}

int deepestLeavesSum(TreeNode* root)
{
    if(root)
        return recursiveSum(root, findDepth(root, 0), 0);
    return 0;
}