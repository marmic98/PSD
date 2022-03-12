#include "utility.h" 
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

void swap(int* a, int* b){
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
}

void* xmalloc(size_t size){
    void* p = malloc(size);
    if(!p)
        exit(-1);
    return p;
}

void* xcalloc(size_t num, size_t size){
    void* p = calloc(num ,size);
    if(!p)
        exit(-1);
    return p;
}

void* xrealloc(void* p, size_t size){
    p = realloc(p, size);
    if (p == NULL){
        printf("Allocation of %lu bytes failed", size);
        exit(-1);
    }
    return p;
}