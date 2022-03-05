#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN 50

void printString(char* s, int len){
    for (int i =0; i < len; i++){
        printf("%c ", s[i]);
    }
    printf("\n");

}

void* xmalloc(size_t size){
    void* p = malloc(size);
    if (p == NULL){
        printf("Allocation of %lu bytes failed", size);
        exit(-1);
    }
    return p;
}

void readLine(char* s, int len){
    fgets(s, len, stdin);
    int newLen = strlen(s);
    if (s[newLen - 1] == '\n')
        s[newLen - 1] = '\0';
}

char* readString(int len){
    char* s = xmalloc(len);
    readLine(s, len);
    int newLen = strlen(s);
    char* s1 = xmalloc(newLen);
    strcpy(s1, s);
    free(s);
    return s1;
}
//richiesta 1: funzione che torva il carattere minimo secondo la ASCII table
char minimo (char* str){
    int len = strlen(str);
    char min = str[0];
    for (int i = 1; i < len; i++){
        if (min > str[i])
            min = str[i];
    }
    return min; 
}

//richiesta 2: funzione che trova il carattere minimo secondo la ASCII table di un insieme di stringhe
char* minimo2(char** tab, int dim){
    char* minimi = xmalloc(dim + 1);
    for (int i = 0; i < dim; i++){
        minimi[i] = minimo(tab[i]);
    }
    minimi[dim] = '\0';
    return minimi;
}

int main(){
    printf("Fornire nome ");
    char* nome = readString(MAXLEN);

    printf("Fornire cognome ");
    char* cognome = readString(MAXLEN);

    printf("Il carattere minimo del nome e' %c\n", minimo(nome));
    printf("Il carattere minimo del cognome e' %c\n", minimo(cognome));

    char *tab[2];
    tab[0] = nome;
    tab[1] = cognome;
    printString(minimo2(tab, 2), 2);  
}