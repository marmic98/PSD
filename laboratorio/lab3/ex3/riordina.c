#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "punto.h"
#include "utility.h"

#define LEN 30

int contaPunti(char* fInName){
    FILE* fin = fopen(fInName, "r");
    int nPunti = 0;

    if (!fin){
        printf("Errore apertura file\n");
        exit(-1);
    }
    else{
        float x=0, y=0;
        while(fscanf(fin, "%f%f", &x, &y)==2){
            nPunti++;
        }
        fclose(fin);
    }
    return nPunti;
}

void caricaPunti(char* fInName, punto p[], int nPunti){
    FILE* fin = fopen(fInName, "r");

    if (!fin){
        printf("Errore apertura file\n");
        exit(-1);
    }
    else{
        float x=0, y=0;
        for(int i = 0 ; i < nPunti;i++){
            fscanf(fin, "%f%f", &x, &y);
            p[i] = creaPunto(x, y);
        }
    fclose(fin);
    }
}

int confrontoPunti(punto *p1, punto *p2, int nPunti){    
    int i = 0;
    while(i < nPunti){
        if ((ordinata(p1[i]) == ordinata(p2[i])) && (ascissa(p1[i]) == ascissa(p2[i])))
            i++;
        else return 0;
    }
    return 1;
}

void bubbleSortCrescentex(punto* p, int nPunti){
    for (int i = 0; i < nPunti - 1; i++){
        for(int j = i + 1; j < nPunti; j++){
            if (ascissa(p[i]) > ascissa(p[j]))
                swapPunto(&p[i], &p[j]);
        }
    }
}

void bubbleSortCrescentey(punto* p, int nPunti){
    for (int i = 0; i < nPunti - 1; i++){
        for(int j = i + 1; j < nPunti; j++){
            if (ordinata(p[i]) > ordinata(p[j]))
                swapPunto(&p[i], &p[j]);
        }
    }
}

void bubbleSortDecrescentex(punto* p, int nPunti){
    for (int i = 0; i < nPunti - 1; i++){
        for(int j = i + 1; j < nPunti; j++){
            if (ascissa(p[i]) < ascissa(p[j]))
                swapPunto(&p[i], &p[j]);
        }
    }
}

void bubbleSortDecrescentey(punto* p, int nPunti){
    for (int i = 0; i < nPunti - 1; i++){
        for(int j = i + 1; j < nPunti; j++){
            if (ordinata(p[i]) < ordinata(p[j]))
                swapPunto(&p[i], &p[j]);
        }
    }
}
//criterio: a crescente d decrescente
//coordinata: o ordinata a ascissa
void riordina (punto* p, int nPunti, char coordinata, char criterio){
    if (criterio == 'a' && coordinata=='a')
        bubbleSortCrescentex(p, nPunti);
    if (criterio == 'a' && coordinata=='o')
        bubbleSortCrescentey(p, nPunti);
    if (criterio == 'd' && coordinata=='a')
        bubbleSortDecrescentex(p, nPunti);
    if (criterio == 'd' && coordinata=='o')
        bubbleSortDecrescentey(p, nPunti);
}

int runTestCase (char* tcId, int nPunti, char coordinata, char criterio){
    char fInName[LEN], fOutName[LEN], fOracleName[LEN];
    strcpy(fInName, tcId);
    strcat(fInName, "_input.txt");

    strcpy(fOutName, tcId);
    strcat(fOutName, "_output.txt");

    strcpy(fOracleName, tcId);
    strcat(fOracleName, "_oracle.txt");

    FILE* output;
    FILE* oracle;
    FILE* input;
    
    punto *p = xmalloc(sizeof(punto)*nPunti);
    caricaPunti(fInName, p, nPunti);

    riordina(p, nPunti, coordinata, criterio);
    
    for(int i = 0; i < nPunti; i++) {
        printf("punto n%d\n", i);
        printPunto(p[i]);
    }

    output = fopen(fOutName, "w");
    for(int i = 0; i < nPunti; i++){
        fprintf(output, "%f %f\n", ascissa(p[i]), ordinata(p[i]));
    }
    fclose(output);

    punto *pOracle = xmalloc(sizeof(punto) * nPunti);
    oracle = fopen(fOracleName, "r");
    caricaPunti(fOracleName, pOracle, nPunti);
    fclose(oracle);
    
    return confrontoPunti(p, pOracle, nPunti);
}

int main(int argc, char *argv[]){
    if (argc < 3){
        printf("numero di parametri inseriti insufficienti\n");
        exit(-1);
    }

    FILE* testSuite = fopen(argv[1], "r");
    FILE* result = fopen(argv[2], "w");

    if (!testSuite || !result){
        printf("Impossibile aprire file di input\n");
        exit(-1);
    }
    char tcId[5];
    int nPunti = 0;
    char coordinata;
    char criterio;

    while(fscanf(testSuite, "%s %d %c %c", tcId, &nPunti, &coordinata, &criterio) == 4){
        fprintf(result, "%s ",tcId);
        printf("%s %d %c %c\n", tcId, nPunti, coordinata, criterio);
        runTestCase(tcId, nPunti, coordinata, criterio) ? fprintf(result, "PASS\n") : fprintf(result, "FAILED\n");
    }
    fclose(result);
    fclose(testSuite);
    return 0;
}