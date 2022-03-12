#include <stdio.h>
#include <stdlib.h>

#define lenA 5
#define lenB 3

void* xcalloc(size_t num, size_t size){
    void* p = calloc(num, size);
    if(!p){
        printf("alloc failed\n");
        exit(-1);
    }
    return p;
}
int* sumArray(int min[], int max[], int lenMin, int lenMax){
    int *c = xcalloc(lenMax, sizeof(int));
    int i = 0;
    for(i; i < lenMin; i++)
        c[i] = min[i] + max[i];

    for(i; i < lenMax; i++)
        c[i] = max[i];

    return c;
}

int* sumArrayChoice(int *a, int *b, int lena, int lenb){
    if(lena > lenb) 
        return sumArray(b, a, lenb, lena);
    else 
        return sumArray(a, b, lena, lenb);
}

void outputArray(int *a, int len){
    for (int i = 0; i < len; i++){
        printf("| %d |", a[i]);
    }
    printf("\n");
}

int main(){
    int a[lenA] = {1,2,3,4,5};
    int b[lenB] = {1,2,3};
    int *c = sumArrayChoice(a, b, lenA, lenB);
    outputArray(c, lenA < lenB ? lenB : lenA);
}