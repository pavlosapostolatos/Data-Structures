#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ask4declare.h"
listnode intsort(listnode a,listnode b)  
{ 
  listnode result;
  if (a==NULL)  //αυτες οι εντολες κανονικα ελεγχουν αν δωθει εξαρχης μια αδεια λιστα αλλα επισης αντικαταστουν το κλασσικο while 
     return(b); 
  else if (b==NULL)//που ελεγχει αν προσπελασαμε την λιστα μεχρι το τελος της χαρη στην ανανδρομη
     return(a); 
  if (a->airport <= b->airport)  
  { 
     result = a;//ουσιαστικα στο result περναει μονο το δεδομενο 
     result->next = intsort(a->next, b);//γιατι ο καθε κομβος της τελικης λιστας συνδεεται με το αμεσως μεγαλυτερο νουμερο
  } 
  else 
  { 
     result = b; //εκμεταλλευομαστε την αυξουσα σειρα αποθηκευοντας παντα τον μικροτερο
     result->next = intsort(a, b->next); //και οταν μεταβιβαζουμε κομβο μιας λιστας τον προσπερναμε.πχ εδω ο α θα προσπεραστει μονο αν βρεθει β νουμερο μεγαλυτερο του γιατι εn τελει ολοι οι κομβου θα περαστουν στο result
  } 
  return(result);//επιστρεφεται καθε φορα ο μικροτερος κομβος για να γινει η συνδεση της λιστας και εν τελει στην main δινεται η κεφαλη/dummy
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
}//δεν χρησιμοποιηθηκε ποτε
listnode mergesort(listnode a){
	int n=0,i=0;
	listnode templist=a,firstlist,secondlist;
	if(sorted(a)==0){//αν ειναι ηδη ταξινομημενη η λιστα(ή ενα κομματι της(αναδρομη)) γινεται return οπως ειναι
		split_two_halves(&templist,&firstlist,&secondlist);
		firstlist=mergesort(firstlist);//ταξινομουνται τα 2 μισα
		secondlist=mergesort(secondlist);
		return intsort(firstlist,secondlist);//τα 2 μισα τωρα πια ταξινομημενα μπαινουν στην ασκηση 3
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

        *first=*head;//το πρωτο μισο αρχιζει απ'την κεφαλή
        listnode templist=*head;

        while(templist!=NULL && templist->next!=NULL && templist->next->next!=NULL){
            *first=(*first)->next;//ο αργος δεικτης που ανεφερε η εκφωνηση
            templist=templist->next->next;//και ο γρηγορος
        }//χαρη στην διπλασια ταχυτητα ο templist φτανει στο τελος οταν first ειναι στην μεση
        /*back halves*/
        *second=(*first)->next;//το δευτερο μισο αρχιζει εκει που τελιωνει το πρωτο
        (*first)->next=NULL;//και το πρωτο τελιωνει εκει που αρχιζει το δευτερο
        //το null σπαει την λιστα
        *first=*head;//το first εχει προχωρησει με τα next αρα το επαναφερουμε στην αρχη της πρωτης λιστας το head
    }
}

