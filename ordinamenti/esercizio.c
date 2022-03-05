#include <stdio.h>
#include "ordinamenti.h"

#define MAXLEN 5

void printArray(int *a, int len){
    for (int i = 0; i < len; i++){
        printf("| %d |", a[i]);
    }
    printf("\n");
}

int main(void){
    int a[MAXLEN] = {5,4,3,2,1};
    insertionSort(a, MAXLEN);
    printArray(a, MAXLEN);
}