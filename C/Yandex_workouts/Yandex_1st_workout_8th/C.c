#include <stdio.h>
#include <stdlib.h>

typedef struct bst
{
    int value;
    struct bst *left;
    struct bst *right;
} bst;

bst *create_node(int init_val);
int add_node(bst *root, int node_val, int recursion_depth);
bst *search(bst *root, int val);
bst *rightest_child(bst *root);
int fixed_right_travesal(bst *node, bst *parent);
void destroy(bst *root);

int main()
{
    int val;
    bst *root;
    if(scanf("%d", &val) && val != 0)
    {
        root = create_node(val);
        while(scanf("%d", &val) && val != 0)
            if(search(root, val) == NULL)
                add_node(root, val, 1);
    }
    printf("%d", fixed_right_travesal(root, NULL));
    destroy(root);
    return 0;
}

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

bst *rightest_child(bst *root)
{
    if(root->right == NULL)
        return root;
    else
        rightest_child(root->right);
}

int fixed_right_travesal(bst *node, bst *parent)
{
    if(node->right == NULL)
        if(node->left != NULL)
            return rightest_child(node->left)->value;
        else
            return parent->value;
    else
        fixed_right_travesal(node->right, node);
}

void destroy(bst *root)
{
    if(root->left != NULL)
        destroy(root->left);
    else if(root->right != NULL)
        destroy(root->right);
    free(root);
}