#include <stdio.h>
#include "item.h"
#include "queue.h"

int main(){
    // queue q = newQueue();
    // int x = 0;
    // for(int i = 0; i < 4; i++){
    //     printf("fornire elemento %d\n", i+1);
    //     scanf("%d", &x);
    //     item temp = createItem(x);
    //     enqueue(temp, q);

    // }
    item test = createItem(3);
    // int c = cancFinoItem(q, test);

    // while(!emptyQueue(q)){
    //     printItem(dequeue(q));
    // }
    // printf("nil\n");

    queue q1 = newQueue();
    for(int i = 0; i < 4; i++){
        printf("fornire elemento %d\n", i+1);
        int x = 0;
        scanf("%d", &x);
        item temp = createItem(x);
        enqueue(temp, q1);
    }

    queue q2 = newQueue();
    for(int i = 0; i < 6; i++){
        printf("fornire elemento %d\n", i+1);
        int x = 0;
        scanf("%d", &x);
        item temp = createItem(x);
        enqueue(temp, q2);
    }

    queue newQ = fondiDaItem(q1, q2, test);
    
    while(!emptyQueue(newQ)){
        printItem(dequeue(newQ));
    }
    printf("nil\n");

}