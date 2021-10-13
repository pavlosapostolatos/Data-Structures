typedef struct list_type *listnode;
typedef char data[4];
typedef int (*CompareType)(data a,data b);
struct list_type{
data airport;
listnode next;
listnode previous;
};

