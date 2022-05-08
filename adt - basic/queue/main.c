#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include "queue.h"

queue inputQueue(int n){
    queue q = newQueue();
    for(int i = 0; i < n; i++){
        printf("fornisci valore: ");
        int x = 0;
        scanf("%d", &x);
        item i = createItem(x);
        enqueue(i, q);
    }
    return q;
} 

queue cloneQueue(queue q){
    queue cloned = newQueue();
    if (emptyQueue(q))
        return cloned;
    
    queue temp = newQueue();
    while(!emptyQueue(q)){
        item curr = dequeue(q);
        enqueue(curr, cloned);
        enqueue(curr, temp); 
    }
    while (!emptyQueue(temp)){
        enqueue(dequeue(temp), q);
    }
    free(temp);
    return cloned;
    
}

void printQueueClient(queue q){
    queue printable = cloneQueue(q);
    printf("head--");
    while(!emptyQueue(printable)){
        printItem(dequeue(printable));
        printf("--");
    }
    printf("tail\n");
    free(printable);
}

queue reverseQueue(queue q){
    queue reverse = newQueue();
    if(emptyQueue(q))
        return reverse;
    int size = getSize(q);
    
    while(!emptyQueue(q)){
        for(int i = 0; i < size-1; i++){
            enqueue(dequeue(q), q);
        }
        enqueue(dequeue(q), reverse);
        size--;
    }
    return reverse;
}

void mergeQueueClient(queue q1, queue q2){
    while(!emptyQueue(q2)){
        enqueue(dequeue(q2), q1);
    }
    //return s1;
}

int main(){
    queue q1 = newQueue();
    q1 = inputQueue(4);
    //printQueue(q);



    // queue rev = reverseQueue(q1);
    // printQueueClient(rev);
    queue q2 = newQueue();
    enqueue(createItem(1), q2);
    enqueue(createItem(2), q2);
    enqueue(createItem(3), q2);
    enqueue(createItem(4), q2);
    
    printQueueClient(q1);
    printQueueClient(q2);

    mergeQueueClient(q1, q2);
    printQueueClient(q1);
    
}