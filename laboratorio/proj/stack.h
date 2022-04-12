#include "itemStr.h"

typedef struct cStack* stack;

stack newStack();
int sizeStack(stack s);
int emptyList(stack s);
int push(item e, stack s);
int pop(stack s);
item top(stack s);