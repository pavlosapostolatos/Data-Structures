#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ask3declare.h"
listnode intsort(listnode a,listnode b)  
{
  listnode result;
  if (a==NULL)  //����� �� ������� �������� �������� �� ����� ������� ��� ����� ����� ���� ������ ������������� �� �������� while 
     return(b); 
  else if (b==NULL)//��� ������� �� ������������ ��� ����� ����� �� ����� ��� ���� ���� ���������
     return(a); 
  if (a->airport <= b->airport)  
  { 
     result = a;//���������� ��� result ������� ���� �� �������� ��� �
     result->next = intsort(a->next, b);//����� � ���� ������ ��� ������� ������ ��������� �� �� ������ ���������� �������
  } 
  else 
  { 
     result = b; //���������������� ��� ������� ����� ������������� ����� ��� ���������
     result->next = intsort(a, b->next); //��� ���� ������������� ����� ���� ������ ��� �����������.�� ��� � � �� ������������ ���� �� ������ � ������� ���������� ��� ����� �n ����� ���� �� ������ �� ��������� ��� result
  } 
  return(result);//������������ ���� ���� � ���������� ������ ��� �� ����� � ������� ��� ������ ��� �� ����� ���� main ������� � ������/dummy
}

listnode intsertlast(listnode list,data item){//��������� ��'��� ������ 1 ��� ���������
	listnode templist,newlist,prev_list;
	newlist=list;
	templist=newlist;
	if (list==NULL){
		templist=(listnode)malloc(sizeof(struct list_type));
		templist->airport=item;
		templist->next=NULL;
	}
	else{
		while (newlist!=NULL) {
		prev_list=newlist;
		newlist=newlist->next;
		}
	newlist=(listnode)malloc(sizeof(struct list_type));
	newlist->airport=item;
	newlist->next=NULL;
	prev_list->next=newlist;
	}
	return templist;
}

void  print(listnode list,char *itemtype){
	if (list==NULL) printf("the list is empty\n");
	while(list!=NULL){
		printf(itemtype, list->airport);
		list=list->next;
	}
	printf("\nlist has ended\n");
}
//�� ������ �� � ����� ����� ������������ ���� ������ ��� �� ������.dead code
int sorted(listnode a){
	listnode prev=a;
	a=a->next;
	while(a!=NULL){
		if(prev->airport > a->airport)//�� ������ ��� �������� ��������� ��� ������������ ��� ��� ������ ������� ����� ��� �����
			return 0;
		else{
			prev=a;
			a=a->next;
		}
	}
	return 1;
}
listnode deletelast(listnode list){
	listnode templist,newlist,prev_list;
	if (list==NULL) return NULL;
	if(list->next==NULL){
		return deletefirst(list);
	}
	templist=list;
	newlist=list;
	while(newlist->next!=NULL){
	prev_list=newlist;
	newlist=newlist->next;}
	free(newlist);
	prev_list->next=NULL;
	return templist;
}
listnode deletefirst (listnode list){
	listnode newlist,templist;
	templist=list;
	newlist=list->next;
	free(templist);
	return newlist;
}

