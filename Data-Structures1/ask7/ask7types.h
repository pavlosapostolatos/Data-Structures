typedef struct list_type *listnode;
typedef char data[11];
struct list_type{
data airport;
listnode next;
};
typedef struct queue_type *queue;
struct queue_type{
 int priority;
 listnode Front;
 listnode Rear;
};

typedef struct queue_list *QL;
struct queue_list{
 queue QUEUE;
 QL link;
};