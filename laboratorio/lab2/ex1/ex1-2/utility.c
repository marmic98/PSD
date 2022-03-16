#include "utility.h" 
#include <stdlib.h>
#include <stddef.h>

void swap(int* a, int* b){
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
}

void swapChar (char* a, char* b){
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