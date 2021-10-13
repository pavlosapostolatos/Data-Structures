#include "module5_2.h"
#include "PQ1_types.h"
PQ PQCreate(int);
int PQIsEmpty(PQ, PQnode);
void PQDestroy(PQ);
int PQGetMaxPriority(PQ);
PQItem PQGetMaxItem(PQ);
void PQInsert(PQ *, PQItem, PRvalue, CompareType);
void Delete(PQ tree);
void LevelOrder(PQ, Visit);
