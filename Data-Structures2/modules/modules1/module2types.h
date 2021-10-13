#include "user.h"
typedef int (*CompareType)(BSTKeyType a, BSTKeyType b);
typedef int BTnode;
typedef struct bin_node *BTtree;
typedef struct bin_node
{
   int size;
   BTitem *items;
   int *priority;
   CompareType compare;
   BSTKeyType *key;
} binary_tree;
typedef void (*Visit)(BTtree, BTnode);
#define LEFT(A) (2 * (A))
#define RIGHT(A) (2 * (A) + 1)
#define PAREN(A) ((A) / 2)
