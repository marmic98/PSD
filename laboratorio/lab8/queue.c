#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include "queue.h"

#define NULLITEM 0

struct node{
    struct node* next;
    item value;
};
typedef struct node* nodo;

struct cQueue{
    nodo head, tail;
    int size;
};

queue newQueue(){
    queue q  = malloc(sizeof(struct cQueue));
    if (!q) return NULL;

    q->size = 0;
    q->head = NULL;
    q->tail = NULL;
    return q;
}

int emptyQueue(queue q){
    if(q == NULL) return -1;
    return  q->size == 0;
}

int enqueue (item e, queue q){
    if (q == NULL)
        return -1;
    nodo new = malloc(sizeof(struct node));
    if(!new) return 0;
    
    new->value = e;

    if (q->head == NULL){
        q->head = new;
    }
    else {
        q->tail->next = new;
    }
    q->tail = new;
    q->size++;
    return 1;
}

item dequeue(queue q){
    if (q == NULL)
        return NULLITEM;

    item result = q->head->value;

    nodo temp = q->head;
    q->head = q->head->next;
    free(temp);

    if (q->head ==NULL) //vuol dire che abbiamno tolto l'unico elemento presente nella coda e ora sarà vuota
       q->tail = NULL; 

    q->size--;
    return result;
}