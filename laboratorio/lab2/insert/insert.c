#include <stdio.h>
#include <stdlib.h>

#define LENDEF 5

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

void* xmalloc(size_t size){
    void* p = malloc(size);
    if(!p){
        printf("alloc failed\n");
        exit(-1);
    }
    return p;
}

void* xcalloc(size_t num, size_t size){
    void* p = calloc(num, size);
    if(!p){
        printf("alloc failed\n");
        exit(-1);
    }
    return p;
}

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