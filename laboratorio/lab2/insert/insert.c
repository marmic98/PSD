#include <stdio.h>
#include <stdlib.h>
#include "utility.h"
#include "vettore.h"

#define LENDEF 5

int shiftDx(int a[], int len, int pos){
    for(int i = len; i > pos; i--)
        a[i] = a[i-1];
    return len+1;
}

void arrayCopy(int* toCopy, int* copied, int len){
    for(int i = 0; i < len; i++){
        copied[i] = toCopy[i];
    }
}

int* insert(int a[], int len, int element, int pos){
    int *aNew = xcalloc((len + 1), sizeof(int));
    arrayCopy(a, aNew, len);
    shiftDx(aNew, len + 1, pos);
    aNew[pos] = element;
    free(a);
    return aNew;
}

int main(){
    int *a = xmalloc(LENDEF * sizeof(int));
    int element, pos;

    inputArray(a, LENDEF);

    printf("Fornire valore da inserire nell'array ");
    scanf("%d", &element);
    printf("Fornire valore da inserire nell'array ");
    scanf("%d", &pos);
    a = insert(a, LENDEF, element, pos);

    outputArray(a, LENDEF);

}