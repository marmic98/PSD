#include "item.h"

typedef struct cQueue* queue;

queue newStack();

int emptyQueue(queue q);

int enqueue(item e, queue q);

item dequeue(queue q);

int getSize(queue q);

void printQueue(queue q);