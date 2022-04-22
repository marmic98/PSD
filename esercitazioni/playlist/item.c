#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "item.h"

#define MAXLEN 50
#define NULLITEM 0

struct song {
    char* nome;
    char* artista;
    int durata;
};

item createItem(char* nome, char* artista, int durata){
    item i = malloc(sizeof(struct song));
    if (!i)
        return NULLITEM;
    
    i->artista = artista;
    i->durata = durata;
    i->nome = nome;
    return i;
}

void printItem(item i){
    printf("Nome: %s\nArtista: %s\nDurata: %ds\n\n", i->nome, i->artista, i->durata);
}

char* getNome(item i){
    return i->nome;
}

char* getArtista(item i){
    return i->artista;
}

int getDurata(item i){
    return i->durata;
}

int sameArtist (char* a, char* b){
    return strcmp(a, b);
}