#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vettore.h"
#include "utility.h"

#define MAXLEN 50

//richiesta 2: funzione che effettua il Bubble Sort di due stringhe
void bubbleSort(int* a, int len){
    for (int i = 0; i < len - 1; i++){
        for(int j = i + 1; j < len; j++){
            if (a[i] > a[j])
                swap(&a[i], &a[j]);
        }
    }
}

int main(int argc, char* argv[]){
    //su windows in argv[0] c'è "path//a.exe"
    //su Linux contiene solo il nome dell'eseguibile
    
    int len = argc - 1;
    int *a = xmalloc(sizeof(int) * len);
    inputArrayCmd(a, argv, len);
    bubbleSort(a, len);
    outputArray(a, len);
}