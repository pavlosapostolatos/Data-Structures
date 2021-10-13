
typedef enum
{
    FALSE,
    TRUE
} Boolean;
typedef char *KeyType;
typedef struct TableEntry *list;
typedef list Content;
typedef struct neig
{
    list cell;
    struct neig *link;
} n;

#include "user.h"
typedef Nbr Stack;

typedef struct TableEntry
{
    KeyType key;
    ItemType item;
    Boolean visited;
    list next;
    short int deleted;
} Entry;

typedef struct array *Hash;
typedef struct array
{
    int size;
    //int n;//only for graph
    list *table;
} hash;

typedef void (*Visit)(Entry *);
