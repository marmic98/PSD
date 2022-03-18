#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "utility.h"
#include "punto.h"

typedef struct pnt {
    float x;
    float y;
} pnt;

punto creaPunto(float x, float y){
    punto p = xmalloc(sizeof(pnt));
    p->x = x;
    p->y = y;
    return p;
}

float ascissa(punto p){
    return p->x;
}

float ordinata(punto p){
    return p->y;
}

float distanza(punto p1, punto p2){
    float dx = p1->x - p2->x;
    float dy = p1->y - p2->y;
    float d = sqrt(dx*dx + dy*dy);
    return d;
}

