#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "item.h"

#define MAXLEN 40

struct esame{
    char nome[MAXLEN];
    char data[MAXLEN];
    int voto;
};

item createItem(){
    item e = malloc(sizeof(struct esame));
    
    printf("nome esame: ");
    fgets(e->nome, MAXLEN, stdin);

    printf("nome esame: ");
    fgets(e->data, MAXLEN, stdin);

    printf("voto: ");
    scanf("%d", &e->voto);
    return e;
}

void printItem(item e){
    printf("nome esame:%s\ndata:%s\nvoto:%d\n", e->nome, e->data, e->voto);
}

char* getNome(item e){
    return e->nome;
}