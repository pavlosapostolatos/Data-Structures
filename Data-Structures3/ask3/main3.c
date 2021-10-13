#include "similar.h"
#include "time.h"
	char** lex;

int main()
{
	char end[10], start[10];
	int n,i;
	printf("give destination word(example cat)\n");
	scanf("%s", end);
	printf("give starting word(example dog)\n");
	scanf("%s", start);
	if (strlen(start) != strlen(end))
	{
		printf("give strings of same size\n");
		return -1;
	}
	char** lex;
	lex=takewords(&n,start);
	Graph a = UGCreate();
	UGAddVertex(&a, end);
	UGAddVertex(&a, start);
	MakePaths(&a, start, end,lex,n);
	UGShortestPath(a, start, end);
	clock_t clock();
	float t1=((float) clock())/CLOCKS_PER_SEC;
	printf("done in %f seconds\n", t1);
	for(i=0;i<n;i++) free (lex[i]);
	free (lex);
	UGDestroy(a);
}
