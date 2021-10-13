#include <stdio.h>
#include <stdlib.h>
#include "module2.h"

int main()
{
    BTtree a;
    BTnode b, c, d;
    Visit vst = visit;
    a = BTcreate(8);
    a = insertroot(a, 1);
    d = BTGetRoot(a);
    BTInsertLeft(a, d, 2);
    BTInsertRight(a, d, 3);
    b = BTGetChildLeft(a, d);
    printf("data of left child of root is ");
    printf(TYPE, BTGetItem(a, b));
    printf("\n");
    c = BTGetChildRight(a, d);
    printf("data of right child of root is ");
    printf(TYPE, BTGetItem(a, c));
    printf("\n");
    BTInsertLeft(a, b, 4);
    BTInsertRight(a, b, 5);
    b = BTGetChildRight(a, b);
    printf("root of 5 is ");
    printf(TYPE, BTGetItem(a, d));
    printf("\n");
    c = BTGetParent(a, b);
    printf("parent of 5 ");
    printf(TYPE, BTGetItem(a, c));
    printf("\n");
    printf("height is %d\n", BTHeight(a));
    printf("size is %d\n", BTSize(a));
    printf("preorder\n");
    BTPreOrder(a, visit);
    printf("\n");
    printf("inorder\n");
    BTInOrder(a, vst);
    printf("\n");
    printf("postorder\n");
    BTPostOrder(a, vst);
    printf("\n");
    printf("levelorder\n");
    BTLevelOrder(a, vst);
    printf("\n");
    printf("changing data of root\n");
    BTChange(a, d, 10);
    printf(TYPE, BTGetItem(a, d));
    printf("\n");
    Remove(a, b);
    BTInOrder(a, vst);
    printf("\n");
    Destroy(a);
}
