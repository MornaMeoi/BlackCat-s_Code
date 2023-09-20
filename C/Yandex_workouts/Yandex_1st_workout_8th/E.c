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
void leaves_traversal(bst *root, int *first_flag);
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
    int first_flag = 1;
    leaves_traversal(root, &first_flag);
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

void leaves_traversal(bst *root, int *first_flag)
{
    if(root->left != NULL)
        leaves_traversal(root->left, first_flag);
    if(root->left == NULL && root->right == NULL)
    {
        if(!(*first_flag))
            putchar('\n');
        first_flag = 0;
        printf("%d", root->value);
    }
    if(root->right != NULL)
        leaves_traversal(root->right, first_flag);
}

void destroy(bst *root)
{
    if(root->left != NULL)
        destroy(root->left);
    else if(root->right != NULL)
        destroy(root->right);
    free(root);
}