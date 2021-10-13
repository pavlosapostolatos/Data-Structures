#include <stdio.h>
#include <stdlib.h>
#include "module1.h"
int BTHeight(BTnode tree)
{
    if (BTIsEmpty(tree, tree) == 1)
        return 0;
    else
    {
        int lheight = BTHeight(tree->left);
        int dheight = BTHeight(tree->right);
        if (lheight > dheight)
            return (lheight + 1);
        else
            return (dheight + 1);//with each children reached recursively we add a height point and when returning to a parent we subtrack a height point
    }
}
BSTKeyType BSTGetKey(BTtree tree, BTnode node)
{
    if (BTIsEmpty(node, node))
    {
        printf("error: inserted empty tree\n");
        return 0;
    }
    BTnode temp = search(tree, node);
    return temp->key;
}
BTnode BTcreate(int maxelem)
{
    BTnode temp = NULL;
    return temp;//empty tree returned
}
int BTIsEmpty(BTnode tree, BTnode node)
{
    return node == NULL;
}
int BTSize(BTnode tree)
{
    int counter = 1;
    if (BTIsEmpty(tree, tree) == 1)
        return 0;
    else
    {
        counter += BTSize(tree->left);
        counter += BTSize(tree->right);
        return counter;//will go through all nodes and add +1 to counter
    }
}

BTnode BTGetRoot(BTnode tree)
{
    BTnode temp = tree;
    if (BTIsEmpty(tree, tree))
        return NULL;
    while (temp->paren != NULL)
        temp = temp->paren;
    return temp;//go to top using parent pointer
}

BTnode BTGetParent(BTnode tree, BTnode node)
{
    if (BTIsEmpty(tree, tree))
    {
        printf("error: inserted empty tree\n");
        return NULL;
    }
    if (node->paren == NULL)
    {
        printf("error: searching for parent of root\n");
        return NULL;
    }
    BTnode temp;
    //temp = search(tree, node);
    temp = node;
    return temp->paren;
}

BTnode BTGetChildLeft(BTnode tree, BTnode node)
{
    if (BTIsEmpty(tree, tree))
    {
        printf("error: inserted empty tree\n");
        return NULL;
    }
    BTnode temp;
    //temp=search(tree,node);
    temp = node;
    return temp->left;
}

BTnode BTGetChildRight(BTnode tree, BTnode node)
{
    if (BTIsEmpty(tree, tree))
    {
        printf("error: inserted empty tree\n");
        return NULL;
    }
    BTnode temp;
    //temp=search(tree,node);
    temp = node;
    return temp->right;
}

void Destroy(BTnode tree)
{
    if (tree == NULL)
        return;
    BTnode left = tree->left, right = tree->right;
    free(tree);
    Destroy(left);
    Destroy(right);//goes to every node and frees it
}

void BTPreOrder(BTnode tree, Visit visit)
{
    if (BTIsEmpty(tree, tree))
        return;
    visit(tree);
    BTPreOrder(tree->left, visit);
    BTPreOrder(tree->right, visit);
}

void BTInOrder(BTnode tree, Visit visit)
{
    if (BTIsEmpty(tree, tree))
        return;
    BTInOrder(tree->left, visit);
    visit(tree);
    BTInOrder(tree->right, visit);
}

void BTPostOrder(BTnode tree, Visit visit)
{
    if (BTIsEmpty(tree, tree))
        return;
    BTPostOrder(tree->left, visit);
    BTPostOrder(tree->right, visit);
    visit(tree);
}

void BTLevelOrder(BTnode tree, Visit visit)
{
    int h = BTHeight(tree);
    int i;
    for (i = 1; i <= h; i++)
        printLevel(tree, i, visit);//access a given level
}

void printLevel(BTnode tree, int level, Visit visit)
{
    if (BTIsEmpty(tree, tree))
        return;//mac depth cant be reached in all sub-trees
    if (level == 1)
        visit(tree);
    else if (level > 1)
    {
        printLevel(tree->left, level - 1, visit);
        printLevel(tree->right, level - 1, visit);//with every step below root we substrack a level
    }
}

