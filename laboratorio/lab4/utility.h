#include <stddef.h>

char* readString(int lenMax);
void swap(int* a, int* b);
void* xmalloc(size_t size);
void* xcalloc(size_t num, size_t size);
void* xrealloc(void* p, size_t size);