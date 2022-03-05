#include <stdio.h>
#include "ordinamenti.h"

#define MAXLEN 5

int main(void){
    int scelta = 0;

    do{
        printf("Quale algoritmo di ordinamento vuoi utilizzare?\n1) Selection Sort\n2) Insertion Sort\n3) Bubble Sort\n4) Esci\n: ");
        scanf("%d", &scelta);
        int a[MAXLEN] = {5,4,3,2,1};
        if (scelta == 1)
            selectionSort(a, MAXLEN);
        if (scelta == 2)
            insertionSort(a, MAXLEN);
        if (scelta == 3)
            bubbleSort(a, MAXLEN);
        if (scelta == 4)
            break;
        if (scelta > 4)
            printf("Hai scelto di non ordinare l'array\n");
        printArray(a, MAXLEN);
    }while(scelta != 4);
    printf("Exiting...\n");
    
}