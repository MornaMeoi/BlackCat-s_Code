#include <stdlib.h>

#include "bst.h"

bst *create_node(int init_val)
{
    bst *initial = (bst *)malloc(sizeof(bst));
    initial->value = init_val;
    initial->left = NULL;
    initial->right = NULL;
    return initial;
}

int add_node(bst *root, int node_val, int recursion_depth)
{
    if(node_val < root->value)
    {
        if(root->left == NULL)
        {
            root->left = create_node(node_val);
            return recursion_depth+1;
        }
        else
            return add_node(root->left, node_val, recursion_depth+1);
    }
    else if(node_val > root->value)
    {
        if(root->right == NULL)
        {
            root->right = create_node(node_val);
            return recursion_depth+1;
        }
        else
            return add_node(root->right, node_val, recursion_depth+1);
    }
}

void print_tree(bst *node, int level)
{
    if(node)
    {
        print_tree(node->left, level+1);
        for(int i = 0;i< level;i++)
            printf("\t");
        printf("%d\n", node->value);
        print_tree(node->right, level+1);
    }
}

bst *search(bst *root, int val)
{
    if(val == root->value)
        return root;
    else if(val < root->value && root->left != NULL)
        search(root->left, val);
    else if(val > root->value && root->right != NULL)
        search(root->right, val);
    else
        return NULL;
}

void right_traversal(bst *root)
{
    if(root->right != NULL)
        right_traversal(root->right);
    printf("%d ", root->value);
    if(root->left != NULL)
        right_traversal(root->left);
}

void left_traversal(bst *root)
{
    if(root->left != NULL)
        left_traversal(root->left);
    printf("%d ", root->value);
    if(root->right != NULL)
        left_traversal(root->right);
}

void leaves_traversal(bst *root)
{
    if(root->left != NULL)
        leaves_traversal(root->left);
    if(root->left == NULL && root->right == NULL)
        printf("%d ", root->value);
    if(root->right != NULL)
        leaves_traversal(root->right);
}

void forks_traversal(bst *root)
{
    if(root->left != NULL)
        forks_traversal(root->left);
    if(root->left != NULL && root->right != NULL)
        printf("%d ", root->value);
    if(root->right != NULL)
        forks_traversal(root->right);
}

void branches_traversal(bst *root)
{
    if(root->left != NULL)
        branches_traversal(root->left);
    if((root->left == NULL && root->right != NULL) || (root->left != NULL && root->right == NULL))
        printf("%d ", root->value);
    if(root->right != NULL)
        branches_traversal(root->right);
}

void destroy(bst *root)
{
    if(root->left != NULL)
        destroy(root->left);
    else if(root->right != NULL)
        destroy(root->right);
    free(root);
}