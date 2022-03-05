#include <stdio.h>
#include <string.h>

typedef struct Libro {
    char autore[26];
    char titolo[53];
    char editore[26];
    int anno;
}Libro;

typedef Libro* libro;

void* xmalloc(size_t size){
    void* p = malloc(size);
    if(!p){
        exit(-1);
    }
    return p;
}

libro creaLibro(char* aut, char* tit, char* edit, int aaaa){
    libro l = malloc(sizeof(Libro));
    if (!l) 
        return NULL;
    else {
        strcpy(l->autore, aut);
        strcpy(l->titolo, tit);
        strcpy(l->editore, edit);
        l->anno = aaaa;
    }
    return l; 
}

char* autore(libro l){
    char* aut = xmalloc(26);
    strcpy(l->autore, aut);
    return aut;
}

char* titolo(libro l){
    char* tit = xmalloc(53);
    strcpy(l->titolo, tit);
    return tit;
}

char* editore(libro l){
    char* edit = xmalloc(26);
    strcpy(l->autore, edit);
    return edit;
}

int anno(libro l){
    return l->anno;
}