#include "graph.h"
int main()
{
	Graph a;
	a = UGCreate();
	UGAddVertex(&a, "daenerys");
	UGAddVertex(&a, "jon");
	UGAddVertex(&a, "arya");
	UGAddVertex(&a, "sansa");
	UGAddVertex(&a, "jorah");
	UGAddVertex(&a, "tyrion");
	UGAddVertex(&a, "jaimie");
	UGAddVertex(&a, "cercei");
	//UGVisit(a);
	UGAddEdge(a, "daenerys", "jon");
	UGAddEdge(a, "daenerys", "tyrion");
	UGAddEdge(a, "daenerys", "sansa");
	UGAddEdge(a, "daenerys", "jorah");
	UGVisit(a);
	UGRemoveEdge(a, "daenerys", "sansa");
	UGRemoveVertex(a, "jorah");
	printf("daenerys' edges\n");
	Nbr l = UGGetAdjacent(a, "daenerys");
	for (; l != NULL; l = l->link)
		printf("%s ", l->cell->key);
	printf("\n");
	printf("making connections\n");
	UGAddEdge(a, "tyrion", "sansa");
	UGAddEdge(a, "jon", "arya");
	UGAddEdge(a, "arya", "sansa");
	printf("path from daenerys to sansa\n");
	l = UGShortestPath(a, "daenerys", "sansa");
	UGDestroy(a);
	return 0;
}
