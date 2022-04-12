#include <stdio.h>
#include <stdlib.h>
#include "itemStr.h"
#include "stack.h"

#define NULLITEM 0

struct node{
    item value;
    struct node* next
};

struct cStack{
    struct node* top;
    int size;
};

stack newStack(){
    stack s = malloc(sizeof(struct cStack));
    if (!s)
        return NULL;
    else{
        s->top = NULL;
        s->size = 0;
        return s;
    }
}

int emptyStack(stack s){
    return s->size == 0;
}

int push(item e, stack s){
    struct node* newTop = malloc(sizeof(struct node));
    if (!newTop)
        return 0;
    else{
        newTop->value = e;
        newTop->next = s->top;
        s->top = newTop;
        s->size++;
        return 1;
    }
}

int pop(stack s){
    if (s->size == 0)
        return 0;
    else{
        struct node* temp = s->top;
        s->top = s->top->next;
        free(temp->value);
        free(temp);
        s->size--;
    }
}

item top(stack s){
    if (s->size == 0)
        return NULLITEM;
    else 
        return s->top->value;
}

int sizeStack(stack s){
    return s->size;
}