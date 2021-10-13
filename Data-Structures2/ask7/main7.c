#include <stdio.h>
#include <stdlib.h>
#if PQ_IMPL_BH
#include "PQ1.h"
#else
#include "PQ2.h"
#endif
int main()
{
	PQ a;
	int i;
	CompareType compare = &comp2;
	Visit vst = visit;
	a = PQCreate(1000);
	for (i = 1; i <= 17; i += 4)
		PQInsert(&a, i, i * 5, compare);
	for (i = 16; i >= 0; i -= 4)
		PQInsert(&a, i, i * 5, compare);
	LevelOrder(a, vst);
	printf("\n");
	Delete(a);
	LevelOrder(a, vst);
	printf("\n");
	printf("max priority and it's item %d ", PQGetMaxPriority(a));
	printf(TYPE, PQGetMaxItem(a));
	printf("\n");
	PQDestroy(a);
}