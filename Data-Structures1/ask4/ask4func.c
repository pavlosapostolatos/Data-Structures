#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ask4declare.h"
listnode intsort(listnode a,listnode b)  
{ 
  listnode result;
  if (a==NULL)  //����� �� ������� �������� �������� �� ����� ������� ��� ����� ����� ���� ������ ������������� �� �������� while 
     return(b); 
  else if (b==NULL)//��� ������� �� ������������ ��� ����� ����� �� ����� ��� ���� ���� ���������
     return(a); 
  if (a->airport <= b->airport)  
  { 
     result = a;//���������� ��� result ������� ���� �� �������� 
     result->next = intsort(a->next, b);//����� � ���� ������ ��� ������� ������ ��������� �� �� ������ ���������� �������
  } 
  else 
  { 
     result = b; //���������������� ��� ������� ����� ������������� ����� ��� ���������
     result->next = intsort(a, b->next); //��� ���� ������������� ����� ���� ������ ��� �����������.�� ��� � � �� ������������ ���� �� ������ � ������� ���������� ��� ����� �n ����� ���� �� ������ �� ��������� ��� result
  } 
  return(result);//������������ ���� ���� � ���������� ������ ��� �� ����� � ������� ��� ������ ��� �� ����� ���� main ������� � ������/dummy
}

listnode intsertlast(listnode list,data item){
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

void nodeswap(listnode *a, listnode *b) 
{int temp;
temp = (*a)->airport;
(*a)->airport=(*b)->airport;
(*b)->airport=temp; 
}//��� ��������������� ����
listnode mergesort(listnode a){
	int n=0,i=0;
	listnode templist=a,firstlist,secondlist;
	if(sorted(a)==0){//�� ����� ��� ������������ � �����(� ��� ������� ���(��������)) ������� return ���� �����
		split_two_halves(&templist,&firstlist,&secondlist);
		firstlist=mergesort(firstlist);//������������� �� 2 ����
		secondlist=mergesort(secondlist);
		return intsort(firstlist,secondlist);//�� 2 ���� ���� ��� ������������ �������� ���� ������ 3
	}
	else return a;
}

int sorted(listnode a){
	listnode prev=a;
	a=a->next;
	while(a!=NULL){
		if(prev->airport > a->airport)
			return 0;
		else{
			prev=a;
			a=a->next;
		}
	}
	return 1;
}


void split_two_halves(listnode* head,listnode*first,listnode *second){

    if(*head==NULL){
        printf("empty list was given.variables remained the same\n");
    }else{

        *first=*head;//�� ����� ���� ������� ��'��� ������
        listnode templist=*head;

        while(templist!=NULL && templist->next!=NULL && templist->next->next!=NULL){
            *first=(*first)->next;//� ����� ������� ��� ������� � ��������
            templist=templist->next->next;//��� � ��������
        }//���� ���� �������� �������� � templist ������ ��� ����� ���� first ����� ���� ����
        /*back halves*/
        *second=(*first)->next;//�� ������� ���� ������� ���� ��� �������� �� �����
        (*first)->next=NULL;//��� �� ����� �������� ���� ��� ������� �� �������
        //�� null ����� ��� �����
        *first=*head;//�� first ���� ���������� �� �� next ��� �� ������������ ���� ���� ��� ������ ������ �� head
    }
}

