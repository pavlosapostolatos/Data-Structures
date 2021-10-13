#include "module1types.h"
BTtree BTcreate(int);
int BTHeight(BTtree);
void BTPreOrder(BTtree, Visit);
void BTInOrder(BTtree, Visit);
void BTPostOrder(BTtree, Visit);
void BTLevelOrder(BTtree, Visit);
void visit(BTtree);
int BTIsEmpty(BTtree, BTnode);
int BTSize(BTtree tree);
BTnode BTGetRoot(BTtree);
BTnode BTGetParent(BTtree, BTnode);
BTnode BTGetChildLeft(BTtree, BTnode);
BTnode BTGetChildRight(BTtree, BTnode);
BTitem BTGetItem(BTtree, BTnode);
BTnode search(BTtree, BTnode);
void Destroy(BTtree);
void Remove(BTtree, BTnode);
BTnode insertroot(BTtree, BTitem);
void BTInsertLeft(BTtree, BTnode, BTitem);
void BTInsertRight(BTtree, BTnode, BTitem);
void BTChange(BTtree, BTnode, BTitem);
void printLevel(BTtree, int, Visit);
BTtree NEW(BTitem, BTtree, BTtree, BSTKeyType, CompareType);
void Changeparen(BTtree *, BTtree);
void Changeright(BTtree *, BTtree);
void Changeleft(BTtree *, BTtree);
void kill(BTtree, BTnode);
void BTChangeKey(BTnode, BTnode, BSTKeyType);
BSTKeyType BSTGetKey(BTtree, BTnode);
