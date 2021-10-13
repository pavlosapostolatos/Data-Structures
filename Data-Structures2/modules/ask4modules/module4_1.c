#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "module4_1.h"

int CBTHeight(CBTtree tree)
{
	return BTHeight(tree);
}

CBTtree CBTcreate(int maxelem)
{
	return BTcreate(maxelem);
}

int CBTSize(CBTtree tree)
{
	return BTSize(tree);
}

CBTnode CBTGetRoot(CBTtree tree)
{
	return BTGetRoot(tree);
}

CBTnode CBTGetParent(CBTtree tree, CBTnode node)
{
	return BTGetParent(tree, node);
}

CBTnode CBTGetChildLeft(CBTtree tree, CBTnode node)
{
	return BTGetChildLeft(tree, node);
}

CBTnode CBTGetChildRight(CBTtree tree, CBTnode node)
{
	return BTGetChildRight(tree, node);
}

void CBTPreOrder(CBTtree tree, Visit visit)
{
	BTPreOrder(tree, visit);
}

void CBTInOrder(CBTtree tree, Visit visit)
{
	BTInOrder(tree, visit);
}

void CBTPostOrder(CBTtree tree, Visit visit)
{
	BTPostOrder(tree, visit);
}

void CBTLevelOrder(CBTtree tree, Visit visit)
{
	BTLevelOrder(tree, visit);
}

CBTitem CBTGetItem(CBTtree tree, CBTnode node)
{
	return BTGetItem(tree, node);
}
void CBTChange(CBTtree tree, CBTnode node, CBTitem item)
{
	BTChange(tree, node, item);
}

int CBTIsEmpty(CBTtree tree, CBTnode node)
{
	return BTIsEmpty(tree, node);
}

#ifdef BT_IMPL_LINKED

CBTnode CBTGetLast(CBTtree tree)
{
	int h = CBTHeight(tree);
	CBTnode last;
	GETLevel(tree, h, &last);
	return last;
}

void GETLevel(CBTtree tree, int level, CBTnode *last)//it is the same algorithm that prints in level order.the last node is printed last. this node instead of getting printed 
// is inserted into the last* pointer last and returned
{
	if (CBTIsEmpty(tree, tree))
		return;
	if (level == 1)
		*last = tree;
	else if (level > 1)
	{
		GETLevel(tree->left, level - 1, last);
		GETLevel(tree->right, level - 1, last);
	}
}
CBTtree CBTInsertLast(CBTtree tree, CBTitem item)
{
	CBTnode temp, newnode;
	int h, i = 0;
	if (tree == NULL)
		return insertroot(tree, item);
	if (CBTSize(tree) == (int)pow(2, CBTHeight(tree)) - 1)//if the tree is filled up to it's last a level an new level is added with insertion at it's leftmost end
	{
		temp = tree;
		while (temp->left != NULL)
			temp = temp->left;
		newnode = (CBTnode)malloc(sizeof(Cbinary_tree));
		newnode->data = item;
		newnode->left = NULL;
		newnode->right = NULL;
		newnode->paren = temp;
		temp->left = newnode;
		//	printf("comp\n");
	}
	else
	{
		h = CBTHeight(tree);
		//printf("height %d\n",h);
		insertatlevel(tree, h - 1, item, &i);//again it is the same algorithm but we trick it to reach only the level above max-depth
	}
	return CBTGetLast(tree);
}

void insertatlevel(CBTtree tree, int level, CBTitem item, int *i)
{ //int k=*i;
	CBTnode temp, temp2 = tree;
	if (CBTIsEmpty(tree, tree))
		return;
	if (level == 1)
	{
		if (*i == 0)//insertion happens only if it hasnt happened already
		{ //printf("in\n");
			if (tree->left == NULL)//in the second to last level we search for the first node that doesnt have both children
			{//we prioritize insertion to the left child if possible to keep "last" order
				temp = (CBTnode)malloc(sizeof(Cbinary_tree));
				temp->data = item;
				temp->left = NULL;
				temp->right = NULL;
				temp->paren = temp2;
				temp2->left = temp;
				*i = 1;
				//			printf("did left\n");
			}
			else if (tree->right == NULL)
			{
				temp = (CBTnode)malloc(sizeof(Cbinary_tree));
				temp->data = item;
				temp->left = NULL;
				temp->right = NULL;
				temp->paren = temp2;
				temp2->right = temp;
				*i = 1;
				//			printf("did right\n");
			}
		}
	}
	else
	{ //printf("i %d level %d\n",*i,level);
		insertatlevel(tree->left, level - 1, item, i);
		insertatlevel(tree->right, level - 1, item, i);
	}
}
void CBTRemoveLast(CBTtree tree)
{
	if (tree->left == NULL && tree->right == NULL)//delete root
	{
		free(tree);
		return;
	}
	CBTnode node = CBTGetLast(tree);
	CBTnode par = node->paren;
	if (par->right != NULL)//fixing parent pointer.no segmentation fault because node isnt the root
		par->right = NULL;
	else if (par->left != NULL)
		par->left = NULL;
	free(node);
}

#else

CBTnode CBTGetLast(CBTtree tree)
{
	int i;
	for (i = 1; i <= tree->size; i++)//presentation is the array is level order-like so just return the last filled cell
		if (tree->items[i] == -1)
		{
			return i - 1;
		}
	return tree->size;
}

void CBTRemoveLast(CBTtree tree)
{
	tree->items[CBTGetLast(tree)] = -1;
}

CBTtree CBTInsertLast(CBTtree tree, CBTitem item)
{
	tree->items[CBTGetLast(tree) + 1] = item;//much simpler with array.we KNOW where the next "last" place is without recursion and tests 
	return tree;
}

#endif
