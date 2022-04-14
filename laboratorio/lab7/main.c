#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "item.h"

stack reverseStack(stack s){
    stack cloned = newStack();
    stack temp = newStack();
    while(!emptyStack(s)){
        push(top(s), cloned);
        push(top(s), temp);
        pop(s);
    }
    while(!emptyStack(temp)){
        push(top(temp), s);
        pop(temp);
    }
    return(cloned);
}

stack cloneStack(stack s){
    stack cloned = newStack();
    cloned = reverseStack(s);
    cloned = reverseStack(cloned);
    return cloned;

}

stack merge(stack s1, stack s2){
    stack merged = newStack();
    
    merged = cloneStack(s2);
    stack s1Cpy = reverseStack(s1);
    while(!emptyStack(s1Cpy)){
        push(top(s1Cpy), merged);
        pop(s1Cpy);
    }
    return merged;
}

stack inputStack(stack s){
    item value;
    int i = 0;
    while(1){
        printf("Fornisci item %d\n",i);
        value = inputItem();
        if (value == -1)
            break;
        push(value, s);
        i++;
    }
    return s;
}

void printStack(stack s){
    stack temp = cloneStack(s);
    while(!emptyStack(temp)){
        printItem(top(temp));
        pop(temp);
    }
    printf("\n");
}

int deleteItem (stack s, item e){
    stack temp = newStack();
    int counter = 0;
    while(!emptyStack(s)){
        if (equal(e, top(s))){
            counter++;
        }
        else {
            push(top(s), temp);    
        }
        pop(s);
    }

    while(!emptyStack(temp)){
        push(top(temp), s);
        pop(temp);
    }
    return counter;
}

int main(){
    stack s1 = newStack();
    inputStack(s1);
    stack s2 = newStack();
    inputStack(s2);

    stack s3 = merge(s1, s2);

    printStack(s3);
    int x = deleteItem(s3, 3);
    printStack(s3);
    printf("3 deleted %d times\n", x);

}