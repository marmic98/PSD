#include "utility.h" 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

char* readString(int lenMax){
    char* s = xmalloc(lenMax);
    fgets(s, lenMax, stdin);
    int len = strlen(s);
    
    s[len-1] = '\0';
    
    char* sOut = xmalloc(len+1);
    strcpy(sOut, s);
    free(s);
    return sOut;
}