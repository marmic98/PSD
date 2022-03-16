#include <stdio.h>
#include <stdlib.h>
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
    if (len <= 1)
        return;
    else{
        for (i = 0; i < len - 1; i++){
            p = posMinimo(a, i, len);
            if (p != i)
                swap(&a[i], &a[p]);
        }
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

void inputArrayCmd(int *a, char* argv[], int len){
    for (int i = 0; i < len; i++){
        a[i] = atoi(argv[i+1]);
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

int* inputArrayFromFile (int len, char* inputFileName){
    int* a = xcalloc(len, sizeof(int));
    FILE* fInput = fopen(inputFileName, "r");
    if (!fInput){
        printf("Errore apertura file\n");
        exit(-1);
    }
    else{
        for(int i = 0; i < len; i++){
            fscanf(fInput, "%d", &a[i]);
        }
        fclose(fInput);
    }
    return a;
} 

void outputArrayToFile(int a[], int len, char* outputFileName){ 
    FILE* fOutput = fopen(outputFileName, "w");
    if (!fOutput){
        printf("Errore apertura file\n");
        exit(-1);
    }
    else{
        for(int i = 0; i < len; i++){
            fprintf(fOutput, "%d\n", a[i]);
        }
        fclose(fOutput);
    }
}

int confrontoArray(int a[], int b[], int len){
    int i = 0;
    while(a[i] == b[i] && i < len)
        i++;
    return i == len;
}