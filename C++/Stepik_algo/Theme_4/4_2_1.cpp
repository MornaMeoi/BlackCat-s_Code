#include <iostream>
#include <map>
#include <vector>

struct TreeNode
{
  TreeNode *left, *right;
  int value;
  char symb;
};

TreeNode* find_min_and_pop(std::vector<TreeNode*>& nodes)
{
  auto min_val_iter = nodes.begin();
  for(auto iter = nodes.begin(); iter < nodes.end(); ++iter)
    if((*iter)->value < (*min_val_iter)->value)
      min_val_iter = iter;
  TreeNode *min_val = *min_val_iter;
  nodes.erase(min_val_iter);
  return min_val;
}

TreeNode* Huffmans(std::vector<TreeNode*>& nodes)
{
  if(nodes.size() == 1)
    return nodes[0];
  TreeNode *newNode = new TreeNode;
  newNode->left = find_min_and_pop(nodes);
  newNode->right = find_min_and_pop(nodes);
  newNode->value = newNode->left->value + newNode->right->value;
  newNode->symb = 0;
  if(!nodes.empty())
  {
    nodes.push_back(newNode);
    return Huffmans(nodes);
  }
  return newNode;
}

void deleteTree(TreeNode* root)
{
  if(root->left != nullptr)
    deleteTree(root->left);
  if(root->right != nullptr)
    deleteTree(root->right);
  delete root;
}

void buildEncoding(TreeNode* root, std::map<char, std::string>& encoding, std::string code)
{
  if(root->left != nullptr)
    buildEncoding(root->left, encoding, code + '0');
  if(root->right != nullptr)
    buildEncoding(root->right, encoding, code + '1');
  if(root->right == nullptr && root->left == nullptr)
    encoding[root->symb] = code;
}

int main()
{
    std::string str;
    std::cin >> str;
    std::map<char, int> symb_amount;
    for(char symb : str)
      ++symb_amount[symb];
    std::vector<TreeNode*> nodes(symb_amount.size());
    size_t i = 0;
    for(const auto& element : symb_amount)
    {
      TreeNode* node = new TreeNode;
      node->symb = element.first;
      node->value = element.second;
      node->left = nullptr;
      node->right = nullptr;
      nodes[i++] = node;
    }

    TreeNode* root = Huffmans(nodes);
    std::map<char, std::string> encoding;
    buildEncoding(root, encoding, "");
    deleteTree(root);
    if(encoding.size() == 1)
      (encoding.begin())->second = "0";
    std::string result = "";
    for(char symb : str)
      result += encoding[symb];

    std::cout << encoding.size() << ' ' << result.size() << std::endl;
    for(const auto& element : encoding)
      std::cout << element.first << ": " << element.second << std::endl;
    std::cout << result;
    return 0;
}