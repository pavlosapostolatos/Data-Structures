#include "module4_1.h"
#include "module5types.h"
BHtree BHcreate(int);
int BHeight(BHtree);
void BHPreOrder(BHtree, Visit);
void BHInOrder(BHtree, Visit);
void BHPostOrder(BHtree, Visit);
void BHLevelOrder(BHtree, Visit);
int BHSize(BHtree);
BHnode BHGetRoot(BHtree);
BHnode BHGetParent(BHtree, BHnode);
BHnode BHGetChildLeft(BHtree, BHnode);
BHnode BHGetChildRight(BHtree, BHnode);
BHnode BHGetItem(BHtree, BHnode);
BHnode search(BHtree, BHnode);
void BHDestroy(BHtree);
BHtree insertroot(BHtree, BHitem);
void BHChange(BHtree, BHnode, BHitem);
void printLevel(BHtree, int, Visit);
BHnode BHGetLast(BHtree);
void GETLevel(BHtree, int, BHnode *);
BHtree BHInsertLast(BHtree, BHitem);
void insertatlevel(BHtree, int, BHitem, int *);
void BHRemoveLast(BHtree);
int BHGetMaxPriority(BHtree);
BHitem BHGetMaxItem(BHtree);
BHtree BHHeapify(int, int *, BHitem *);
void BHInsert(BHtree, int, BHitem);
void BHRemove(BHtree);
void testheap(BHtree);
int BHIsEmpty(CBTtree, CBTnode);
int BHIsLeaf(BHtree, BHnode);
#ifdef BT_IMPL_LINKED
void heapify_down(BHtree);
void heapify_up(BHtree);
void postorderheap(BHtree);
#else
void heapify_down(BHtree, BHnode);
void heapify_up(BHtree, BHnode);
void postorderheap(BHtree, BHnode);
#endif
