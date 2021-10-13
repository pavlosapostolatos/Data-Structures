#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "module2.h"

//array fromation is exactly like class theory entails.datat starts at the [1] cell and is inserted in level order as the the cells go foward.empty node is represented with -1
BTtree BTcreate(int maxelem)
{//mallocing for all possible contents of struct
    int i;
    BTtree b = (BTtree)malloc(sizeof(binary_tree));
    b->size = maxelem;
    b->items = (BTitem *)malloc((maxelem + 1) * sizeof(BTitem));
    for (i = 1; i < b->size + 1; i++)
        b->items[i] = -1;
    b->priority = (int *)malloc((maxelem + 1) * sizeof(int));
    b->key = (BSTKeyType *)malloc((maxelem + 1) * sizeof(BSTKeyType));
    return b;
}

int BTSize(BTtree tree)
{
    int i, nodes = 0;
    for (i = 1; i < tree->size + 1; i++)
        if (tree->items[i] != -1)
            nodes++;
    return nodes;
}
BSTKeyType BSTGetKey(BTtree tree, BTnode node)
{
    if (BTIsEmpty(tree, node))
    {
        printf("error: inserted empty tree\n");
        return 0;
    }
    return tree->key[node];
}
BTnode BTGetChildLeft(BTtree tree, BTnode node)
{
    if (LEFT(node) > tree->size)
        return -1;//always checking for out of bounds.means it doesnt have children
    else
        return LEFT(node);//macros to make traversal easier to write.check #define
}

BTnode BTGetChildRight(BTtree tree, BTnode node)
{
    if (RIGHT(node) > tree->size)
        return -1;
    else
        return RIGHT(node);
}

BTnode BTGetParent(BTtree tree, BTnode node)
{
    if (PAREN(node) < 1)
        return -1;
    else
        return PAREN(node);
}
BTitem BTGetItem(BTtree tree, BTnode node)
{
    if (node > tree->size || node < 1)
    {
        printf("going out of bounds\n");
        exit(-1);
    }
    else if (tree->items[node] == -1)
    {
        printf("inserted empty node\n");
    }
    return tree->items[node];
}

void BTChange(BTtree tree, BTnode node, BTitem item)
{
    if (node > tree->size || node < 1)
    {
        printf("going out of bounds\n");
        exit(-1);
    }
    tree->items[node] = item;
}
void BTChangeKey(BTtree tree, BTnode node, BSTKeyType key)
{
    if (node > tree->size || node < 1)
    {
        printf("going out of bounds\n");
        exit(-1);
    }
    else if (tree->items[node] == -1)
    {
        printf("inserted empty node\n");
    }
    tree->key[node] = key;
}

BTnode BTGetRoot(BTtree tree) { return 1; }

BTtree insertroot(BTtree tree, BTitem item)
{
    if (tree->items[1] != -1)
    {
        printf("inserted empty tree\n");
        exit(-1);
    }
    else
        tree->items[1] = item;
    return tree;
}

void Remove(BTtree tree, BTnode node)
{
    int child1 = 1, child2 = 1;
    if (RIGHT(node) > tree->size)
        child2 = 0;
    if (LEFT(node) > tree->size)
        child1 = 0;
    if (child1 == 1)
        if (tree->items[LEFT(node)] != -1)
            child1 = 0;
    if (child2 == 1)
        if (tree->items[RIGHT(node)] != -1)
            child1 = 0;
    if (child1 == 0 && child2 == 0)
        tree->items[node] = -1;//only deleting leafs
}
void Destroy(BTtree tree)
{
    free(tree->items);
    free(tree);
}

void BTInsertLeft(BTtree tree, BTnode node, BTitem item)
{
    if (LEFT(node) > tree->size || tree->items[LEFT(node)] != -1)
    {
        printf("out of bounds or child exists\n");
        exit(-1);
    }
    else
        tree->items[LEFT(node)] = item;
}

void BTInsertRight(BTtree tree, BTnode node, BTitem item)
{
    if (RIGHT(node) > tree->size || tree->items[RIGHT(node)] != -1)
    {
        printf("out of bounds or child exists\n");
        exit(-1);
    }
    else
        tree->items[RIGHT(node)] = item;
}

int BTHeight(BTtree tree)
{
    int i, k, height, maxh = 0;
    for (i = 1; i < tree->size + 1; i++)
    {
        k = i;
        height = 0;
        while (k > 0)
        {
            if (tree->items[k] != -1)
                height++;
            k = k / 2;
        }
        if (height > maxh)
            maxh = height;
    }
    return maxh;//basically for each cell of the array im counting how many "ansectors" it has using the parent method
}

void BTLevelOrder(BTtree tree, Visit visit)
{
    int i;
    for (i = 1; i < tree->size + 1; i++)
        visit(tree, i);
    printf("\n");
}

void BTPostOrder(BTtree tree, Visit visit)
{
	postorder(tree, 1, visit);
}

void postorder(BTtree tree, BTnode node, Visit visit)
{
    if (node > tree->size)
        return;
    if (tree->items[node] == -1)
        return;
    postorder(tree, LEFT(node), visit);
    postorder(tree, RIGHT(node), visit);
    visit(tree, node);
}

void visit(BTtree tree, BTnode node)
{
    if (tree->items[node] != -1)
        printf(TYPE, tree->items[node]);
}

void BTInOrder(BTtree tree, Visit visit)
{
    inorder(tree, 1, visit);
}

void BTPreOrder(BTtree tree, Visit visit)
{
    preorder(tree, 1, visit);
}
void inorder(BTtree tree, BTnode node, Visit visit)
{
    if (node > tree->size)
        return;
    if (tree->items[node] == -1)
        return;
    inorder(tree, LEFT(node), visit);
    visit(tree, node);
    inorder(tree, RIGHT(node), visit);
}

void preorder(BTtree tree, BTnode node, Visit visit)
{
    if (node > tree->size)
        return;
    if (tree->items[node] == -1)
        return;
    visit(tree, node);
    preorder(tree, LEFT(node), visit);
    preorder(tree, RIGHT(node), visit);
}
int BTIsEmpty(BTtree tree, BTnode node)
{
    if (node < 1 || node > tree->size)
        return 1;
    else if (tree->items[node] == -1)
        return 1;
    else
        return 0;
}
void Changeleft(BTtree *a, BTtree b)
{
    return;
}
void Changeright(BTtree *a, BTtree b)
{
    return;//meant to swap left and right pointers which the sequential implementation doesnt have for obvious reasons.
}//it exists to limit conditional compilation.ignore it
void Changeparen(BTtree *a, BTtree b) { return; }

void kill(BTtree tree, BTnode node)
{
    tree->items[node] = -1;//Remove function without no children limitation.used in exercise 6
}

//int comp1(BSTKeyType a,BSTKeyType b){
//return strcmp(a,b);}

int comp2(BSTKeyType a, BSTKeyType b)
{
    double k = a - b;
    if (k == 0.0)
        return 0;
    else
        return k;
}
