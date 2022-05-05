#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "item.h"

int main (){
	stack s1 = newStack();
	stack s2 = newStack();
	printf("Primo stack\n");
	s1 = inputStack(4);
	printf("Secondo stack\n");
	s2 = inputStack(4);
		
	stack s3 = merge(s1, s2);
	printStack(s3);
	
	deleteItem(s1, createItem(3));
	printStack(s1);
}