#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ask6declare.h"
void insertafter(QL *a, QL *b)
{
	(*b)->link = (*a)->link;
	(*a)->link = *b;
}
listnode search(listnode list, data item)
{
	while (list != NULL)
		if (strcmp(list->airport, item) == 0)
			return list;
		else
			list = list->next;
	//printf("item wasn't found\n");
	return NULL;
}

listnode similar(data key, char **lex, int n)
{
	listnode similar = NULL;
	char ch;
	int i, wordsize;
	data backup;

	strcpy(backup, key);
	wordsize = strlen(key);
	for (i = 0; i < wordsize; i++)
	{
		strcpy(key, backup);
		for (ch = 'a'; ch <= 'z'; ch++)
		{
			if (key[i] == ch)
				continue;
			else
				key[i] = ch;
			if (bsearch(&key, lex, n, sizeof(char *), myCompare) != NULL)
			{
				if (strcmp(key, backup) != 0)
					similar = insertlast(similar, key);
			}
		}
	}

	strcpy(key, backup);

	return similar;
}

int myCompare(const void *a, const void *b)
{
	const char *pa = *(const char **)a;
	const char *pb = *(const char **)b;
	return strcmp(pa, pb);
}

int countlines(char *filename)
{
	FILE *fp = fopen(filename, "r");
	int ch = 0;
	int lines = 0;

	if (fp == NULL)
		return 0;

	lines++;
	while (!feof(fp))
	{
		ch = fgetc(fp);
		if (ch == '\n')
			lines++;
	}
	fclose(fp);
	return lines;
}

listnode insertlast(listnode list, data item)
{
	listnode templist, newlist, prev_list;
	newlist = list;
	templist = newlist;
	if (list == NULL)
	{
		templist = (listnode)malloc(sizeof(struct list_type));
		strcpy(templist->airport, item);
		templist->next = NULL;
	}
	else
	{
		while (newlist != NULL)
		{
			prev_list = newlist;
			newlist = newlist->next;
		}
		newlist = (listnode)malloc(sizeof(struct list_type));
		strcpy(newlist->airport, item);
		newlist->next = NULL;
		prev_list->next = newlist;
	}
	return templist;
}
void print(listnode list, char *itemtype)
{
	if (list == NULL)
		printf("the list is empty\n");
	while (list != NULL)
	{
		printf(itemtype, list->airport);
		list = list->next;
	}
	printf("\nlist has ended\n");
}
