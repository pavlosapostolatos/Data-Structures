#include "module6_1.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
BSTnode BSTGetRoot(BSTtree tree)
{
    return BTGetRoot(tree);
}
BSTtree BSTcreate(int maxelem)
{
    return BTcreate(maxelem);
}

int BSTIsEmpty(BSTtree tree, BSTnode node)
{
    return BTIsEmpty(tree, node);
}

void BSTInOrder(BSTtree tree, Visit visit)
{
    BTInOrder(tree, visit);
}

void BSTChange(BSTtree tree, BSTnode node, BSTitem item)
{
    return BTChange(tree, node, item);
}

BSTnode Search(BSTtree tree, BSTnode node, BSTKeyType key, CompareType compare)
{
    if (BSTIsEmpty(tree, node) || compare(BSTGetKey(tree, node), key) == 0)
        return node;
    if (compare(BSTGetKey(tree, node), key) < 0)
        return Search(tree, BSTGetChildRight(tree, node), key, compare);
    return Search(tree, BSTGetChildRight(tree, node), key, compare);
}

BSTnode BSTGetChildLeft(BSTtree tree, BSTnode node)
{
    return BTGetChildLeft(tree, node);
}

BSTnode BSTGetChildRight(BSTtree tree, BSTnode node)
{
    return BTGetChildRight(tree, node);
}

BSTnode BSTGetMaxKey(BSTtree tree, BSTnode node)
{
    BSTnode temp = node;
    while (BTIsEmpty(tree, BSTGetChildRight(tree, temp)) == 0)
        temp = BSTGetChildRight(tree, temp);
    return temp;
}

BSTnode BSTGetMinKey(BSTtree tree, BSTnode node)
{
    BSTnode temp = node;
    while (BTIsEmpty(tree, BSTGetChildLeft(tree, temp)) == 0)
        temp = BSTGetChildLeft(tree, temp);
    return temp;
}
BSTitem BSTGetItem(BSTtree tree, BSTnode node)
{
    return BTGetItem(tree, node);
}

BSTtree deleteNode(BSTtree tree, BSTitem key)
{
    return del(tree, BTGetRoot(tree), key);
}

BSTtree del(BSTtree tree, BSTnode node, BSTitem key)
{
    if (BSTIsEmpty(tree, node))
        return tree;
    if (tree->compare(key, BSTGetKey(tree, node)) > 0)
        del(tree, BSTGetChildRight(tree, node), key);
    else if (tree->compare(key, BSTGetKey(tree, node)) < 0)
        del(tree, BSTGetChildLeft(tree, node), key);//typical search on a sorted tree
    else
    {//has been found
        if (BSTIsEmpty(tree, BSTGetChildLeft(tree, node)) && BSTIsEmpty(tree, BSTGetChildRight(tree, node)))
        {//no children.can delete immediately
            kill(tree, node);
            return tree;
        }
        else if (BSTIsEmpty(tree, BSTGetChildLeft(tree, node)))
        {
            BSTnode temp = BSTGetMinKey(tree, BSTGetChildRight(tree, node));//basically returns leftmost leaf to temp
            BTChangeKey(tree, node, BSTGetKey(tree, temp));//i exhanged key and data with lowest value item of the node's right subtree. 
            BTChange(tree, node, BTGetItem(tree, temp));//remember we checked if the found node is a leaf so it definetely has a right child if left is empty
            del(tree, temp, BSTGetKey(tree, temp));//we delete temp which is definetely a leaf so in recursion it will go straight into the kill function (line 85)
        }
        else if (BSTIsEmpty(tree, BSTGetChildRight(tree, node)))
        {//same thing in reverse
            BSTnode temp = BSTGetMaxKey(tree, BSTGetChildLeft(tree, node));
            BTChangeKey(tree, node, BSTGetKey(tree, temp));
            BTChange(tree, node, BTGetItem(tree, temp));
            del(tree, temp, BSTGetKey(tree, temp));
        }
    }
    return tree;
}

#ifdef BT_IMPL_LINKED

BSTtree sorted_insert(BSTtree tree, BSTitem item, BSTKeyType key, CompareType compare)
{
    if (BSTIsEmpty(tree, tree))
        return NEW(item, NULL, NULL, key, compare);//we only insert at yth bottom of a BST
    if (compare(BSTGetKey(tree, tree), key) > 0)
    {
        Changeleft(&tree, sorted_insert(BSTGetChildLeft(tree, tree), item, key, compare));
        BTtree a = BSTGetChildLeft(tree, tree);
        Changeparen(&a, tree);//setting pointers right.O
    }
    else
    {
        Changeright(&tree, sorted_insert(BSTGetChildRight(tree, tree), item, key, compare));
        BTtree b = BSTGetChildRight(tree, tree);
        Changeparen(&b, tree);
    }
    return tree;
}
//cancelled code but still functional and optimised for our exercise and tree structure
BSTnode insert_at_head(BSTnode tree, BSTitem item, BSTKeyType key, CompareType compare)
{
    if (BTIsEmpty(tree, tree))
        return NEW(item, NULL, NULL, key, compare);
    if (compare(tree->key, key) > 0)
    {
        tree->left = sorted_insert(BSTGetChildLeft(tree, tree), item, key, compare);
        tree->left->paren = tree;
        tree = RotateRight(tree);
    }
    else
    {
        tree->right = sorted_insert(BSTGetChildRight(tree, tree), item, key, compare);
        tree->right->paren = tree;
        tree = RotateLeft(tree);
    }
    return tree;
}
BSTnode RotateRight(BSTnode h)
{
    BSTnode x = h->left;
    x->paren = h->paren;
    h->paren = x;
    h->left = x->right;
    if (!BSTIsEmpty(x->right, x->right))
        x->right->paren = h;
    x->right = h;
    return x;
}

BSTnode RotateLeft(BSTnode h)
{
    BSTnode x = h->right;
    h->right = x->left;
    if (!BSTIsEmpty(x->left, x->left))
        x->left->paren = h;
    x->left = h;
    x->paren = h->paren;
    h->paren = x;
    return x;
}

#else

BSTtree sorted_insert(BSTtree tree, BSTitem item, BSTKeyType key, CompareType compare)
{
    tree->compare = compare;
    return SI(tree, 1, item, key);//startting from root
}

BSTtree SI(BSTtree tree, BSTnode node, BSTitem item, BSTKeyType key)
{//applying same logic
    if (BSTIsEmpty(tree, node))
    {
        BTChange(tree, node, item);
        BTChangeKey(tree, node, key);
        return tree;
    }
    if (tree->compare(BSTGetKey(tree, node), key) > 0)
        return SI(tree, BSTGetChildLeft(tree, node), item, key);
    else
        return SI(tree, BSTGetChildRight(tree, node), item, key);
}

#endif
