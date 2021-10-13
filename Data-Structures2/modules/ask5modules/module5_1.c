#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "module5_2.h"

BHtree BHcreate(int maxelem)
{
    return CBTcreate(maxelem);
}

BHnode BHGetRoot(BHtree tree)
{
    return CBTGetRoot(tree);
}
void BHDestroy(BHtree tree)
{
    Destroy(tree);
}

BHtree BHInsertLast(BHtree tree, BHitem item)
{
    return CBTInsertLast(tree, item);
}
void BHRemoveLast(BHtree tree)
{
    CBTRemoveLast(tree);
}

BHnode BHGetLast(BHtree tree)
{
    return CBTGetLast(tree);
}

int BHeight(BHtree tree)
{
    return CBTHeight(tree);
}

void BHLevelOrder(BHtree tree, Visit visit)
{
    CBTLevelOrder(tree, visit);
}

BHitem BHGetMaxItem(BHtree tree)
{
    BHnode temp = BHGetRoot(tree);
    return CBTGetItem(tree, temp);
}

int BHIsEmpty(BHtree tree, BHnode node)
{
    return CBTIsEmpty(tree, node);
}
int BHIsLeaf(BHtree tree, BHnode node)
{
    return (BHIsEmpty(tree, CBTGetChildLeft(tree, node)) && BHIsEmpty(tree, CBTGetChildRight(tree, node)));
}

#ifdef BT_IMPL_LINKED

BHtree BHHeapify(int n, int *priorities, BHitem *items)
{
    int i;
    BHtree a = NULL;
    for (i = 0; i < n; i++)
    {
        a = BHInsertLast(BHGetRoot(a), items[i]);//datat is inserted with the CBT method
        a->priority = priorities[i];
    }
    a = BHGetRoot(a);
    postorderheap(a);//we heapify the deepest internal nodes in post order
    return BHGetRoot(a);
}

void BHRemove(BHtree tree)//we delete root because it has the highest priority
{
    BHtree newroot, temp = BHGetLast(tree);
    newroot = tree;
    newroot->priority = temp->priority;
    newroot->data = temp->data;//data between root and last node are exchanged
    BHRemoveLast(newroot);//we delete the last node which is now the previous root
    heapify_down(newroot);//we put the data of the root in it's place to reaquire heap characteristic
}

void BHInsert(BHtree tree, int priority, BHitem item)
{
    BHtree a = tree;
    a = BHInsertLast(a, item);
    a->priority = priority;
    heapify_up(a);//insert it last.move it up as far as it can go
}

void heapify_up(BHtree tree)
{
    if (tree == NULL)
        return;
    if (tree->paren == NULL)
        return;//it is root
    BHtree heap = tree;
    BHitem tempd;
    int tempp;
    if (tree->priority > tree->paren->priority)
    {
        tempd = heap->data;
        heap->data = heap->paren->data;
        heap->paren->data = tempd;
        tempp = heap->priority;
        heap->priority = heap->paren->priority;
        heap->paren->priority = tempp;//simple data and priority swap
        heapify_up(heap->paren);//same data and priority on an upper level 
    }
}
void postorderheap(BHtree tree)
{
    if (BHIsEmpty(tree, tree))
        return;
    if (BHIsLeaf(tree, tree))
        return;
    postorderheap(tree->left);
    postorderheap(tree->right);
    heapify_down(tree);//look line 71
}

void heapify_down(BHtree tree)
{
    char go = 't';
    BHitem tempd;
    int tempp;
    if (BHIsLeaf(tree, tree))
        return;//no children.right spot reached
    if (BHIsEmpty(tree->left, tree->left))
    {
        go = 'r';
    }
    else if (BHIsEmpty(tree->right, tree->right))
    {
        go = 'l';
    }
    if (go == 't')//has both children
    {
        if (tree->left->priority > tree->right->priority)
            go = 'l';
        else
            go = 'r';
    }//goes where the highest priotiry is
    BHnode heap = tree;
    if (go == 'l')
    {
        if (heap->priority < heap->left->priority)
        {
            tempd = heap->data;
            heap->data = heap->left->data;
            heap->left->data = tempd;
            tempp = heap->priority;
            heap->priority = heap->left->priority;
            heap->left->priority = tempp;//simple data and priority swap
            heapify_down(heap->left);
        }
    }
    else
    {
        if (heap->priority < heap->right->priority)
        {
            tempd = heap->data;
            heap->data = heap->right->data;
            heap->right->data = tempd;
            tempp = heap->priority;
            heap->priority = heap->right->priority;
            heap->right->priority = tempp;
            heapify_down(heap->right);
        }
    }
}

