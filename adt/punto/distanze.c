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

int coppieVicine(punto p[], int nPunti, float d){
    int counter = 0;
    for(int i = 0; i < nPunti - 1; i++){
        for(int j = i + 1; j < nPunti; j++){
            if (distanza(p[i], p[j]) < d)
                counter++;
        }
    }
    return counter;
}

int runTestCase (char* tcId, int nPunti, float d){
    
    char fInName[LEN], fOutName[LEN], fOracleName[LEN];
    strcpy(fInName, tcId);
    strcat(fInName, "_input.txt");

    strcpy(fOutName, tcId);
    strcat(fOutName, "_output.txt");

    strcpy(fOracleName, tcId);
    strcat(fOracleName, "_oracle.txt");

    //int nPunti = contaPunti(nPunti);
    FILE* output = fopen(fOutName, "w");
    if(nPunti < 2){
        fprintf(output, "0");
        fclose(output);
    }


    punto *p = xmalloc(sizeof(punto)*nPunti);
    caricaPunti(fInName, p, nPunti);

    int coppieIdonee = coppieVicine(p, nPunti, d);
    output = fopen(fOutName, "w");
    fprintf(output, "%d\n", coppieIdonee);
    fclose(output);

    int coppieIdoneeOracle;
    FILE* oracle = fopen(fOracleName, "r");
    fscanf(oracle, "%d", &coppieIdoneeOracle);
    fclose(oracle);
    printf("output: %d\noracle: %d\n", coppieIdonee, coppieIdoneeOracle);
    return (coppieIdonee == coppieIdoneeOracle);
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
    float d = 0;

    while(fscanf(testSuite, "%s%d%f", tcId, &nPunti, &d) == 3){
        fprintf(result, "%s ",tcId);
        runTestCase(tcId, nPunti, d) ? fprintf(result, "PASS\n") : fprintf(result, "FAILED\n");
    }
    fclose(result);
    fclose(testSuite);
    return 0;
}