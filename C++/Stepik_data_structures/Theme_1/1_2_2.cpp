#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
  vector<TreeNode*> children;
};

int CalculateTreeHeight(TreeNode* node)
{
  if(node->children.empty())
    return 1;
  int result = 0;
  for(auto& child : node->children)
    result = max(result, CalculateTreeHeight(child));
  return result + 1;
}

int main()
{
  int n;
  cin >> n;
  vector<TreeNode> tree(n);
  TreeNode* root = nullptr;
  for(int i = 0; i < n; ++i)
  {
    int parent_idx;
    cin >> parent_idx;
    if(parent_idx == -1)
      root = &tree[i];
    else
      tree[parent_idx].children.push_back(&tree[i]);
  }
  cout << CalculateTreeHeight(root);
  return 0;
}