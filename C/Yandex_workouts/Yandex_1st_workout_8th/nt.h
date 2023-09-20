#ifndef NT_H
#define NT_H

typedef struct nt
{
    char *value;
    int descendants_amount;
    int children_amount;
    int children_capacity;
    struct nt **children;
} nt;

nt *create_node(char *value);
nt *search(nt *root, char *value);
void add_node(nt *root, char *parent, char *child);
int calculate_descendants(nt *root);
void destroy(nt *root);

#endif