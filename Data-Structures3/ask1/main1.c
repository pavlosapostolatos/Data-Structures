#include "hash1.h"
int main()
{
	Hash a;
	Visit vst = &visit;
	ItemType pitem, item;
	a = HTCreate();
	item.integer = 1;
	HTInsert(&a, "daenerys", item);
	(item.integer)++;
	HTInsert(&a, "jon", item);
	(item.integer)++;
	HTInsert(&a, "tyrion", item);
	(item.integer)++;
	HTInsert(&a, "tormund", item);
	(item.integer)++;
	HTInsert(&a, "arya", item);
	(item.integer)++;
	HTInsert(&a, "sansa", item);
	(item.integer)++;
	HTInsert(&a, "jorah", item);
	(item.integer)++;
	//resizing happens here
	HTInsert(&a, "davos", item);
	(item.integer)++;
	HTInsert(&a, "jaimie", item);
	(item.integer)++;
	HTInsert(&a, "cersei", item);
	(item.integer)++;
	HTInsert(&a, "hound", item);
	(item.integer)++;
	HTInsert(&a, "bran", item);
	(item.integer)++;
	printf("hash size is %d\n", HTSize(a));
	printf("removing jorah\n");
	HTRemove(a, "jorah");
	HTVisit(a, vst);
	printf("searching for jon\n");
	HTGet(a, "jon", &pitem);
	printf("jon's item %d\n", pitem.integer);
	HTDestroy(a);
	return 0;
}
