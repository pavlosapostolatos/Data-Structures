#include <stdio.h>
#include <stdlib.h>
#include "ask9.h"

Tree Create(void) { return NULL; }
int compare(TreeItem a, TreeItem b)
{
	double k = a - b;
	if (k == 0.0)
		return 0;
	else
		return k;
}

TreeItem PHGetMaxItem(Tree heap)
{
	return GetData(heap);//return root data
}

Tree PHMerge(Tree heap1, Tree heap2)
{
	Tree newheap, end;
	if (IsEmpty(heap1))
		return heap2;
	else if (IsEmpty(heap2))
		return heap1;
	if (compare(heap1->data, heap2->data) > 0)
	{
		newheap = heap1;
		end = heap2;
	}
	else
	{
		newheap = heap2;
		end = heap1;
	}
	newheap = ChangeList(newheap, insertlast(GetList(newheap), end));//subtree with lowest value is inserted at the end of the other subtree's children list
	return newheap;
}

Tree PHInsert(Tree heap, TreeItem item)
{
	Tree add = AddItemTree(item);//create heap containing only item and empty children list
	return PHMerge(heap, add);//merge it with old heap
}

listnode insertlast(listnode list, Tree tree2)
{
	listnode templist, newlist;
	newlist = list;
	templist = AddTreelist(tree2);
	if (list == NULL)
	{
		return templist;//typical one node list
	}
	else
	{
		while (!IsListEmpty(GetNext(newlist)))
			newlist = GetNext(newlist);
		newlist = ChangeNext(newlist, templist);
	}
	return list;
}

Tree PHDeleteMax(Tree heap)
{
	listnode many_heaps = GetList(heap);//many lists is the list of children
	Tree a = merge_many(many_heaps);//new merged heap is returned 
	free(heap);//delete the parent(root)
	return a;
}
Tree merge_many(listnode heap)
{
	if (IsListEmpty(heap))
		return NULL;//list of children reached it's end.remember PHmerge knows what to do is given an empty tree as an arguement
	listnode heaps = heap;
	Tree heap1 = remove_first(heaps);//can be empty
	heaps = GetNext(heaps);
	Tree heap2 = remove_first(heaps);
	heaps = GetNext(heaps);//list of children moves on
	return PHMerge(PHMerge(heap1, heap2), merge_many(heaps));//each time 2 children are morged and recursively merge with the merging of the next 2
}

Tree remove_first(listnode heaps)
{
	if (IsListEmpty(heaps))
		return NULL;
	else
		return GetSubtree(heaps);
}


