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

void insertionSort(int a[], int len){
    int i;
    for (i = 1; i < len; i++){
        int toSwap = a[i];
        int j = i - 1;
        while(j >= 0 && toSwap < a[j]){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = toSwap;  
    }
}

int main(void){
    int a[MAXLEN] = {5,4,3,2,1};
    insertionSort(a, MAXLEN);
    printArray(a, MAXLEN);
}