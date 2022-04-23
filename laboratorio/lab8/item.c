#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "item.h"

typedef struct pnt {
    float x;
    float y;
} pnt;

punto creaPunto(float x, float y){
    punto p = malloc(sizeof(struct pnt));
    if (p){
        p->x = x;
        p->y = y;
    }
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

void printPunto(punto p){
    printf("(%g, %g)", p->x,p->y);
}

int equal(punto p1, punto p2){
    return ((ascissa(p1) == ascissa(p2)) && (ordinata(p1) == ordinata(p2)));
}

int lessx (punto p1, punto p2){
    return ascissa(p1) < ascissa(p2);
}

int lessy (punto p1, punto p2){
    return ordinata(p1) < ordinata(p2);
}

void swapPunto(punto* a, punto* b){
    punto temp = *a;
    *a = *b;
    *b = temp;
}

