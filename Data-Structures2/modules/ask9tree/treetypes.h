#include "9item.h"
typedef struct pair_heap *Tree;
typedef struct list_childs *listnode;
struct pair_heap
{
	TreeItem data;
	listnode list;
};

struct list_childs
{
	Tree sub_tree;
	listnode next;
};
