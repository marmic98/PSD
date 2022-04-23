#include <stdio.h>
#include "queue.h"

// queue cloneQueue(queue q){
//     if(!q)
//         return NULL;
//     queue cloned = newQueue();
//     queue tempQ = newQueue();
//     while(!emptyQueue(q)){
//         item current = dequeue(q);
//         enqueue(current, tempQ);
//         enqueue(current, cloned);
//     }
//     while (!emptyQueue(tempQ)){
//         enqueue(dequeue(tempQ), q);
//     }
//     free(tempQ);
//     return cloned;
// }

queue createQueue(){
    queue q = newQueue();
    item p;
    char c = ' ';
    do{
        printf("Fornisci punto\n");
        float x;
        printf("ascissa: ");
        scanf("%f",&x);
        float y;
        printf("ordinata: ");
        scanf("%f",&y);
        fflush(stdin);
        p = creaPunto(x, y);
        enqueue(p, q);
        printf("Digita c per terminare l'inserimento di punti\n");
        c = getchar();
    }while(c != 'c');
    return q;
}

//sottoCode: la funzione sottocode, presa in inout una coda, genera quattro sottocode contenenti ciascuna i punti dei 4 quadranti
//precondizione: q = <a1, a2, ..., an> con n >= 0 e q1, q2, q3, q4 vuote. Esse servono a contenere i punti per i quattro quadranti
//postcondizione: q = nil. q1 contiene i punti del primo quadrante (++), q2 del secondo (-+), q3 del terzo (--) e q4 del quarto (+-)
//                  lo zero è inteso come appartenente al primo quadrante
void sottoCode(queue q, queue q1, queue q2, queue q3, queue q4){
    if (emptyQueue(q))
        printf("Coda vuota\n");
    while(!emptyQueue(q)){
        item curr = dequeue(q);
        if (ascissa(curr) >= 0 && ordinata(curr) >= 0)
            enqueue(curr, q1);
        
        if (ascissa(curr) < 0 && ordinata(curr) >= 0)
            enqueue(curr, q2);

        if (ascissa(curr) < 0 && ordinata(curr) < 0)
            enqueue(curr, q3);
        
        if (ascissa(curr) >= 0 && ordinata(curr) < 0)
            enqueue(curr, q4);
    }
}

//pre: /
//post: verrà prodotta una funzione qualora la cosa q presenta almeno 2 punti di cui è possibile calcolare la distanza. q non viene alterata
float spezzata(queue q){
    float lunghezza = 0;

    if (getSize(q) < 2)
        return lunghezza;

    queue copyQ = newQueue();
    item curr = dequeue(q);
    item next = dequeue(q);
    lunghezza = distanza(curr, next);
    
    enqueue(curr, copyQ);
    enqueue(next, copyQ);

    while (!emptyQueue(q)){
        curr = next;
        next = dequeue(q);
        lunghezza += distanza(curr, next);
        enqueue(next, copyQ);
    }
    
    while(!emptyQueue(copyQ)){
        enqueue(dequeue(copyQ), q);
    }
    return lunghezza;
}

//pre: /
//post: cat = head-->q1,q2-->tail
queue concatena (queue q1, queue q2){
    queue cat = newQueue();
    while (!emptyQueue(q1)){
        enqueue(dequeue(q1), cat);
    }
    while (!emptyQueue(q2)){
        enqueue(dequeue(q2), cat);
    }
    return cat;
}
//id ascissa
//cicli necessari: ordinata
void scheduler (queue processes, int cicli){
    while (!emptyQueue(processes)){
        item proc = dequeue(processes);
        float cpuBurst = ordinata(proc) - cicli;
        if (cpuBurst > 0){
            enqueue(creaPunto(ascissa(proc), cpuBurst), processes);
        }

    printQueue(processes);
    printf("\n");
    }  
    printf("DONE\nF-SOCIETY\n");
}

int main(){
    queue q = newQueue();
    q = createQueue();
    //printQueue(q);

    queue q1, q2, q3, q4;

    // q1 = newQueue();
    // q2 = newQueue();
    // q3 = newQueue();
    // q4 = newQueue();

    //sottoCode(q, q1, q2, q3, q4);
    
    //printf("1 quadrante\n");
    //printQueue(q1);
    //printf("2 quadrante\n");
    //printQueue(q2);
    //printf("3 quadrante\n");
    //printQueue(q3);
    //printf("4 quadrante\n");
    //printQueue(q4);
    
    printf("lunghezza spezzata: %g\n", spezzata(q));
    printQueue(q);

    // queue cat = concatena(q4, q3);
    // cat = concatena(cat, q2);
    // cat = concatena(cat, q1);

    // printQueue(cat);

    // queue proc = newQueue();

    // enqueue(creaPunto(1, 10), proc);
    // enqueue(creaPunto(2, 3), proc);
    // enqueue(creaPunto(3, 8), proc);
    // enqueue(creaPunto(4, 5), proc);

    // scheduler (proc, 4);
}