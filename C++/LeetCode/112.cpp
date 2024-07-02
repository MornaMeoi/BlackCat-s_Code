//task https://leetcode.com/problems/path-sum/?envType=list&envId=rjy5c3hg
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

bool hasPathSum(TreeNode* root, int targetSum);

int main()
{
    return 0;
}

bool recursiveCheck(TreeNode* root, int targetSum, int currentSum)
{
    if(root->left && root->right)
        return recursiveCheck(root->left, targetSum, currentSum+root->val) || recursiveCheck(root->right, targetSum, currentSum+root->val);
    else if(root->left)
        return recursiveCheck(root->left, targetSum, currentSum+root->val);
    else if(root->right)
        return recursiveCheck(root->right, targetSum, currentSum+root->val);
    else
        return targetSum == (currentSum + root->val);
}

bool hasPathSum(TreeNode* root, int targetSum)
{
    if(root)
        return recursiveCheck(root, targetSum, 0);
    else
        return false;
}