#include "utility.h" 
#include <stdlib.h>

void swap(int* a, int* b){
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
}

void* xmalloc(unsigned int size){
    void* p = malloc(size);
    if(!p)
        exit(-1);
    return p;
}