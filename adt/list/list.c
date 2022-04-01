#include <stdio.h>
#include <stdlib.h>
#include "list.h"

struct cList{
    struct node *first;
    int size;
};

struct node{
    item value;
    struct node* next;
};

list newList(void){
    list l = malloc(sizeof(struct cList));
    if(l != NULL){
        l->first = NULL;
        l->size = 0;
    }
    return l;
}

int insertList(list l, item e, int pos){
    if (pos > l->size) return l;
    struct node *new = malloc(sizeof(struct node));
    new->value = e;
    if (l->size == 0){
        l->first = new;
        l->size++;
        return l;
    }

    struct node* prec = l->first;
    int i = 0;
    while(i < pos-1)



}
