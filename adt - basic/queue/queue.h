#include "item.h"

typedef struct cQueue* queue;

queue newQueue();

int emptyQueue(queue q);

int enqueue(item e, queue q);

item dequeue(queue q);

int getSize(queue q);

queue pariDispari(queue q);

void printQueue(queue q);
