#include <stdio.h>
#include <stdlib.h>
#include "ask2declare.h"
#include <string.h>
int comp1(data a,data b){
return strcmp(a,b);}

int comp2(data a,data b){
	double k=a-b;
	if (k==0.0) return 0;
	else return 1;
}
listnode create(){
listnode dum1,dum2;
dum1=(listnode)malloc(sizeof(struct list_type));
strcpy(dum1->airport,"beg");
dum1->previous=NULL;
dum2=(listnode)malloc(sizeof(struct list_type));
strcpy(dum2->airport,"end");
dum2->next=NULL;
dum2->previous=dum1;
dum1->next=dum2;
return dum1;//η λιστα θα ειναι beg->real list->end
}

void  print(listnode list,char *itemtype){
	if (list==NULL) printf("the list is empty\n");
	while(list!=NULL){
		printf(itemtype, list->airport);
		list=list->next;
	}
	printf("\nlist printed\n");
}

listnode search(listnode list,data item, CompareType compare){
	while(list!=NULL)
		if (compare(item, list->airport)==0) return list;
		else list=list->next;
	printf("item wasn't found\n");
	return NULL;
}

listnode insertlast(listnode list,data item){
	listnode templist,newlist,prev_list;
	newlist=list;
	templist=newlist;
	while(templist!=NULL){
		prev_list=templist;
		templist=templist->next;
	}
	return insertbefore(list,item,prev_list);//insert πριν τον dummy του τελους
}
listnode insertbefore(listnode list,data item,listnode node){
	listnode newnode,templist,left,right,b;
	templist=list;
	b=list;
	while (templist!=NULL){
		if(templist==node){
			left=templist->previous;
			right=templist;
			newnode=(listnode)malloc(sizeof(struct list_type));
			strcpy(newnode->airport,item);
			newnode->next=right;
			newnode->previous=left;
			left->next=newnode;
			right->previous=newnode;//newnode μπαινει ενδιαμεσα απο Left kai right
			return b;
		}
	templist=templist->next;
	}
	printf("node wasn't found\n");
	return b;
}

listnode Delete(listnode list,listnode node){
	int node_counter=0,found=0;
	listnode newlist,templist,prev_list;
	templist=list;
	newlist=list;
	while (newlist!=NULL){
		node_counter++;
		if (newlist==node){
			found=1;
			prev_list->next=newlist->next;
			newlist->next->previous=newlist->previous;
			free(newlist);	
		}
		prev_list=newlist;
newlist=newlist->next;
	}
	printf("node was %s found\n", found ? "" : "not");
	return templist;
}

listnode deletefirst (listnode list){
	listnode newlist,templist;
	templist=list;
	newlist=list->next;
	free(templist);
	return newlist;
}

listnode deletelast(listnode list){
	if (list->next==NULL) return NULL;//διαγραφω τον κομβο πριν τον dummy και τον συνδεω μετα την διαγραφη με την υπολοιπη λιστα
	listnode templist,newlist,prev_list,dummy;
	templist=list;
	newlist=list;
	while(newlist->next->next!=NULL){
	prev_list=newlist;
	newlist=newlist->next;
	}
	dummy=newlist->next;
	prev_list->next=dummy;
	dummy->previous=prev_list;
	free(newlist);
	return templist;
}

listnode insertafter(listnode list,data item,listnode node){
	listnode templist,newlist,right,b;
	newlist=list;
	templist=list;
	while (newlist!=NULL){
		if (newlist==node){
			b=(listnode)malloc(sizeof(struct list_type));
			strcpy(b->airport,item);
			b->next=newlist->next;
			b->previous=newlist;
			right=newlist->next;
			newlist->next=b;
			right->previous=b;
			return templist;
		}
		else newlist=newlist->next;
	}
	printf("node was not found\n");
	return list;
}
