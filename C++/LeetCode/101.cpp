//task https://leetcode.com/problems/symmetric-tree/?envType=list&envId=rjy5c3hg
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

bool recursiveCheck(TreeNode* left_node, TreeNode* right_node);
bool isSymmetric(TreeNode* root);

int main()
{
    return 0;
}

bool recursiveCheck(TreeNode* left_node, TreeNode* right_node)
{
    if(left_node->val != right_node->val || (left_node->left && !right_node->right) || (left_node->right && !right_node->left) || (!left_node->left && right_node->right) || (!left_node->right && right_node->left))
        return false;
    else if(left_node->left && left_node->right && right_node->right && right_node->left)
        return recursiveCheck(left_node->left, right_node->right) && recursiveCheck(left_node->right, right_node->left);
    else if(left_node->left && right_node->right)
        return recursiveCheck(left_node->left, right_node->right);
    else if(left_node->right && right_node->left)
        return recursiveCheck(left_node->right, right_node->left);
    else
        return true;
    
}

bool isSymmetric(TreeNode* root)
{
    if(root)
    {
        if(root->left && root->right)
            return recursiveCheck(root->left, root->right);
        else if((root->left && !root->right) || (!root->left && root->right))
            return false;
    }
    return true;
}