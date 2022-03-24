#include <stddef.h>


void* xmalloc(size_t size);
void* xcalloc(size_t num, size_t size);
void* xrealloc(void* p, size_t size);