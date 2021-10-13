#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "hashtypes1.h"
Hash HTCreate();
Hash CustomHTCreate(int);
int HTSize(Hash);
int HTGet(Hash, KeyType, ItemType *);
void HTInsert(Hash *, KeyType, ItemType);
void HTRemove(Hash, KeyType);
void HTDestroy(Hash);
void HTVisit(Hash, Visit);
int hashcode(char *, int n);
void Destroylist(list);
void Print(list a, Visit vst);
double load(Hash);
list Insertlast(list, KeyType, ItemType Item);
list searchlist(list, KeyType);
list delete (list, list);
list Deletefirst(list);
void visit(Entry *);
int HTGetindex(Hash hash, KeyType Key);
