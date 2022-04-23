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
    new->next = NULL;

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

int isPresentQ(queue q, item e){
    if(emptyQueue(q))
        return NULL;
    while(!emptyQueue(q) && cmp(e, getHead(q)) != 0)
        dequeue(q);
    return !emptyQueue(q);
}

queue xorQ(queue q1, queue q2){
    queue newQ = newQueue();
    if (emptyQueue(q1) && !emptyQueue(q2))
        return q2; //coda vuota
    
    if (!emptyQueue(q1) && emptyQueue(q2))
        return q1; //coda vuota
    
    nodo temp1 = q1->head;
    nodo temp2 = q2->head;
    int flag = 0;
    while(temp1){
        while(temp2 && flag == 0){
            if (cmp(temp1->value, temp2->value) == 0)
                flag = 1;
        temp2 = temp2->next;
        
        }
        if (flag == 0){
            enqueue(temp1->value, newQ);
        }
        

        flag = 0;
        temp1 = temp1->next;
        temp2 = q2->head;
        
    }

    temp1 = q1->head;
    temp2 = q2->head;

    while(temp2){
        while(temp1 && flag == 0){
            if (cmp(temp1->value, temp2->value) == 0)
                flag = 1;
        temp1 = temp1->next;
        }
        if (flag == 0){
            enqueue(temp2->value, newQ);
        }
        flag = 0;
        temp2 = temp2->next;
        temp1 = q1->head;
    }
    return newQ;
}