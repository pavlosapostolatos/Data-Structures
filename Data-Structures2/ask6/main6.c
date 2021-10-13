#include <stdio.h>
#include <stdlib.h>
#include "module6_1.h"
int main()
{
    BSTtree a;
    int i;
    CompareType compare = &comp2;
    Visit vst = visit;
    a = BSTcreate(1000);
    for (i = 1; i <= 15; i += 2)
        //a=insert_at_head(a,i,i*5,compare);
        a = sorted_insert(a, i, i * 5, compare);
    for (i = 14; i >= 0; i -= 2)
        //a=insert_at_head(a,i,i*5,compare);
        a = sorted_insert(a, i, i * 5, compare);
    BSTnode r = BSTGetRoot(a);
    BSTInOrder(a, vst);
    printf("\n");
    a = sorted_insert(a, 16, 80, compare);
    BSTInOrder(a, vst);
    printf("\n");
    a = deleteNode(a, 80);
    BSTInOrder(a, vst);
    printf("\n");
    printf("max and min key ");
    printf(TYPE, BSTGetKey(a, BSTGetMaxKey(a, r)));
    printf(TYPE, BSTGetKey(a, BSTGetMinKey(a, r)));
    printf("\n");
    Destroy(a);
}
