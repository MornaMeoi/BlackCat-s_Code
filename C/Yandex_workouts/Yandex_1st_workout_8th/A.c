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
void destroy(bst *root);

int main()
{
    int val, max = 0;
    bst *root;
    if(scanf("%d", &val) && val != 0)
    {
        root = create_node(val);
        while(scanf("%d", &val) && val != 0)
        {
            if(search(root, val) == NULL)
            {
                int temp = add_node(root, val, 1);
                max = temp > max ? temp : max;
            }
        }
    }
    destroy(root);
    printf("%d", max);
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

void destroy(bst *root)
{
    if(root->left != NULL)
        destroy(root->left);
    else if(root->right != NULL)
        destroy(root->right);
    free(root);
}