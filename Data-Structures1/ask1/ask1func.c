#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ask1declare.h"
listnode create()
{
	listnode b;
	b = (listnode)malloc(sizeof(struct list_type));
	strcpy(b->airport, "dum");
	b->next = NULL;
	return b;
}

void print(listnode list)
{
	if (list == NULL)
		printf("the list is empty\n");
	while (list != NULL)
	{
		printf("%s ", list->airport);
		list = list->next;
	}
	printf("\nlist printed\n");
}

listnode search(listnode list, data item)
{
	while (list != NULL)
		if (strcmp(list->airport, item) == 0)
			return list;
		else
			list = list->next;
	printf("item wasn't found\n");
	return NULL;
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

listnode Delete(listnode list, listnode node)
{
	int node_counter = 0, found=0;
	listnode newlist, templist, prev_list;
	if (list == node)
		return deletefirst(list);
	if (list == NULL)
		return list;
	else
	{
		templist = list;
		newlist = list;
	}
	while (newlist != NULL)
	{
		node_counter++;
		if (newlist == node)
		{
			found = 1;
			prev_list->next = newlist->next;//αφου ο ενδιάμεσος κόμβος διαγραφεται ο αριστερός και ο δεξης συνδεονται
			free(newlist);
		}
		prev_list = newlist;
		newlist = newlist->next;
	}
	printf("node was %s found\n", found ? "" : "not");
	return templist;
}

listnode deletefirst(listnode list)
{
	listnode newlist, templist;
	templist = list;
	newlist = list->next;
	free(templist);
	return newlist;
}

listnode deletelast(listnode list)
{
	listnode templist, newlist, prev_list;
	if (list == NULL)
		return NULL;
	if (list->next == NULL)
	{
		return deletefirst(list);
	}
	templist = list;
	newlist = list;
	while (newlist->next != NULL)
	{
		prev_list = newlist;
		newlist = newlist->next;
	}
	free(newlist);
	prev_list->next = NULL;
	return templist;
}

listnode insertafter(listnode list, data item, listnode node)
{
	listnode templist, newlist, b;
	newlist = list;
	templist = list;
	while (newlist != NULL)
	{
		if (newlist == node)
		{
			b = (listnode)malloc(sizeof(struct list_type));
			strcpy(b->airport, item);
			b->next = newlist->next;
			newlist->next = b;
			return templist;
		}
		else
			newlist = newlist->next;
	}
	printf("node was not found\n");
	return list;
}
