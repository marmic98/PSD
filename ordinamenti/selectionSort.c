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

int posMinimo(int *a, int i, int len){
    int posMin = i; 
    for (int j = i + 1; j < len; j++){
        if (a[posMin] > a[j]){
            posMin = j;
        }
    }
    return posMin;
}

void selectionSort(int a[], int len){
    int i, p;
    for (i = 0; i < len - 1; i++){
        p = posMinimo(a, i, len);
        if (p != i)
            swap(&a[i], &a[p]);
    }
}

int main(void){
    int a[MAXLEN] = {5,4,3,2,1};
    selectionSort(a, MAXLEN);
    printArray(a, MAXLEN);
}