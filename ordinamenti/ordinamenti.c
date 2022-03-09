#include <stdio.h>
#include <unistd.h>
#include "ordinamenti.h"

void printArray(int *a, int len){
    for (int i = 0; i < len; i++){
        printf("| %d |", a[i]);
    }
    sleep(1);
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
        printArray(a, len);
        for(int j = i + 1; j < len; j++){
            if (a[i] > a[j])
                swap(&a[i], &a[j]);
        }
    }
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
        printArray(a, len);
        p = posMinimo(a, i, len);
        if (p != i)
            swap(&a[i], &a[p]);
    }
}

void insertionSort(int a[], int len){
    for (int i = 1; i < len; i++){
        int toSwap = a[i];
        int j = i - 1;
        printArray(a, len);
        while(j >= 0 && toSwap < a[j]){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = toSwap;  
    }
}