#include "item.h"

typedef struct cQueue* queue;

queue newQueue();

int emptyQueue(queue q);

int enqueue(item e, queue q);

item dequeue(queue q);

int cancFinoItem(queue q, item e);

queue fondiDaItem(queue q1, queue q2, item e);