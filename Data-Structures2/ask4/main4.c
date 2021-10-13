 #include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "module4_1.h"

int main(){
CBTtree a;
CBTnode b,c,d;
Visit vst=visit;
a=CBTcreate(8);
a=CBTInsertLast(a,1);
d=CBTGetRoot(a);
CBTInsertLast(a,2);
CBTInsertLast(a,3);
b=CBTGetChildLeft(a,d);
printf("data of left child of root is ");
printf(TYPE,CBTGetItem(a,b));
printf("\n");
c=CBTGetChildRight(a,d);
printf("data of right child of root is ");
printf(TYPE,CBTGetItem(a,c));
printf("\n");
CBTInsertLast(a,4);
//CBTLevelOrder(a,vst);
CBTInsertLast(a,5);
//CBTLevelOrder(a,vst);
//printf("done\n");
b=CBTGetChildRight(a,b);
printf("root of 5 is ");
printf(TYPE,CBTGetItem(a,d));
printf("\n");
//printf("%d\n",b==NULL);
c=CBTGetParent(a,b);
printf("parent of 5 ");
printf(TYPE,CBTGetItem(a,c));
printf("\n");
printf("height is %d\n", CBTHeight(a));
printf("size is %d\n", CBTSize(a));
printf("preorder\n");
CBTPreOrder(a,visit);
printf("\n");
printf("inorder\n");
CBTInOrder(a,vst);
printf("\n");
printf("postorder\n");
CBTPostOrder(a,vst);
printf("\n");
printf("levelorder\n");
CBTLevelOrder(a,vst);
printf("\n");
printf("changing data of root\n");
CBTChange(a ,d ,10);
printf(TYPE,CBTGetItem(a,d));
printf("\n");
CBTRemoveLast(a);
CBTInOrder(a,vst);
printf("\n");
Destroy(a);
}

