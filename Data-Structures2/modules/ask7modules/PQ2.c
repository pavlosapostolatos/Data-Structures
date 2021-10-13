#include "PQ2.h"
#include <stdio.h>
#include <stdlib.h>
PQ PQCreate(int maxelem)
{//we call BST functions
	return BSTcreate(maxelem);
}

int PQIsEmpty(PQ tree, PQnode node)
{
	return BSTIsEmpty(tree, node);
}

void PQDestroy(PQ tree)
{
	Destroy(tree);
}

PRvalue PQGetMaxPriority(PQ tree)
{
	return BSTGetKey(tree, BSTGetMaxKey(tree, BSTGetRoot(tree)));
}
PQItem PQGetMaxItem(PQ tree)
{
	return BSTGetItem(tree, BSTGetMaxKey(tree, BSTGetRoot(tree)));
}

void Delete(PQ tree)
{
	deleteNode(tree, PQGetMaxPriority(tree));
}

void PQInsert(PQ *tree, PQItem item, PRvalue pr, CompareType compare)
{
	PQ a = *tree;
	if (a == NULL)
	{
		*tree = sorted_insert(a, item, pr, compare);
	}
	else
		sorted_insert(a, item, pr, compare);
}

void LevelOrder(PQ a, Visit vst)
{
	BTLevelOrder(a, vst);
}
