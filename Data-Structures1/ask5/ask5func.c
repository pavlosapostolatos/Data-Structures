#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ask5declare.h"
listnode similar(data key){
	FILE *fp;
	listnode similar=NULL;
	char ch;
	int n=countlines("words");//μετράω γραμμες για να δεσμεύσω ακριβω; οσο χωρο χρειάζομαι
	int i,wordsize;
	char **lex;
	data backup;
	strcpy(backup,key);//αντιγραφω την λεξη γιατί θα γινουν μετατροπες
	printf("file has %d lines\n",n);
	fp=fopen("words","r");
	if (!fp) return NULL;
	lex=(char**)malloc(n*sizeof(char*));
	for (i=0;i<n;i++) lex[i]=(char*)malloc(11*sizeof(char));//στο λεξικο ο μεγιστο μεγεθος λεξης ειναι 10+1 για το \0
	i=-1;
	while(!feof(fp)){
		i++;
		fscanf(fp,"%s",*(lex+i));//μια λέξη string του αρχειου καταλαμβάνει μια σειρά του πίνακα
	}
	qsort(lex, n, sizeof(char*), myCompare);//στην default qsort της c περνάμε πρωτα τον πινακα που θα ταξινομηθεί την διασταση του τι τυπο δεδομενων εχει και μια συναρτηση που θα της λεει τι σύγκριση θα κάνει
	//for (i=0;i<n;i++) printf("%s\n",*(lex+i));
	wordsize=strlen(key);
	printf("%d\n",wordsize);
	for(i=0;i<wordsize;i++){//αλλαζει καθε γραμμα της λέξης
		strcpy(key,backup);//επειδη η διαφορα θα ειναι καθε φορα κατα 1 γραμμα πρεπει να επαναφερουμε την αρχικη λέξη
	for(ch='a';ch<='z';ch++){//δοκιμαζουμε όλα τα πιθανά γραμματα
	if(key[i]==ch) continue;
	else key[i]=ch;
	if(bsearch(&key,lex,n, sizeof(char*),myCompare)!= NULL ) {//στην default bsearch της c περνάμε πρωτα το αντικειμενο που ψάχνουμε τον πινακα που θα αναζητηθεί την διασταση του τι τυπο δεδομενων εχει και μια συναρτηση που θα της λεει τι σύγκριση θα κάνει
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
int myCompare (const void * a, const void * b ){//η qsort και η bsearch χρησιμποιουν void* δεικτεσ για να λειτουργουν για καθε τυπο δεδομενων.για αυτο η mycompare πρεπει να δεχεται void*
    const char *pa = *(const char**)a;//επίσης μεσα σε επανάληψη τα δεδομένα ταξινομούνται//συγκρίνονται σε ζευγάρια
    const char *pb = *(const char**)b;//τα pa pb ειναι char*(string).Ta a kai b γινονται cast σε string για να λειτουργουν όπως εχουμε μαθει τα char*
    return strcmp(pa,pb);//καθε πιθανη mycopare πρεπει να επιστρεφει int 0 οταν τα 2 δεδομένα ειναι ίδια γιατί ετσι ειναι προγραμματισμένες οι qsort bsearch
}

int countlines(char *filename)
{
  // count the number of lines in the file called filename                                    
  FILE *fp = fopen(filename,"r");//απλο διαβασμα απο την αρχη του κειμενου
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

