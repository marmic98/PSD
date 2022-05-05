#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "item.h"

stack inputStackClient(int n){
	stack s = newStack();

	for(int i = 0; i < n; i++){
		printf("fornire valore: ");
		int x = 0;
		scanf("%d", &x);
		push(createItem(x), s);
	}
	return s;
}

stack reverseStackClient (stack s){
	stack temp = newStack();
	stack reversed = newStack();
	
	if (emptyStack(s)) 
		return reversed;

	while(!emptyStack(s)){
		push(top(s), temp);
		push(top(temp), reversed);
		pop(s);
	}
	while(!emptyStack(temp)){
		push(top(temp), s);
		pop(temp);
	}
	return reversed;
}

stack cloneStackClient (stack s){
	stack temp = newStack();
	stack cloned = newStack();
	
	if (emptyStack(s)) 
		return cloned;

	while(!emptyStack(s)){
		push(top(s), temp);
		pop(s);
	}
	while(!emptyStack(temp)){
		push(top(temp), s);
		push(top(temp), cloned);
		pop(temp);
	}
	return cloned;
}

void printStackClient(stack s){
	stack toPrint = cloneStackClient(s);
	printf("top-->");
	while (!emptyStack(toPrint)){
		printItem(top(toPrint));
		pop(toPrint);
		printf("-->");
	}
	printf("fondo\n");
	free(toPrint);
}

int deleteItemClient(stack s, item toDelete){
	stack temp = newStack();
	int counter = 0;
	while(!emptyStack(s)){
		if(cmp(toDelete, top(s)) == 0)
			counter++;
		else
			push(top(s), temp);
		pop(s);
	}

	while(!emptyStack(temp)){
		push(top(temp), s);
		pop(temp);
	}
	return counter;
}



int main (){
	stack s1 = newStack();
	//stack s2 = newStack();
	//printf("Primo stack\n");
	s1 = inputStackClient(4);
	// printf("Secondo stack\n");
	// s2 = inputStackClient(4);
	// printStackClient(cloneStackClient(s1));
	// printStackClient(reverseStackClient(s1));
	// printStackClient(s1);
	printStackClient(s1);
	int c = deleteItemClient(s1, createItem(3));
	printf("3 eliminato %d volt%s\n", c, c == 1 ? "a": "e");
	printStackClient(s1);
	//stack s3 = merge(s1, s2);
	//printStack(s3);
	
	//deleteItem(s1, createItem(3));
	//printStack(s1);
}