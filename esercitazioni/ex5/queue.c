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

queue cancDaItem(queue q, item el){
    if (emptyQueue(q))
        return NULL;
    
    struct node* app = q->head;
    queue q1 = newQueue();

    while(app != NULL && cmp(el, app->value) != 0){
        enqueue(app->value, q1);
        app = app->next;
    }
    if (app)
        enqueue(app->value, q1);
    
    free(app);
    return q1;
}

struct node* deleteDuplicates(struct node* q3){
    struct node* temp1 = q3;
    struct node* temp2 = NULL;
    struct node* doppione;
    while(temp1 != NULL && temp1->next != NULL){
        temp2 = temp1;
        while(temp2->next!= NULL){
            if (cmp(temp1->value, temp2->next->value) == 0){
                doppione = temp2->next;
                temp2->next = temp2->next->next;   
                free(doppione);
            }
            else{
                temp2 = temp2->next;
            }
        }   
        temp1 = temp1->next;    
    }
    return q3;
}

queue fondiQueue(queue q1, queue q2){
    if (!q1 || !q2)
        return NULL;

    struct node* temp1 = q1->head;
    struct node* temp2 = q2->head;

    queue q3 = newQueue();

    while(temp1){
        while(temp2){
            if (cmp(temp1->value, temp2->value) == 0){
                enqueue(temp1->value, q3);
                break;
            }
            else
                temp2 = temp2->next;
        }
        temp2 = q2->head;
        temp1 = temp1->next;
    }
    
    q3->head = deleteDuplicates(q3->head);
    
    return q3;
}

void printQueue(queue q){
    struct node* temp = q->head;
    while(temp != NULL){
        printItem(temp->value);
        temp = temp->next;
    }
    printf("nil\n");
}