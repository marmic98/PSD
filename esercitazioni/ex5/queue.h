#include "item.h"

typedef struct cQueue* queue;

queue newQueue();

int emptyQueue(queue q);

int enqueue(item e, queue q);

item dequeue(queue q);

queue cancDaItem(queue q, item el);

queue fondiQueue(queue q1, queue q2);

void printQueue(queue q);