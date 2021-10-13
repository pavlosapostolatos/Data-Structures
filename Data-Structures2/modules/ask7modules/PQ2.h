#include "module6_1.h"
#include "PQ2_types.h"
PQ PQCreate(int);
int PQIsEmpty(PQ, PQnode);
void PQDestroy(PQ);
PRvalue PQGetMaxPriority(PQ);
PQItem PQGetMaxItem(PQ);
void PQInsert(PQ *, PQItem, PRvalue, CompareType);
void Delete(PQ tree);
void LevelOrder(PQ, Visit);