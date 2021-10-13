#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ask1declare.h"
int main()
{
	int i;
	listnode a, b, c, del, add;
	data item;
	a = create();
	printf("list with dummy created\n");
	printf("type data to be added last\n");
	strcpy(item,"sk");
	a = insertlast(a, item);
	print(a);
	printf("one more time\n");
	strcpy(item,"dit");
	c = insertlast(a, item);
	print(c);
	printf("type data to be searched in list\n");
	strcpy(item,"sk");
	add = search(c, item);
	printf("type data to be inserted after the item you searched for\n");
	strcpy(item,"chi");
	c = insertafter(c, item, add);
	print(c);
	printf("type data to be deleted from list\n");
	strcpy(item,"chi");
	del = search(c, item);
	c = Delete(c, del);
	print(c);
	printf("testing delete last\n");
	c = deletelast(c);
	print(c);
	printf("searching for string <<jhg>> and trying to delete a random node that dont exist\n");
	print(search(c,"jhg"));
	listnode ran=create();
	strcpy(ran->airport,"jhg");
	Delete(c,ran);
}
