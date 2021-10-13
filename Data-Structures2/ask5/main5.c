 #include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "module5_2.h"

int main(){
    Visit vst=visit;
    BHtree a;
    a=BHcreate(20);
    int n=15,i,k;
    int* priorities;
    BHitem* items,temp;
    priorities=(int*)malloc(n*sizeof(int));
    items=(BHitem*)malloc(n*sizeof(BHitem));
    for(i=0;i<n;i++){
        priorities[i]=(i+1)*5;
        items[i]=i;
    }
    a=BHHeapify(n,priorities,items);
    BHLevelOrder(a,vst);
    printf("\n");
    BHInsert(a,100, 20);
    BHLevelOrder(a,vst);
    printf("\n");
    BHRemove(a);
    BHLevelOrder(a,vst);
    printf("\n");
    k=BHGetMaxPriority(a);
    printf("max priority of tree is %d\n",k);
    temp=BHGetMaxItem(a);
    printf("max priority item is");
    printf(TYPE,temp);
    printf("\n");
    BHDestroy(a);
}
