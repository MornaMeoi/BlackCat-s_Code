#include <iostream>
#include <queue>
#include <vector>

struct TreeNode
{
  TreeNode *left, *right;
  char symb;
};

void deleteTree(TreeNode* root)
{
  if(root->left != nullptr)
    deleteTree(root->left);
  if(root->right != nullptr)
    deleteTree(root->right);
  delete root;
}

void placeNode(TreeNode* root, char symb, const std::string& code, size_t current_bit)
{
  if(current_bit != code.size())
  {
    if(code[current_bit] == '0')
    {
      if(root->left == nullptr)
      {
        TreeNode* newNode = new TreeNode;
        newNode->left = newNode->right = nullptr;
        newNode->symb = current_bit == code.size()-1 ? symb : 'N';
        root->left = newNode;
      }
      placeNode(root->left, symb, code, current_bit+1);
    }
    else
    {
      if(root->right == nullptr)
      {
        TreeNode* newNode = new TreeNode;
        newNode->left = newNode->right = nullptr;
        newNode->symb = current_bit == code.size()-1 ? symb : 'N';
        root->right = newNode;
      }
      placeNode(root->right, symb, code, current_bit+1);
    }
  }
}

int main() {

  size_t k, l;
  std::cin >> k >> l;

  std::vector<std::pair<char, std::string>> temp(k);
  std::string str(l, 0);
  for(size_t i = 0; i < k; ++i)
  {
    std::pair<char, std::string> temp_pair;
    std::cin >> temp_pair.first;
    std::cin.ignore(2);
    std::cin >> temp_pair.second;
    temp[i] = temp_pair;
  }
  std::cin >> str;

  TreeNode* root = new TreeNode, *tree_ptr = root;
  root->left = root->right = nullptr;
  root->symb = temp.size() == 1 ? temp[0].first : 'N';
  for(const auto& element : temp)
    placeNode(root, element.first, element.second, 0);
  
  for(size_t i = 0; i < str.size(); ++i)
  {
    if(tree_ptr->left == nullptr && tree_ptr->right == nullptr)
    {
      std::cout << tree_ptr->symb;
      tree_ptr = root;
      --i;
    }
    else if(str[i] == '0')
      tree_ptr = tree_ptr->left;
    else if(str[i] == '1')
      tree_ptr = tree_ptr->right;
  }
  std::cout << tree_ptr->symb;
  deleteTree(root);
  return 0;
}