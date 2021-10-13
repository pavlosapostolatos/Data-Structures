#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ask5declare.h"
listnode similar(data key){
	FILE *fp;
	listnode similar=NULL;
	char ch;
	int n=countlines("words");//������ ������� ��� �� �������� ������; ��� ���� ����������
	int i,wordsize;
	char **lex;
	data backup;
	strcpy(backup,key);//��������� ��� ���� ����� �� ������ ����������
	printf("file has %d lines\n",n);
	fp=fopen("words","r");
	if (!fp) return NULL;
	lex=(char**)malloc(n*sizeof(char*));
	for (i=0;i<n;i++) lex[i]=(char*)malloc(11*sizeof(char));//��� ������ � ������� ������� ����� ����� 10+1 ��� �� \0
	i=-1;
	while(!feof(fp)){
		i++;
		fscanf(fp,"%s",*(lex+i));//��� ���� string ��� ������� ������������ ��� ����� ��� ������
	}
	qsort(lex, n, sizeof(char*), myCompare);//���� default qsort ��� c ������� ����� ��� ������ ��� �� ����������� ��� �������� ��� �� ���� ��������� ���� ��� ��� ��������� ��� �� ��� ���� �� �������� �� �����
	//for (i=0;i<n;i++) printf("%s\n",*(lex+i));
	wordsize=strlen(key);
	printf("%d\n",wordsize);
	for(i=0;i<wordsize;i++){//������� ���� ������ ��� �����
		strcpy(key,backup);//������ � ������� �� ����� ���� ���� ���� 1 ������ ������ �� ������������ ��� ������ ����
	for(ch='a';ch<='z';ch++){//����������� ��� �� ������ ��������
	if(key[i]==ch) continue;
	else key[i]=ch;
	if(bsearch(&key,lex,n, sizeof(char*),myCompare)!= NULL ) {//���� default bsearch ��� c ������� ����� �� ����������� ��� �������� ��� ������ ��� �� ���������� ��� �������� ��� �� ���� ��������� ���� ��� ��� ��������� ��� �� ��� ���� �� �������� �� �����
		//printf("Found item = %s\n", key);
      if (strcmp(key,backup)!=0) similar=insertlast(similar,key);
   } else {
      //printf("Item = %s could not be found\n", key);
   }
}
}
for(i=0;i<n;i++) free (lex[i]);
free (lex);
strcpy(key,backup);
print(similar,"%s ");
printf("\n");

return similar;
}
int myCompare (const void * a, const void * b ){//� qsort ��� � bsearch ������������ void* ������� ��� �� ����������� ��� ���� ���� ���������.��� ���� � mycompare ������ �� ������� void*
    const char *pa = *(const char**)a;//������ ���� �� ��������� �� �������� �������������//������������ �� ��������
    const char *pb = *(const char**)b;//�� pa pb ����� char*(string).Ta a kai b �������� cast �� string ��� �� ����������� ���� ������ ����� �� char*
    return strcmp(pa,pb);//���� ������ mycopare ������ �� ���������� int 0 ���� �� 2 �������� ����� ���� ����� ���� ����� ����������������� �� qsort bsearch
}

int countlines(char *filename)
{
  // count the number of lines in the file called filename                                    
  FILE *fp = fopen(filename,"r");//���� �������� ��� ��� ���� ��� ��������
  int ch=0;
  int lines=0;

  if (fp == NULL)
  return 0;

  lines++;
while(!feof(fp))
{
  ch = fgetc(fp);
  if(ch == '\n')
    lines++;
}
  fclose(fp);
  return lines;
}

listnode insertlast(listnode list,data item){
	listnode templist,newlist,prev_list;
	newlist=list;
	templist=newlist;
	if (list==NULL){
		templist=(listnode)malloc(sizeof(struct list_type));
		strcpy(templist->airport,item);
		templist->next=NULL;
	}
	else{
		while (newlist!=NULL) {
		prev_list=newlist;
		newlist=newlist->next;
		}
	newlist=(listnode)malloc(sizeof(struct list_type));
	strcpy(newlist->airport,item);
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

