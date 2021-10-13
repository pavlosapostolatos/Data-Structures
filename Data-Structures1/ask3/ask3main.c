#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ask3declare.h"
int main(){
	int i;
	printf("ask3\n");
listnode a,b,c,del,add,int1=NULL,int2=NULL,ask4=NULL;
for(i=1;i<=17;i+=4) int1=intsertlast(int1,i);
for(i=0;i<=10;i+=2) int2=intsertlast(int2,i);
data item;
char itemtype[4];
strcpy(itemtype,"%d ");
printf("list1\n");
print(int1,itemtype);
printf("list2\n");
print(int2,itemtype);
c=intsort(int1,int2);
printf("result\n");
print(c,itemtype);
}
