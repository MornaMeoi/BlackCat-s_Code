#ifndef BST_H
#define BST_H

typedef struct bst
{
    int value;
    struct bst *left;
    struct bst *right;
} bst;

bst *create_node(int init_val);
int add_node(bst *root, int node_val, int recursion_depth);
void print_tree(bst *node, int level);
bst *search(bst *root, int val);
void left_traversal(bst *root);
void right_traversal(bst *root);
void leaves_traversal(bst *root);
void forks_traversal(bst *root);
void branches_traversal(bst *root);
void destroy(bst *root);

#endif