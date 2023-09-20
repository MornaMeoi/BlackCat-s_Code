#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "nt.h"

nt *create_node(char *value)
{
    nt *initial = (nt *)malloc(sizeof(nt));
    initial->value = (char *)malloc((strlen(value) + 1) * sizeof(char));
    strcpy(initial->value, value);
    initial->children_amount = 0;
    initial->descendants_amount = 0;
    initial->children_capacity = 1;
    initial->children = (nt **)malloc(sizeof(nt *));
    return initial;
}

nt *search(nt *root, char *value)
{
    nt *res = NULL;
    if(strcmp(root->value, value) == 0)
        return root;
    else if(root->children_amount != 0)
        for(nt **child = root->children; child - root->children < root->children_amount; ++child)
        {
            nt *temp = search(*child, value);
            if(temp != NULL)
                res = temp;
        }
    return res;
}

void add_node(nt *root, char *parent, char *child)
{
    nt *par = search(root, parent), *ch = search(root, child);
    if(par->children_amount == par->children_capacity)
    {
        par->children_capacity *= 2;
        par->children = (nt **)realloc(par->children, par->children_capacity * sizeof(nt *));
    }
    par->children[(par->children_amount)++] = create_node(child);
}

int calculate_descendants(nt *root)
{
    root->descendants_amount = root->children_amount;
        if(root->children_amount != 0)
            for(nt **child = root->children; child - root->children < root->children_amount; ++child)
                root->descendants_amount += calculate_descendants(*child);
    return root->descendants_amount;
}

void destroy(nt *root)
{
    if(root->children_amount != 0)
        for(nt **child = root->children; child - root->children < root->children_amount; ++child)
            destroy(*child);
    free(root->value);
    free(root->children);
}