#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utility.h"
#include "libro.h"

struct lbr{
    char* titolo;
    char* editore;
    float prezzo;
    int anno;
}; 

libro newLibro(char* titolo, char* editore, float prezzo, int anno){
    libro l = xmalloc(sizeof(struct lbr));
    
    l->titolo = xmalloc(100);
    l->editore = xmalloc(50);
    strcpy(l->titolo,titolo);
    strcpy(l->editore,editore);
    l->prezzo = prezzo;
    l->anno = anno;
    return l;
}

char* titolo(libro l){
    //passare la copia di una stringa sarebbe stato più sicuro poichè non avremmo passato il puntatore 
    //alla stringa del campo titolo ma il puntatore ad un area di memoria in cui c'è una copia della stringa che abbiamo
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