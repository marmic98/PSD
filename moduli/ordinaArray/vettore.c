#include <stdio.h>
#include "vettore.h"
#include "utility.h"

int posMinimo(int *a, int i, int len){
    int posMin = i; 
    for (int j = i + 1; j < len; j++){
        if (a[posMin] > a[j]){
            posMin = j;
        }
    }
    return posMin;
}

int minimoArray(int *a, int i, int len){
    int min = a[i]; 
    for (int j = i + 1; j < len; j++){
        if (min > a[j]){
            min = a[j];
        }
    }
    return min;
}

void selectionSort(int a[], int len){
    int i, p;
    for (i = 0; i < len - 1; i++){
        p = posMinimo(a, i, len);
        if (p != i)
            swap(&a[i], &a[p]);
    }
}

void outputArray(int *a, int len){
    for (int i = 0; i < len; i++){
        printf("| %d |", a[i]);
    }
    printf("\n");
}

void inputArray(int *a, int len){
    for (int i = 0; i < len; i++){
        printf("Fornisci elemento %d dell'array ", i+1);
        scanf("%d", &a[i]);
    }
}

int ricercaBinaria(int* a,int item, int len){
    int inizio=0,fine=len-1,centro;
    while(inizio <= fine){
        centro = (inizio+inizio)/2;
        if (a[centro]==item){
            return centro;
        }
         else if (item > a[centro]){
            inizio = centro+1;
        }
        else {
            fine = centro-1;
        }
    }
    return -1;
}