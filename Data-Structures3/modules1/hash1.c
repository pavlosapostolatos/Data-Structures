#include "hash1.h"
//separate chaining implementaion
int HTSize(Hash hash)
{
	int i, nodes = 0;
	list *Table = hash->table;
	list cell;
	for (i = 0; i < hash->size; i++)
		for (cell = Table[i]; cell != NULL; cell = cell->next)
			nodes++;
	return nodes;
}

int HTGet(Hash hash, KeyType Key, ItemType *Item)
{
	int h;
	list temp, T;
	h = hashcode(Key, hash->size);//hashcode tells us where to put a new key and where we can find it
	T = hash->table[h];
	if ((temp = searchlist(T, Key)) == NULL)
		return 0;
	else
	{
		(*Item).integer = temp->item.integer;
		return 1;
	}
}
void HTInsert(Hash *hash, KeyType Key, ItemType Item)
{
	Hash temphash = *hash;
	list *Table = temphash->table;
	int h, i;
	list temp, T, cell;
	Hash newhash;
	if (load(temphash) < 0.9)
	{
		h = hashcode(Key, temphash->size);
		T = (temphash)->table[h];
		if ((temp = searchlist(T, Key)) != NULL)
			temp->item.integer = Item.integer;//if it exists just update item
		else
			temphash->table[h] = Insertlast(T, Key, Item);//else add it
	}
	else
	{
		newhash = CustomHTCreate(2 * temphash->size);//if load factor is surpassed we create with hash table
		for (i = 0; i < temphash->size; i++)//readd data in new positions because of hashcode
			for (cell = Table[i]; cell != NULL; cell = cell->next)
				HTInsert(&newhash, cell->key, cell->item);
		HTInsert(&newhash, Key, Item);
		HTDestroy(temphash);//delete old hashtbale because it is useless now
		*hash = newhash;
	}
}

void HTRemove(Hash hash, KeyType Key)
{
	int h;
	list temp, T;
	h = hashcode(Key, hash->size);
	T = hash->table[h];
	temp = searchlist(T, Key);
	hash->table[h] = delete (T, temp);
}
void HTDestroy(Hash hash)
{
	int i;
	list *Table = hash->table;
	for (i = 0; i < hash->size; i++)
		Destroylist(Table[i]);
	free(Table);
	free(hash);
}

void HTVisit(Hash hash, Visit vst)
{
	int i;
	list *Table = hash->table;
	for (i = 0; i < hash->size; i++)
	{
		if (Table[i] == NULL)
			printf("empty cell");
		else
			Print(Table[i], vst);
		printf("\n");
	}
}

void Destroylist(list a)
{
	if (a == NULL)
		return;
	Destroylist(a->next);
	free(a->key);
	free(a);
}

void Print(list a, Visit vst)
{
	list node = a;
	while (node != NULL)
	{
		vst(node);
		node = node->next;
	}
}

list Insertlast(list List, KeyType Key, ItemType Item)
{
	list templist, newlist, prev_list;
	newlist = List;
	templist = newlist;
	if (List == NULL)
	{
		templist = (list)malloc(sizeof(struct TableEntry));
		templist->key = malloc(MAXKEYSIZE * sizeof(char));
		strcpy(templist->key, Key);
		templist->item.integer = Item.integer;
		templist->next = NULL;
	}
	else
	{
		while (newlist != NULL)
		{
			prev_list = newlist;
			newlist = newlist->next;
		}
		newlist = (list)malloc(sizeof(struct TableEntry));
		newlist->key = malloc(MAXKEYSIZE * sizeof(char));
		strcpy(newlist->key, Key);
		newlist->item.integer = Item.integer;
		newlist->next = NULL;
		prev_list->next = newlist;
	}
	return templist;
}
list searchlist(list node, KeyType Key)
{
	list cell;
	for (cell = node; cell != NULL; cell = cell->next)
		if (strcmp(cell->key, Key) == 0)
			return cell;
	return NULL;
}

list delete (list List, list node)
{
	int found = 0;
	list newlist, templist, prev_list;
	if (List == node)
		return Deletefirst(List);
	if (List == NULL)
		return List;
	else
	{
		templist = List;
		newlist = List;
	}
	while (newlist != NULL)
	{
		if (newlist == node)
		{
			found = 1;
			prev_list->next = newlist->next; 
			free(newlist);
		}
		prev_list = newlist;
		newlist = newlist->next;
	}
	printf("node was %s found\n", found ? "" : "not");
	return templist;
}

list Deletefirst(list List)
{
	list newlist, templist;
	templist = List;
	newlist = List->next;
	free(templist);
	return newlist;
}
