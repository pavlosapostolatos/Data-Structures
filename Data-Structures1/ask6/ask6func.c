#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ask6declare.h"

int askisi(){
	listnode sim;
	QL a,b,head,newnode,step;
	data key,start,end;;
	int i,complete=0,n=0,bima=0;
	printf("give destination word(example cat)\n");
	scanf("%s",end);
	printf("give starting word(example dog)\n");
	scanf("%s",start);
	if(strlen(start)!=strlen(end)){
		printf("give strings of same size\n");
		return 0;
	}
	a=initializeQL(end);//αρχιζουμε εισαγωντας το τελικο μας αποτέλεσμα στην ουρά.υπαρχει μονο αυτό
	head=a;//ξέρρουμε ανα πασα στιγμη την κεφαλή της λιστας ουρών
	//!!!!!ΣΗΜΑΝΤΙΚΟ.Για την κατανοηση των συναρτήσεων θυμηθείτε οτι καθε επανάληψη(βήμα)προσθετει μια πιθανη λέξη στο path και δημιουργει αλλη μια ουρά//
	while(!complete && head!=NULL){//επαναληψη μεχρι να βρουμε την λεξη η να διαγραφτουν ολοι η κομβοι αρα η μετατρόπη ειναι αδύνατη
	a=head;//υπολοποισα λιστα ουρων αντι για ουρα ουρων γιατί ο pointer tail δεν μου χρησιμευσε πουθενα και πιο πολύπλοκα structs θα εκαναν τον κώδικα ακατανόητο
	while(a!=NULL){
	if(search(a->QUEUE->Front,start)!=NULL){//βρηκαμε αυτο που ψαχνουμε?
		printf("Complete\n");
		complete=1;
		print(a->QUEUE->Front,"%s ");
		printf("bima %d\n",bima);
		return 0;
	}
	a=a->link;//ψαχνουμε καθε ουρά μας
	}
	a=head;//προσπελαση λιστας με τον δεικτη a για να δουμε αν καποια ουρα εφτασε στην τελικη λεξη και μετα επαναφερουμε το α στη αρχη της λιστας ουρων
	while(a!=NULL){
	step=a->link;//οι νεοι κομβοι θα εισχωρηθούν αναμεσα στους ήδη υπαρχοντες.το α θα παει στο step ωστε οι μετατροπές των καινουριων κόμβων να επεκταθουν στην επομενη επαναληψη
	strcpy(key,a->QUEUE->Rear->airport);//similar ψαχνουμε μόνο για το πιο προσφατο στοιχείο της μετατροπής
	sim=similar(key);
	while(sim!=NULL){
		if(search(a->QUEUE->Front,sim->airport)==NULL){//δεν προσθέτω λέξεις που υπάρχουν ήδη
			newnode=addQL(a->QUEUE->Front,sim->airport);
			insertafter(&a,&newnode);		
		}
		sim=sim->next;
	}
	head=Delete(head,a);//διαγραφω τον αρχικο κομβο
	bima++;
	a=step;
	}
}
printf("transformation is not possible\n");
	return 0;
}

QL Delete(QL list,QL node){
	int node_counter=0,found;
	QL newlist,templist,prev_list;
	if (list==node) return deletefirst(list);
	if (list==NULL) return list;
	else {
	templist=list;
	newlist=list;}
	while (newlist!=NULL){
		node_counter++;
		if (newlist==node){
			found=1;
			prev_list->link=newlist->link;
			free(newlist);	
		}
		prev_list=newlist;
newlist=newlist->link;
	}
	//printf("node was %s found\n", found ? "" : "not");
	return templist;
}

QL deletefirst (QL list){
	QL newlist,templist;
	templist=list;
	newlist=list->link;
	free(templist);
	return newlist;
}
void insertafter(QL *a,QL*b){
	(*b)->link=(*a)->link;
	(*a)->link=*b;
}
listnode search(listnode list,data item){
	while(list!=NULL)
		if (strcmp(list->airport,item)==0) return list;
		else list=list->next;
	//printf("item wasn't found\n");
	return NULL;
}

//εφτιαξα αντίστοιχες initialize and insertqueue γιατι αυτες του μαθήματος δεν βόλευαν
QL initializeQL(data end){
	QL  tempqueue;
	tempqueue=(QL)malloc(sizeof(struct queue_list));
	queue  tempq;
	tempq=(queue)malloc(sizeof(struct queue_type));
	listnode b;
	b=(listnode)malloc(sizeof(struct list_type));
	strcpy(b->airport,end);
	b->next=NULL;
	tempq->Front=b;
	tempq->Rear=b;//σε ουρα με ενα μονο στοιχείο αρχη==τελος
	tempqueue->QUEUE=tempq;
	tempqueue->link=NULL;
	return tempqueue;
}

QL  addQL(listnode prev,data new_sim){
	QL  tempqueue;
	tempqueue=(QL)malloc(sizeof(struct queue_list));
	queue  tempq;
	tempq=(queue)malloc(sizeof(struct queue_type));
	listnode b=NULL;
	while(prev!=NULL) {
	b=insertlast(b,prev->airport);
	prev=prev->next;//η καινουρια ουρα μετατροπης περιεχει το ηδη υπάρχον path 
	}
	b=insertlast(b,new_sim);//+την καινουρια similar λεξη(λογικα δεν θα ειναι μονο μία αλλα για τις υπολοιπες θα φτιαχτει αλλη ουρά)
	tempq->Front=b;
	tempq->Rear=b;
	while (b!=NULL){
		tempq->Rear=b;
		b=b->next;
	}
	tempqueue->QUEUE=tempq;
	tempqueue->link=NULL;
	return tempqueue;
}
listnode similar(data key){
	FILE *fp;
	listnode similar=NULL;
	char ch;
	int i,n,wordsize;
	n=countlines("words");
	char **lex;
	data backup;
	strcpy(backup,key);
	//printf("file has %d lines\n",n);
	fp=fopen("words","r");
	if (!fp) return 0;
	lex=(char**)malloc(n*sizeof(char*));
	for (i=0;i<n;i++) lex[i]=(char*)malloc(11*sizeof(char));
	i=-1;
	while(!feof(fp)){
		i++;
		fscanf(fp,"%s",*(lex+i));
	}
	qsort(lex, n, sizeof(char*), myCompare);
	//for (i=0;i<n;i++) printf("%s\n",*(lex+i));
	strcpy(backup,key);
	wordsize=strlen(key);
	//printf("%d\n",wordsize);
	for(i=0;i<wordsize;i++){
		strcpy(key,backup);
	for(ch='a';ch<='z';ch++){
	if(key[i]==ch) continue;
	else key[i]=ch;
	if(bsearch(&key,lex,n, sizeof(char*),myCompare)!= NULL ) {
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
//print(similar,"%s ");
//printf("\n");
return similar;
}
int myCompare (const void * a, const void * b ){
    const char *pa = *(const char**)a;
    const char *pb = *(const char**)b;
    return strcmp(pa,pb);
}

int countlines(char *filename)
{
  FILE *fp = fopen(filename,"r");
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
