#include <stdio.h>
#include <stdlib.h>
#include "ask9.h"
int main()
{
	Tree a, b, c;
	a = Create();
	a = PHInsert(a, 10);
	a = PHInsert(a, 9);
	a = PHInsert(a, 8);
	a = PHInsert(a, 7);
	a = PHInsert(a, 6);
	a = PHDeleteMax(a);
	printf("list a:");
	print(a);
	printf("\n");
	printf("max item is ");
	printf(TYPE, PHGetMaxItem(a));
	printf("\n");
	b = Create();
	b = PHInsert(b, 11);
	printf("\n list b:");
	print(b);
	c = PHMerge(a, b);
	printf("\n merged a and b:");
	print(c);
	printf("\n");
}
