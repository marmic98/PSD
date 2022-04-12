#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "itemStr.h"
#include "stack.h"

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

void printStack(stack s){
    stack temp = cloneStack(s);
    while(!emptyStack(temp)){
        printItem(top(temp));
        pop(temp);
    }
    printf("\n");
}

int balance(char* expr){
    stack brackets = newStack();
    for(int i = 0; expr[i] != '\0'; i++){
        if (expr[i] == '(' || expr[i] == '[' || expr[i] == '{'){ 
            push(chToItem(expr[i]), brackets);
        }
        if (expr[i] == ')' || expr[i] == ']' || expr[i] == '}'){
            item topBracket = top(brackets);
            pop(brackets);
            if (!eqBrackets(itemToCh(topBracket), expr[i]))
                return 0;
        }
        printStack(brackets);
    }
    return 1;
}

int main(){
    char* expr = "{[])]}";
    printf("esito verifica bilanciamento: %d\n", balance(expr));
}