#ifdef BT_IMPL_LINKED
#include "module1.h"
#else
#include "module2.h"
#endif
#include "module4_1types.h"
CBTtree CBTcreate(int);
int CBTHeight(CBTtree);
void CBTPreOrder(CBTtree, Visit);
void CBTInOrder(CBTtree, Visit);
void CBTPostOrder(CBTtree, Visit);
void CBTLevelOrder(CBTtree, Visit);
int CBTSize(CBTtree tree);
CBTnode CBTGetRoot(CBTtree);
CBTnode CBTGetParent(CBTtree, CBTnode);
CBTnode CBTGetChildLeft(CBTtree, CBTnode);
CBTnode CBTGetChildRight(CBTtree, CBTnode);
CBTitem CBTGetItem(CBTtree, CBTnode);
CBTnode search(CBTtree, CBTnode);
void Destroy(CBTtree);
CBTtree insertroot(CBTtree, CBTitem);
void CBTChange(CBTtree, CBTnode, CBTitem);
void printLevel(CBTtree, int, Visit);
CBTnode CBTGetLast(CBTtree);
void GETLevel(CBTtree, int, CBTnode *);
CBTtree CBTInsertLast(CBTtree, CBTitem);
void insertatlevel(CBTtree, int, CBTitem, int *);
void CBTRemoveLast(CBTtree);
int CBTIsEmpty(CBTtree, CBTnode);
