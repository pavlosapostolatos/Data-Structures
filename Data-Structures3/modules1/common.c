#include "hash1.h"
Hash HTCreate()
{
	return CustomHTCreate(MAXSIZE);//useful for size doubling after load factor is surpassed
}

Hash CustomHTCreate(int n)
{
	int i;
	Hash a = (Hash)malloc(sizeof(hash));
	a->size = n;
	a->table = (Content *)malloc(n * sizeof(Content));
	for (i = 0; i < n; i++)
	{
		a->table[i] = NULL;
	}
	return a;
}

double load(Hash hash)
{
	return (double)HTSize(hash) / (double)hash->size;
}

int hashcode(char *K, int n)
{
	int h = 0, a = 33, i = 0;
	for (; K[i] != '\0'; i++)
		h = (a * h + K[i]) % n;
	return h;
}

void visit(list node)
{
	printf("K %s I %d --", node->key, node->item.integer);//key string is printed next to it's item
}
