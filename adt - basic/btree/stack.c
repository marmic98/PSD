#include <stdio.h>
#include <stdlib.h>
#include "item.h"
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


stack reverseStack(stack s){
	if (emptyStack(s))
		return NULL;
	
	stack temp = newStack();
	stack reverse = newStack();
	
	while(!emptyStack(s)){
		push(top(s), temp);
		push(top(s), reverse);
		pop(s);
	}
	while(!emptyStack(temp)){
		push(top(temp), s);
		pop(temp);
	}
	free(temp);
	return reverse;
}

stack cloneStack(stack s){
	stack cloned = newStack();
	cloned = reverseStack(s);
	cloned = reverseStack(cloned);
	return cloned;
}

stack inputStack(unsigned int n){
	stack s = newStack();
	
	for(int i = 0; i < n; i++){
		printf("Fornire valore: ");
		int x = 0;
		scanf("%d", &x);
		push(createItem(x), s);
	}
	return s;
}

void printStack(stack s){
	stack cloned = newStack();
	cloned = cloneStack(s);
	printf("top->");
	while(!emptyStack(cloned)){
		printItem(top(cloned));
		pop(cloned);
		printf("--");
	}
	printf("\n");
}

stack merge(stack s1, stack s2){
    stack merged = newStack();
	if(emptyStack(s1) && !emptyStack(s2))
		return s2;
	else if(!emptyStack(s1) && emptyStack(s2))
		return s1;
	else if(emptyStack(s1) && !emptyStack(s2))
		return merged;
    merged = cloneStack(s2);
    stack s1Cpy = reverseStack(s1);
    while(!emptyStack(s1Cpy)){
        push(top(s1Cpy), merged);
        pop(s1Cpy);
    }
    return merged;
}

void deleteItem(stack s, item toDelete){
	stack temp = newStack();
	while (!emptyStack(s)){
		if(cmp(top(s), toDelete) != 0)
			push(top(s), temp);
		pop(s);
	}
	
	while(!emptyStack(temp)){
		push(top(temp), s);
		pop(temp);
	}
}