#include "user.h"
typedef int (*CompareType)(BSTKeyType a, BSTKeyType b);
typedef struct bin_node *BTnode;
typedef struct bin_node
{
    BTitem data;
    BTnode left;
    BTnode right;
    BTnode paren;
    int priority;
    CompareType compare;
    BSTKeyType key;
} binary_tree;
typedef BTnode BTtree;
typedef void (*Visit)(BTnode);
