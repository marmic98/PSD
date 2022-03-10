#include <stdio.h>
#include "vettore.h"
#include "utility.h"

int main(void){
    int lenArray;
    printf("Fornire lunghezza array ");
    scanf("%d", &lenArray);

    int* a = xmalloc(lenArray * sizeof(int));

    inputArray(a, lenArray);
    //printf("l'elemento piu' piccolo dell'array e' %d e la sua posizione nell'array e' %d (from 0)\n", minimoArray(a, 0, lenArray), posMinimo(a, 0, lenArray));
    selectionSort(a, lenArray);
    outputArray(a, lenArray);
}