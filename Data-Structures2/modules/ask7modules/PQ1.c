#include "PQ1.h"
#include <stdio.h>
#include <stdlib.h>
//we use BH functions
PQ PQCreate(int maxelem)
{
	return BHcreate(maxelem);
}

int PQIsEmpty(PQ tree, PQnode node)
{
	return BHIsEmpty(tree, node);
}

void PQDestroy(PQ tree)
{
	Destroy(tree);
}
PRvalue PQGetMaxPriority(PQ tree)
{
	return BHGetMaxPriority(tree);
}
PQItem PQGetMaxItem(PQ tree)
{
	return BHGetMaxItem(tree);
}
void PQInsert(PQ *tree, PQItem item, PRvalue pr, CompareType compare)
{
	PQ a = *tree;
	if (a == NULL)
	{
		PRvalue *Pr = (PRvalue *)malloc(sizeof(PRvalue));
		PQItem *items = (PQItem *)malloc(sizeof(PQItem));
		items[0] = item;
		Pr[0] = pr;
		a = BHHeapify(1, Pr, items);
		*tree = a;
	}//if given empty tree we create 1 item array and return bhheapify result because BHinsert is void so it cant return a filled tree if given an empty one
	else
	{
		BHInsert(a, pr, item);
	}
}

void Delete(PQ tree)
{
	BHRemove(tree);
}

void LevelOrder(PQ a, Visit vst)
{
	BHLevelOrder(a, vst);
}
