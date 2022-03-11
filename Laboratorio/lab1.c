#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN 50

//Utility
void printString(char* s){
    for (int i =0; i < strlen(s); i++){
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

void* xrealloc(void* p, size_t size){
    p = realloc(p, size);
    if (p == NULL){
        printf("Allocation of %lu bytes failed", size);
        exit(-1);
    }
    return p;
}

void* xcalloc(size_t num, size_t size){
    void* p = calloc(num, size);
    if (p == NULL){
        printf("Allocation of %lu bytes failed", size);
        exit(-1);
    }
    return p;
}

void swap(char* a, char* b){
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
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

//richiesta 3: funzione che effettua il merge di due stringhe
char* merge(char** tab){
    int len0 = strlen(tab[0]);
    int len1 = strlen(tab[1]);

    char* mergedStr = (char*)xmalloc(len0 + len1 + 1);

    strcpy(mergedStr, tab[0]);
    
    int i = len0;
    for(i; i < (len0 + len1); i++){
        mergedStr[i] = tab[1][i-len0]; 
    }
    mergedStr[i] = '\0';
    return mergedStr;
}
//richiesta 4: funzione che effettua l'incastonamento di una stringa in un' altra
char* incastona(char* lunga, char* corta){
    int lenLunga = strlen(lunga);
    int lenCorta = strlen(corta);
    char* incastonamento = (char*)xmalloc(lenLunga);

    strcpy(incastonamento, lunga);

    int meta0 = lenLunga/2;
    int meta1 = lenCorta/2;
    int start = meta0 - meta1;
    int i;
    for (i = 0, start; start < meta0 + meta1, i < lenCorta; start++, i++){
        incastonamento[start] = corta[i];
    }
    return incastonamento;
}

char* incastonaGenerico(char** tab){
    int len0 = strlen(tab[0]);
    int len1 = strlen(tab[1]);
    
    if (len0 >= len1){ //metto tab1 in tab0
        return incastona(tab[0], tab[1]);
    }else{//metto tab0 in tab1
        return incastona(tab[1], tab[0]);
    }
}

//richiesta 5: funzione che effettua lo swap di stringhe
void inverti(char** tab){
    char* temp = tab[0];
    tab[0] = tab[1];
    tab[1] = temp;
}

/*richiesta 6: funzione che aggiunge alla matrice di stringhe una terza stringa
 *composta dai primi tre caratteri del nome e gli ultimi tre del cognome
 */  
void crea(char** tab){
    tab[2] = xcalloc(7, 1);

    strncat(tab[2], tab[0], 3);
    
    int len1 = strlen(tab[1]);
    strcat(tab[2], tab[1] + (len1-3));

    tab[2][6] = '\0';
} 

//richiesta 7: funzione che effettua il Bubble Sort di due stringhe
void bubbleSort(char* s){
    int i;
    int len = strlen(s);
    for (i = 0; i < len - 1; i++){
        for(int j = i + 1; j < len; j++){
            if (s[i] > s[j])
                swap(&s[i], &s[j]);
        }
    }
}

int main(){
    printf("Fornire nome ");
    char* nome = readString(MAXLEN);

    printf("Fornire cognome ");
    char* cognome = readString(MAXLEN);

    printf("Il carattere minimo del nome e' %c\n", minimo(nome));
    printf("Il carattere minimo del cognome e' %c\n", minimo(cognome));

    char **tab= xmalloc(2 * sizeof(char*));
    tab[0] = nome;
    tab[1] = cognome;

    printf("i caratteri minimi delle due stringhe sono rispettivamente: ");
    printString(minimo2(tab, 2));

    printf("il merge tra le due stringhe e' %s\n", merge(tab));

    printf("l'incastonamento delle due stringhe e' %s\n", incastonaGenerico(tab));

    inverti(tab);
    printf("...SWAP...\nnome %s\ncognome %s\n", tab[0], tab[1]);
    inverti(tab);

    tab = xrealloc(tab, sizeof(char*) * 3);
    crea(tab);
    printf("tab[2] ==> %s\n",tab[2]);

    bubbleSort(tab[0]);
    bubbleSort(tab[1]);
    printf("nome ordinato secondo ASCII table: %s\ncognome ordinato secondo ASCII table: %s\n", tab[0], tab[1]);
}