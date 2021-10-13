#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ask3declare.h"
listnode intsort(listnode a,listnode b)  
{
  listnode result;
  if (a==NULL)  //αυτες οι εντολες κανονικα ελεγχουν αν δωθει εξαρχης μια αδεια λιστα αλλα επισης αντικαταστουν το κλασσικο while 
     return(b); 
  else if (b==NULL)//που ελεγχει αν προσπελασαμε την λιστα μεχρι το τελος της χαρη στην ανανδρομη
     return(a); 
  if (a->airport <= b->airport)  
  { 
     result = a;//ουσιαστικα στο result περναει μονο το δεδομενο του α
     result->next = intsort(a->next, b);//γιατι ο καθε κομβος της τελικης λιστας συνδεεται με το αμεσως μεγαλυτερο νουμερο
  } 
  else 
  { 
     result = b; //εκμεταλλευομαστε την αυξουσα σειρα αποθηκευοντας παντα τον μικροτερο
     result->next = intsort(a, b->next); //και οταν μεταβιβαζουμε κομβο μιας λιστας τον προσπερναμε.πχ εδω ο α θα προσπεραστει μονο αν βρεθει β νουμερο μεγαλυτερο του γιατι εn τελει ολοι οι κομβου θα περαστουν στο result
  } 
  return(result);//επιστρεφεται καθε φορα ο μικροτερος κομβος για να γινει η συνδεση της λιστας και εν τελει στην main δινεται η κεφαλη/dummy
}

listnode intsertlast(listnode list,data item){//παραλλαγη απ'την ασκηση 1 για ακεραιους
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
//θα ελεγχε αν η λιστα ειναι ταξινομημενη αλλα τελικα δεν το θελατε.dead code
int sorted(listnode a){
	listnode prev=a;
	a=a->next;
	while(a!=NULL){
		if(prev->airport > a->airport)//αν βρεθει ενα στοιχειο μικροτερο του προηγουμενου του δεν εχουμε αυξουσα σειρά στη λιστα
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

