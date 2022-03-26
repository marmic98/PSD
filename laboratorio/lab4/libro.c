#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libro.h"

struct lbr{
    char* titolo;
    char* editore;
    float prezzo;
    int anno;
}; 

typedef struct lbr* libro;

libro newLibro(char* titolo, char* editore, float prezzo, int anno){
    libro l = malloc(sizeof(struct lbr));
    if (!l){
        perror(" ");
        exit(-1);
    }
    l->titolo = malloc(100);
    l->editore = malloc(50);
    strcpy(l->titolo,titolo);
    strcpy(l->editore,editore);
    l->prezzo = prezzo;
    l->anno = anno;
    return l;
}

char* titolo(libro l){
    return l->titolo;
}

char* editore (libro l){
    return l->editore;
}

float prezzo(libro l){
    return l->prezzo;
}

int anno(libro l){
    return l->anno;
}

float scontaPrezzo(libro* l, float scontoPercentuale){
    float prezzoScontato =  (*l)->prezzo * (1-(scontoPercentuale/100));
    (*l)->prezzo = prezzoScontato;
    return prezzoScontato;
}

void aggiornaAnno(libro* l, int annoNew){
    (*l)->anno = annoNew;
}

void outputLibro(libro l){
printf("Titolo: %s\nEditore: %s\nPrezzo: %g\nAnno: %d\n\n", titolo(l), editore(l), prezzo(l), anno(l));
}