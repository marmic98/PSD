#include <stdio.h>
#include "item.h"
#include "queue.h"

int main(){
    queue q1 = newQueue();
    for(int i = 0; i < 4; i++){
        printf("fornire elemento %d\n", i+1);
        int x = 0;
        scanf("%d", &x);
        item temp = createItem(x);
        enqueue(temp, q1);
    }

    queue q2 = newQueue();
    for(int i = 0; i < 3; i++){
        printf("fornire elemento %d\n", i+1);
        int x = 0;
        scanf("%d", &x);
        item temp = createItem(x);
        enqueue(temp, q2);
    }

    queue q3 = xorQ(q1, q2);
    
    while(!emptyQueue(q3)){
        printItem(dequeue(q3));
    }
    printf("nil\n");
}