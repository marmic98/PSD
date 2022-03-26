#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libro.h"

#define BUFFSIZE 100
#define EDITORE "Bompiani"
#define ANNO 2014
#define X 20

void* xmalloc(size_t size){
    void* p = malloc(size);
    if (!p){
        printf("Allocazione di %lu bytes fallita\n", size);
        exit(-1);
    }
    return p;
}

char* readString(){
    char* s = xmalloc(BUFFSIZE);
    fgets(s, BUFFSIZE, stdin);
    int len = strlen(s);

    if (s[len-1] == '\n')
        s[len-1] = '\0';
    
    char* sOut = xmalloc(len+1);
    strcpy(sOut, s);
    free(s);
    return sOut;

}

libro* inputBiblioteca(libro* biblioteca, int n){
    biblioteca = xmalloc(sizeof(libro)*n);
    int c;
    for(int i = 0; i < n; i++){
        while ( (c = getchar()) != '\n' && c != EOF );
        printf("Fornire dati libro n%d\n",i+1);
        printf("Titolo: ");
        char* titolo = readString();
        
        printf("Editore: ");
        char* editore = readString();
         
        printf("Prezzo: ");
        float prezzo = 0;
        scanf("%f", &prezzo);

        printf("Anno: ");
        int anno = 0;
        scanf("%d", &anno);

        biblioteca[i] = newLibro(titolo, editore, prezzo, anno);
    }
    printf("\n");
    return biblioteca;
}

int contaLibriFromFile(char* fInName){
    char buffer[BUFFSIZE];
    int i=0;
    FILE* fin = fopen(fInName, "r");
    if (!fin) exit(-1);

    while (fgets(buffer, BUFFSIZE, fin)) 
        i++;
    return i/4;
}

libro* inputBibliotecaFromFile(int n, char* fInName){
    libro* biblioteca = xmalloc(sizeof(libro)*n);
    FILE* fin = fopen(fInName, "r");
    if(!fin) exit(-1);

    char  *buffer = xmalloc(BUFFSIZE); 
    char *titolo = xmalloc(BUFFSIZE);
    char *editore = xmalloc(BUFFSIZE);
    int anno = 0;
    float prezzo = 0;
    
    for(int i = 0; i < n; i++){

        fgets(buffer, BUFFSIZE, fin);
        buffer[strlen(buffer)-1] = '\0';
        strcpy(titolo, buffer);

        fgets(buffer, BUFFSIZE, fin);    
        buffer[strlen(buffer)-1] = '\0';
        strcpy(editore, buffer);
        
        fgets(buffer, BUFFSIZE, fin);    
        buffer[strlen(buffer)-1] = '\0';
        anno = atoi(buffer);        

        fgets(buffer, BUFFSIZE, fin);    
        buffer[strlen(buffer)-1] = '\0';
        prezzo = atof(buffer);
        biblioteca[i] = newLibro(titolo, editore, prezzo, anno);
    }
    fclose(fin);
    printf("\n");
    return biblioteca;
}

void outputBiblioteca(libro* biblioteca, int n){
    for (int i = 0; i < n; i++){
        printf("Libro n%d\n", i+1);
        outputLibro(biblioteca[i]);
    }
}
//Ricerca del libro più vecchio
libro oldestBook(libro* biblioteca, int n){
    libro oldest = biblioteca[0];
    if (n < 1)
        return NULL; 
    for(int i = 1; i < n; i++){
        if (anno(biblioteca[i]) < anno(oldest))
            oldest = biblioteca[i];
    }
    return oldest;
}

//Ricerca del libro meno costoso
libro CheapestBook(libro* biblioteca, int n){
    libro cheapest = biblioteca[0];
        if (n < 1)
            return NULL; 
        for(int i = 1; i < n; i++){
            if (prezzo(biblioteca[i]) < prezzo(cheapest))
                cheapest = biblioteca[i];
        }
        return cheapest;
}

//Trova tutti i libri dell’editore X
libro* searchPublisher(char* publisher, libro* biblioteca, int n, int* np){
    for (int i = 0; i < n; i++){
        printf("%sa\n%sa\ncmp: %d\n", editore(biblioteca[i]), publisher, !strcmp(editore(biblioteca[i]), publisher));
        if (strcmp(editore(biblioteca[i]), publisher) == 0)
            *np++;
    }    
    if (np == 0)
        return NULL;
    libro* publisherBooks = xmalloc(sizeof(libro) * (*np));
    int counter = 0;
    for (int i = 0; i < n; i++){
        if (strcmp(editore(biblioteca[i]), publisher) == 0){
            publisherBooks[counter] = biblioteca[i];
            counter++;

        }
    }
    return publisherBooks;
}
//Ridurre del X% il costo dei libri dell’anno AAAA.
// questa funzione potrebbe restituire void oppure un intero
// che restiuisce 0 in caso tutto è andato correttamente
int scontaLibri(libro* biblioteca, int n, int year, float percentuale){
    for (int i = 0; i < n; i++){
        if(anno(biblioteca[i]) == year)
            scontaPrezzo(&biblioteca[i], percentuale);
    }
    return 0;
}

