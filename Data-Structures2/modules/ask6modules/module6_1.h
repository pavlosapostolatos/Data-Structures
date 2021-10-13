#ifdef BT_IMPL_LINKED
#include "module1.h"
#else
#include "module2.h"
#endif
#include "module6_1types.h"
BSTtree BSTcreate(int maxelem);
int BSTIsEmpty(BSTtree tree, BSTnode node);
void BSTInOrder(BSTtree tree, Visit visit);
void BSTChange(BSTtree tree, BSTnode node, BSTitem item);
BSTnode Search(BSTtree tree, BSTnode node, BSTKeyType key, CompareType compare);
BSTnode BSTGetChildLeft(BSTtree tree, BSTnode node);
BSTnode BSTGetChildRight(BSTtree tree, BSTnode node);
void Destroy(BSTtree tree);
BSTnode BSTGetMaxKey(BSTtree tree, BSTnode node);
BSTnode BSTGetMinKey(BSTtree tree, BSTnode node);
BSTitem BSTGetItem(BSTtree tree, BSTnode node);
BSTtree sorted_insert(BSTtree tree, BSTitem item, BSTKeyType key, CompareType compare);
BSTnode insert_at_head(BSTnode tree, BSTitem item, BSTKeyType key, CompareType compare);
BSTnode RotateRight(BSTnode h);
BSTtree deleteNode(BSTtree tree, BSTKeyType key);
BSTnode RotateLeft(BSTnode h);
BSTnode BSTGetRoot(BSTtree tree);
BSTtree del(BSTtree, BSTnode, BSTitem);
BSTtree SI(BSTtree, BSTnode, BSTitem, BSTKeyType);
