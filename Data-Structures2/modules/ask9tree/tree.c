#include "tree.h"
#include <stdio.h>
#include <stdlib.h>
//these are just typical functions that handle the contents of my structs.thta way pairheap doesnt get built on it's own.it justs call these functions with proper arguments
listnode ChangeNext(listnode list1, listnode list2)
{
	list1->next = list2;
	return list1;
}

Tree ChangeList(Tree tree, listnode list)
{
	tree->list = list;
	return tree;
}
TreeItem GetData(Tree tree)
{
	return tree->data;
}
listnode GetNext(listnode list)
{
	return list->next;
}
listnode GetList(Tree tree)
{
	return tree->list;
}
int IsEmpty(Tree tree)
{
	return tree == NULL;
}
Tree GetSubtree(listnode list)
{
	return list->sub_tree;
}
int IsListEmpty(listnode list)
{
	return list == NULL;
}
Tree AddItemTree(TreeItem item)
{
	Tree add = (Tree)malloc(sizeof(struct pair_heap));
	add->data = item;
	add->list = NULL;
	return add;
}
listnode AddTreelist(Tree tree)
{
	listnode templist = (listnode)malloc(sizeof(struct list_childs));
	templist->sub_tree = tree;
	templist->next = NULL;
	return templist;
}
void print(Tree heap)
{
	if (heap == NULL)
		return;
	visit(heap);
	listnode childs = GetList(heap);
	while (!IsListEmpty(childs))
	{
		print(GetSubtree(childs));
		childs = GetNext(childs);
	}
}

void visit(Tree heap)
{
	printf(TYPE, GetData(heap));
}
