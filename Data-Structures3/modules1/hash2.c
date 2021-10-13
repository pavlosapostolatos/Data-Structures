#include "hash1.h"

int HTSize(Hash hash)
{
	int i, nodes = 0;
	Content *Table = hash->table;
	for (i = 0; i < hash->size; i++)
		if (Table[i] != NULL)
			if (Table[i]->deleted == 0)
				nodes++;
	return nodes;
}

int HTGet(Hash hash, KeyType Key, ItemType *Item)
{
	int h;
	if ((h = HTGetindex(hash, Key)) == -1)
	{
		printf("didnt find key \n");
		return 0;
	}
	(*Item).integer = hash->table[h]->item.integer;
	return 1;
}

int HTGetindex(Hash hash, KeyType Key)
{
	int h, step = 1;
	h = hashcode(Key, hash->size);
	Content *Table = hash->table;
	while ((Table[h] != NULL) && (Table[h]->deleted == 1 || strcmp(Table[h]->key, Key) != 0))
	{
		h -= step;
		if (h < 0)
			h += hash->size;
	}
	if (Table[h] != NULL)
	{
		return h;
	}
	return -1;
}

void HTDestroy(Hash hash)
{
	int i;
	Content *Table = hash->table;
	for (i = 0; i < hash->size; i++)
		if (Table[i] != NULL)
		{
			free(Table[i]->key);
			free(Table[i]);
		}
	free(Table);
	free(hash);
}

void HTRemove(Hash hash, KeyType Key)
{
	int h;
	if ((h = HTGetindex(hash, Key)) == -1)
	{
		printf("didnt find key to delete\n");
		return;
	}
	hash->table[h]->deleted = 1;//nodes marked as deleted throughout the functions are considered empty as if they were NULL
	free(hash->table[h]->key);//we also free thenow cancelled key.when inserting into a deleted node key is remalloced
	return;
}

void HTVisit(Hash hash, Visit vst)
{
	int i;
	Content *Table = hash->table;
	for (i = 0; i < hash->size; i++)
	{
		if (Table[i] == NULL || Table[i]->deleted == 1)
			printf("empty cell");
		else
			vst(Table[i]);
		printf("\n");
	}
}

void HTInsert(Hash *hash, KeyType Key, ItemType Item)//same idea and structure as the separate chaining algorithm
{
	Hash temphash = *hash;
	Content *Table = temphash->table;
	int h, i, step = 1;
	Content cell;
	Hash newhash;
	if (load(temphash) < 0.5)
	{
		h = hashcode(Key, temphash->size);
		while (Table[h] != NULL && Table[h]->deleted == 0 && strcmp(Table[h]->key, Key) != 0)
		{
			h -= step;
			if (h < 0)
				h += temphash->size;
		}
		if (Table[h] == NULL)
		{
			cell = (Content)malloc(sizeof(Entry));
			cell->key = (char *)malloc(MAXKEYSIZE * sizeof(char));
			strcpy(cell->key, Key);
			cell->item.integer = Item.integer;
			cell->deleted = 0;
			temphash->table[h] = cell;
		}
		else if (Table[h]->deleted == 1)
		{
			Table[h]->key = (char *)malloc(MAXKEYSIZE * sizeof(char));
			strcpy(Table[h]->key, Key);
			Table[h]->item.integer = Item.integer;
			Table[h]->deleted = 0;//only HTInsert and HTRemove changed the ->deleted value
		}
		else if (strcmp(Table[h]->key, Key) == 0)
			Table[h]->item.integer = Item.integer;
	}
	else
	{
		newhash = CustomHTCreate(2 * temphash->size);
		for (i = 0; i < temphash->size; i++)
			if (Table[i] != NULL && Table[i]->deleted == 0)
				HTInsert(&newhash, Table[i]->key, Table[i]->item);
		HTInsert(&newhash, Key, Item);
		HTDestroy(temphash);
		*hash = newhash;
	}
}