int BHGetMaxPriority(BHtree tree)
{
    BHnode temp = BHGetRoot(tree);
    return temp->priority;
}
#else

int BHGetMaxPriority(BHtree tree)
{
    return tree->priority[1];
}

BHtree BHHeapify(int n, int *priorities, BHitem *items)
{
    int i;
    BHtree a = BHcreate(n + 5);//create space for items + some other possible insertions the user might want
    for (i = 0; i < n; i++)
    {
        a = BHInsertLast(a, items[i]);
        a->priority[i + 1] = priorities[i];
    }
    for (i = 1; i < a->size + 1; i++)
        visit(a, i);
    printf("\n");
    postorderheap(a, 1); //leaf and empty custom for array
    return a;
}

void postorderheap(BHtree tree, BHnode node)
{
    if (BHIsEmpty(tree, node))
        return;
    if (BHIsLeaf(tree, node))
        return;
    postorderheap(tree, LEFT(node));
    postorderheap(tree, RIGHT(node));
    heapify_down(tree, node);
}

void heapify_down(BHtree tree, BHnode node)
{
    char go = 't';
    BHitem tempd;
    int tempp;
    if (BHIsLeaf(tree, node))
        return;
    if (BHIsEmpty(tree, LEFT(node)))
    {
        go = 'r';
    }
    else if (BHIsEmpty(tree, RIGHT(node)))
    {
        go = 'l';
    }
    if (go == 't')
    {
        if (tree->priority[LEFT(node)] > tree->priority[RIGHT(node)])
            go = 'l';
        else
            go = 'r';
    }
    BHtree heap = tree;
    if (go == 'l')
    {
        if (heap->priority[node] < heap->priority[LEFT(node)])
        {
            tempd = heap->items[node];
            heap->items[node] = heap->items[LEFT(node)];
            heap->items[LEFT(node)] = tempd;
            tempp = heap->priority[node];
            heap->priority[node] = heap->priority[LEFT(node)];
            heap->priority[LEFT(node)] = tempp;
            heapify_down(heap, LEFT(node));
        }
    }
    else
    {
        if (heap->priority[node] < heap->priority[RIGHT(node)])
        {
            tempd = heap->items[node];
            heap->items[node] = heap->items[RIGHT(node)];
            heap->items[RIGHT(node)] = tempd;
            tempp = heap->priority[node];
            heap->priority[node] = heap->priority[RIGHT(node)];
            heap->priority[RIGHT(node)] = tempp;
            heapify_down(heap, RIGHT(node));
        }
    }
}

void BHRemove(BHtree tree)
{
    BHnode temp = BHGetLast(tree);
    BHtree newroot = tree;
    newroot->priority[1] = newroot->priority[temp];
    newroot->items[1] = newroot->items[temp];
    BHRemoveLast(newroot);
    heapify_down(newroot, 1);
}

void BHInsert(BHtree tree, int priority, BHitem item)
{
    BHtree a = tree;
    a = BHInsertLast(a, item);
    a->priority[BHGetLast(tree)] = priority;
    heapify_up(a, BHGetLast(tree));
}

void heapify_up(BHtree tree, BHnode node)
{
    if (BHIsEmpty(tree, node))
        return;
    if (BHIsEmpty(tree, PAREN(node)))
        return;
    BHtree heap = tree;
    BHitem tempd;
    int tempp;
    if (tree->priority[node] > tree->priority[PAREN(node)])
    {
        tempd = heap->items[node];
        heap->items[node] = heap->items[PAREN(node)];
        heap->items[PAREN(node)] = tempd;
        tempp = heap->priority[node];
        heap->priority[node] = heap->priority[PAREN(node)];
        heap->priority[PAREN(node)] = tempp;
        heapify_up(heap, PAREN(node));
    }
}

#endif
