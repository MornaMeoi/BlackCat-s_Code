#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN 100

void quicksort(char **arr, int first, int last);
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

int main()
{
    FILE *inp = fopen("input.txt", "r");
    int N;
    fscanf(inp, "%d\n", &N);

    char child[LEN], parent[LEN];
    fscanf(inp, "%s %s", child, parent);
    nt *root = create_node(parent);
    add_node(root, parent, child);
    char **map = (char **)malloc(N*sizeof(char *) + N*LEN*sizeof(char));
    for(int i = 0; i < N; ++i)
        map[i] = (char *)(map + N) + i*LEN;
    strcpy(map[0], parent);
    strcpy(map[1], child);

    for(int i = 2; i < N; ++i)
    {
        fscanf(inp, "%s %s", child, parent);
        add_node(root, parent, child);
        strcpy(map[i], child);
    }
    fclose(inp);

    quicksort(map, 0, N-1);
    calculate_descendants(root);
    for(char **str = map; str - map < N; ++str)
    {
        printf("%s %d", *str, search(root, *str)->descendants_amount);
        if(str - map != N-1)
            putchar('\n');
    }
    destroy(root);
    free(map);
    return 0;
}

void quicksort(char **arr, int first, int last){
   int i, j, pivot;
   char *temp;
   if(first<last){
        pivot=first;
        i=first;
        j=last;
        while(i<j){
            while(strcmp(arr[i], arr[pivot]) <= 0 && i < last)
                i++;
            while(strcmp(arr[j], arr[pivot]) > 0)
                j--;
            if(i<j){
                temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
        temp=arr[pivot];
        arr[pivot]=arr[j];
        arr[j]=temp;
        quicksort(arr,first,j-1);
        quicksort(arr,j+1,last);
   }
}

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
    nt *par = search(root, parent);
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