BTnode search(BTnode tree, BTnode node)
{
    BTnode temp;
    if (tree == NULL)
        return tree;
    if (tree->data == node->data)
        return tree;
    if ((temp = search(tree->left, node)) != NULL)
        return temp;
    if ((temp = search(tree->right, node)) != NULL)
        return temp;
    return NULL;
}//slow because tree isnt sorted/improved in exercise 6

void Remove(BTnode tree, BTnode node)
{
    if (BTIsEmpty(tree, tree) || BTIsEmpty(node, node))
    {
        printf("error: inserted empty tree\n");
        return;
    }
    BTnode temp = search(tree, node);
    if (BTIsEmpty(temp, temp))
    {
        printf("error: node doesnt exist\n");
        return;
    }
    if (temp->left != NULL || temp->left != NULL)
    {
        printf("error: node has children\n");
        return;
    }
    if (temp->paren != NULL)
    {
        if (temp->paren->left == temp)
            temp->paren->left = NULL;
        else if (temp->paren->right == temp)
            temp->paren->right = NULL;//setting parent pointer to avoid bugs
    }
    free(temp);
}

BTitem BTGetItem(BTnode tree, BTnode node)
{
    if (BTIsEmpty(node, node))
    {
        printf("error: inserted empty tree\n");
        return 0;
    }
    BTnode temp = search(tree, node);
    return temp->data;
}

BTnode insertroot(BTnode tree, BTitem item)
{
    BTnode temp;
    if (BTIsEmpty(tree, tree))
    {
        temp = (BTnode)malloc(sizeof(binary_tree));
        temp->data = item;
        temp->left = NULL;
        temp->right = NULL;
        temp->paren = NULL;
    }
    return temp;
}

void BTInsertLeft(BTnode tree, BTnode node, BTitem item)
{
    BTnode newnode, temp = search(tree, node);
    if (temp->left != NULL)
    {
        printf("left child exists\n");
        return;
    }
    newnode = (BTnode)malloc(sizeof(binary_tree));
    newnode->data = item;
    newnode->left = NULL;
    newnode->right = NULL;
    newnode->paren = temp;
    temp->left = newnode;
}

void BTInsertRight(BTnode tree, BTnode node, BTitem item)
{

    BTnode newnode, temp = search(tree, node);
    if (temp->right != NULL)
    {
        printf("right child exists\n");
        return;
    }
    newnode = (BTnode)malloc(sizeof(binary_tree));
    newnode->data = item;
    newnode->left = NULL;
    newnode->right = NULL;
    newnode->paren = temp;
    temp->right = newnode;
}

void BTChange(BTnode tree, BTnode node, BTitem item)
{
    BTnode temp = search(tree, node);
    temp->data = item;
}
void BTChangeKey(BTnode tree, BTnode node, BSTKeyType key)
{
    BTnode temp = search(tree, node);
    temp->key = key;
}

void visit(BTnode tree)
{
    printf(TYPE, tree->data);
}

BTtree NEW(BTitem item, BTtree l, BTtree r, BSTKeyType key, CompareType compare)
{
    BTtree x = (BTnode)malloc(sizeof(binary_tree));
    x->data = item;
    x->left = l;
    x->right = r;
    x->key = key;
    x->compare = compare;
    return x;
}

void Changeleft(BTtree *a, BTtree b)
{
    (*a)->left = b;
}
void Changeright(BTtree *a, BTtree b)
{
    (*a)->right = b;
}
void Changeparen(BTtree *a, BTtree b)
{
    (*a)->paren = b;
}
void kill(BTtree tree, BTnode node)
{
    if (node->paren != NULL)
    {
        if (node->paren->left == node)
            node->paren->left = NULL;
        else if (node->paren->right == node)
            node->paren->right = NULL;
    }
    free(node);
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
