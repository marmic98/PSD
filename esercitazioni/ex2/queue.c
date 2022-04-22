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

item getHead(queue q){
    return q->head->value;
}

int cancFinoItem(queue q, item e){
    int counter = 0;
    if (emptyQueue(q))
        return counter; 
    while(!emptyQueue(q) && cmp(e, getHead(q)) != 0){
        counter++;
        dequeue(q);
    }
    return counter;
}

queue fondiDaItem(queue q1, queue q2, item e){
    queue newQ = newQueue();
    if (emptyQueue(q1) && emptyQueue(q2))
        return newQ; //coda vuota
    
    while(!emptyQueue(q1) && cmp(e, getHead(q1)) != 0){ //raggiungo el in q1
        dequeue(q1);
    }
    
    while(!emptyQueue(q2) && cmp(e, getHead(q2)) != 0){ //raggiungo el in q2
        dequeue(q2);
    }

    queue temp = newQueue();
    while(!emptyQueue(q1)){
        while(!emptyQueue(q2)){
            item toSave;
            if (cmp(getHead(q1), getHead(q2)) == 0){
                toSave = getHead(q2);
                enqueue(toSave, newQ);
            }
            enqueue(dequeue(q2), temp);
        }
        while(!emptyQueue(temp))
            enqueue(dequeue(temp), q2);

        dequeue(q1);   
    }
    return newQ;
}