//Trova due libri con scarto di prezzo minore
libro* trovaLibriPrezzoSimile(libro* biblioteca, int n){
    libro* coppiaPrezzoSimile= xmalloc(sizeof(libro*) * 2);
    if (n < 2)
        return NULL;
    float differenzaMin = prezzo(biblioteca[0]) - prezzo(biblioteca[1]);
    if (differenzaMin < 0) differenzaMin *=-1;

    for (int i = 0; i < n - 1; i++){
        for (int j = i+1; j < n; j++){
            float diff = prezzo(biblioteca[i]) - prezzo(biblioteca[j]);
            if (diff < 0) diff *=-1;
            if (diff < differenzaMin){
                differenzaMin = diff;
                coppiaPrezzoSimile[0] = biblioteca[i];
                coppiaPrezzoSimile[1] = biblioteca[j];
            }
        }
    }
    return coppiaPrezzoSimile;
}

//Calcola il costo totale di tutti i libri dell’anno AAAA
float costoTotale(libro* biblioteca,int n, int year){
    float prezzoTot = 0;
    for (int i = 0; i < n; i++){
        if (year == anno(biblioteca[i]))
            prezzoTot += prezzo(biblioteca[i]);
    }
    return prezzoTot;
}
    
int delete(libro* b, int n, int pos){
    for(pos; pos < n - 1; pos++){
        b[pos] = b[pos+1];
    }
    return n-1;
}
//Elimina i libri dell'anno AAAA
int eliminaLibri(libro* biblioteca,int n, int year){
    int i = 0;
    while(i < n){
        if (year == anno(biblioteca[i]))
            n = delete(biblioteca, n, i);
        else i++;
    }
    biblioteca = realloc(biblioteca, sizeof(libro) * n);
    return n;
}

int main(int argc, char *argv[]){
    if (argc < 2){
        printf("File mancanti in input\n");
        exit(-1);
    }
    char* inputFileName = argv[1];

    // printf("Fornire il numero di libri da inserire in biblioteca\n");
    // scanf("%d", &n);

    int n = contaLibriFromFile(inputFileName);
    
    //input biblioteca
    //biblioteca = inputBiblioteca(biblioteca, n);
    libro * biblioteca = inputBibliotecaFromFile(n, inputFileName);
    outputBiblioteca(biblioteca, n);

    libro test = newLibro("","",0,0);

    //ricerca libro più antico
    test = oldestBook(biblioteca, n);
    if (test == NULL)
        printf("Numero libri insufficienti\n");
    else{
        printf("Libro più vecchio:\n");
        outputLibro(test);
    }
    //ricerca libro meno costoso
    test = CheapestBook(biblioteca, n);
    if (test == NULL)
        printf("Numero libri insufficienti\n");
    else{
        printf("Libro meno costoso:\n");
        outputLibro(test);
    }

    //trova libri editore x
    char* publisher = "Bompiani";
    int nPublisher = 0;
    libro* testBiblioteca = searchPublisher(publisher, biblioteca, n, &nPublisher);
    if (nPublisher == 0)
        printf("%s non ha pubblicato alcun libro\n", publisher);
    else{
        printf("I libri pubblicati da %s sono %d:\n", publisher, nPublisher);
        outputBiblioteca(testBiblioteca, nPublisher);
    }

    //sconta libri pubblicati nell'anno ANNO dell'X%
    printf("Sconto dell'%d sui libri pubblicati nell'anno %d\n",X, ANNO);
    scontaLibri(biblioteca, n, ANNO, X);
    outputBiblioteca(biblioteca, n); 

    //coppia differenz aprezzo minore
    printf("Coppia libri differenza di prezzo minore:\n");
    libro* coppia = trovaLibriPrezzoSimile(biblioteca, n);
    outputBiblioteca(coppia, 2);

    //costo totale libri nell'anno ANNO
    printf("Costo totale dei libri pubblicati nell'anno %d: %g\n\n", ANNO, costoTotale(biblioteca, n, ANNO));

    //eliminia libri pubblicati nell'anno
    printf("Libri pubblicati nell'anno %d eliminati!\n", ANNO);
    n = eliminaLibri(biblioteca, n, ANNO); //aggiorniamo la lunghezza effettiva dei libri restiendo il nuovo n
    outputBiblioteca(biblioteca, n); 
}