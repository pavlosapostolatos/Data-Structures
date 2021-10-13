#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ask4declare.h"
int main(){
		int i;
listnode ask4=NULL;
char itemtype[4];
strcpy(itemtype,"%d ");
for(i=1;i<=17;i+=4) ask4=intsertlast(ask4,i);
for(i=17;i>=0;i-=3) ask4=intsertlast(ask4,i);
print(ask4,itemtype);
ask4=mergesort(ask4);
print(ask4,itemtype);
}
