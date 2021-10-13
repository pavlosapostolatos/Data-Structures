#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ask2declare.h"
int main()
{
	int i;
	listnode a, b, c, del, add, int1 = NULL, int2 = NULL;
	data item;
	char itemtype[4];
	char scantype[4];
	strcpy(itemtype, "%s ");
	CompareType compare = &comp1;
	a = create();
	printf("list with dummies created\n");
	printf("type data to be added last\n");
	strcpy(item,"sk");
	a = insertlast(a, item);
	print(a, itemtype);
	printf("again\n");
	strcpy(item,"dit");
	a = insertlast(a, item);
	print(a, itemtype);
	printf("type data to be searched in list\n");
	strcpy(item,"sk");
	add = search(a, item, compare);
	printf("type data to be inserted after the item you searched for\n");
	strcpy(item,"chi");
	c = insertafter(a, item, add);
	print(c, itemtype);
	printf("type data to be inserted before the item you searched for\n");
	strcpy(item,"k08");
	c = insertbefore(a, item, add);
	print(c, itemtype);
	printf("type data to be deleted from list\n");
	strcpy(item,"chi");
	del = search(a, item, compare);
	c = Delete(c, del);
	print(c, itemtype);
	printf("testing delete last\n");
	c = deletelast(c);
	print(c, itemtype);
	printf("searching for string <<jhg>> and trying to delete a random node that dont exist\n");
	strcpy(item,"jhg");
	print(search(c,item, compare), itemtype);
	listnode ran=create();
	strcpy(ran->airport,"jhg");
	Delete(c,ran);
}
