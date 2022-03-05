#include <stdio.h>

#define MAXLEN 5

void printArray(int *a, int len){
    for (int i = 0; i < len; i++){
        printf("| %d |", a[i]);
    }
    printf("\n");
}

void swap(int* a, int* b){
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
}

void bubbleSort(int a[], int len){
    int i;
    for (i = 0; i < len - 1; i++){
        for(int j = i + 1; j < len; j++){
            if (a[i] > a[j])
                swap(&a[i], &a[j]);
        }
    }
}

int main(void){
    int a[MAXLEN] = {5,4,3,2,1};
    bubbleSort(a, MAXLEN);
    printArray(a, MAXLEN);
}