#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vettore.h"
#include "utility.h"

#define MAXLEN 50

//richiesta 3: funzione che trova consonanti e vocali di una stringa
int isVocal(char c){
    return (c == 'a' || c == 'A' || c == 'e' || c == 'E' || c == 'i' || c == 'I' || c == 'O' ||c == 'o' ||c == 'U' || c == 'u');
}

int isCons(char c){
    return (c == 'b' || c == 'B' || c == 'c' || c == 'C' || c == 'd' || c == 'D' || c == 'F' ||c == 'f' ||c == 'G' ||c == 'g' || 
    c == 'h' || c == 'H' || c == 'j' || c == 'J' || c == 'k' || c == 'K' || c == 'l' ||c == 'L' ||c == 'M' || c == 'm' 
    ||c == 'N' || c == 'n'||c == 'P' || c == 'p' ||c == 'Q' || c == 'q' ||c == 'R' || c == 'r' ||c == 'S' || c == 's' ||c == 'T' || c == 't' ||c == 'V' || c == 'v' ||c == 'W' || c == 'w' ||c == 'X' || c == 'x' ||c == 'Y' || c == 'y' ||c == 'Z' || c == 'z'  );
}

char** vocaliConsonanti(char* s){
    char** vocons = xcalloc(2, sizeof(char*));
    int cons;
    int voc;
    int len = strlen(s);
    
    for (int i = 0; i < len; i++){
        if (isVocal(s[i]))
            voc++;
        else if (isCons(s[i]))
            cons++; 
    }
    
    vocons[0] = xcalloc(voc, sizeof(char));
    vocons[1] = xcalloc(cons, sizeof(char));

    int i, vocIndex = 0, consIndex = 0;

    for (i = 0; i < len; i++){
        if (isVocal(s[i])){
            vocons[0][vocIndex] = s[i];
            vocIndex++;
        }
        else if (isCons(s[i])){
            vocons[1][consIndex] = s[i];
            consIndex++;
        }
    }

    vocons[0][vocIndex] = '\0';
    vocons[1][consIndex] = '\0';

    return vocons;

} 

int main(int argc, char* argv[]){
    //su windows in argv[0] c'è "path//a.exe"
    //su Linux contiene solo il nome dell'eseguibile
    
    char* nome = argv[1];
    char* cognome = argv[2];

    if (argc < 3) exit(-1);
    
    char** voconsNome = xcalloc(2, sizeof(char*));
    voconsNome = vocaliConsonanti(nome);
    printf("vocali cognome: %s\n", voconsNome[0]);
    printf("consonanti cognome: %s\n", voconsNome[1]);

    char** voconsCognome = xcalloc(2, sizeof(char*));
    voconsCognome = vocaliConsonanti(cognome);
    printf("vocali cognome: %s\n", voconsCognome[0]);
    printf("consonanti cognome: %s\n", voconsCognome[1]);
}