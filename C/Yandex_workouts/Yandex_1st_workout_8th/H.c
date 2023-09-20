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
void height(bst *root, int level, int *max_level);
int avl_check(bst *root);
void destroy(bst *root);

int main()
{
    int val;
    bst *root;
    if(scanf("%d", &val) && val != 0)
    {
        root = create_node(val);
        while(scanf("%d", &val) && val != 0)
        {
            if(search(root, val) == NULL)
                add_node(root, val, 1);
        }
    }
    printf(avl_check(root) ? "YES" : "NO");
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

void height(bst *root, int level, int *max_level)
{
    if(root->left != NULL)
        height(root->left, level+1, max_level);
    else
        *max_level = level > *max_level ? level : *max_level;
    if(root->right != NULL)
        height(root->right, level+1, max_level);
    else
        *max_level = level > *max_level ? level : *max_level;
}

int avl_check(bst *root)
{
    int left_height = 1, right_height = 1, result = 1;
    if(root->left != NULL && root->right != NULL)
    {
        height(root->left, 1, &left_height);
        height(root->right, 1, &right_height);
        if(left_height < right_height-1 || left_height > right_height+1)
            return 0;
        result = avl_check(root->left) && avl_check(root->right);

    }
    else if(root->left == NULL && root->right != NULL)
    {
        height(root->right, 1, &right_height);
        if(right_height > 1)
            return 0;
    }
    else if(root->right == NULL && root->left != NULL)
    {
        height(root->left, 1, &left_height);
        if(left_height > 1)
            return 0;
    }
    return result;
}

void destroy(bst *root)
{
    if(root->left != NULL)
        destroy(root->left);
    else if(root->right != NULL)
        destroy(root->right);
    free(root);
}