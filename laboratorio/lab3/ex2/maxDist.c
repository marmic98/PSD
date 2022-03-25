#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "punto.h"
#include "utility.h"

#define LEN 30

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

float* distMaxDots(punto p[], int nPunti){
    float *max = xmalloc(3 * sizeof(float));
    if (nPunti < 2){
        max[0] = -1;
        max[1] = -1;
        max[2] = -1;
        return max; 
    }
    max[0] = distanza(p[0], p[1]);
    for(int i = 0; i < nPunti - 1; i++){
        for(int j = i+1; j < nPunti; j++){
            float dist = distanza(p[i], p[j]);
            if (dist > max[0]){
                max[0] = dist;
                max[1] = i;
                max[2] = j;    
            }
        }
    }
    return max;
}

int confrontoArray(float *a, float *b, int len){
    int i = 0;
    while(a[i] == b[i] && i < len)
        i++;
    return i == len;
}

int runTestCase (char* tcId, int nPunti){
    char fInName[LEN], fOutName[LEN], fOracleName[LEN];
    strcpy(fInName, tcId);
    strcat(fInName, "_input.txt");

    strcpy(fOutName, tcId);
    strcat(fOutName, "_output.txt");

    strcpy(fOracleName, tcId);
    strcat(fOracleName, "_oracle.txt");

    FILE* output = fopen(fOutName, "w");
    FILE* oracle = fopen(fOracleName, "r");
    if(nPunti < 2){
        fprintf(output, "0\n0\n0\n");
        fclose(output);
        float* maxDistOracle = xmalloc(sizeof(float) * 3);
        int i = 0; 
        while(i < 3){
            fscanf(oracle, "%f", &maxDistOracle[i]);
        i++;
    }
        fclose(oracle);
        return maxDistOracle[0] == 0 && maxDistOracle[1] == 0 && maxDistOracle[2] == 0;
    }

    punto *p = xmalloc(sizeof(punto)*nPunti);
    caricaPunti(fInName, p, nPunti);

    float* maxDist = distMaxDots(p, nPunti);
    int j = 0;
    
    output = fopen(fOutName, "w");
    int i = 0;
    while(i < 3){
        fprintf(output, "%f\n", maxDist[i]);
        i++;
    }
    fclose(output);
    i=0;
    float *maxDistOracle = xmalloc(sizeof(float) * 3);
    oracle = fopen(fOracleName, "r");

    while(i < 3){
        fscanf(oracle, "%f", &maxDistOracle[i]);
        i++;
    }
    fclose(oracle);
   
    return (confrontoArray(maxDist,maxDistOracle, 3));
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

    while(fscanf(testSuite, "%s%d", tcId, &nPunti) == 2){
        fprintf(result, "%s ",tcId);
        runTestCase(tcId, nPunti) ? fprintf(result, "PASS\n") : fprintf(result, "FAILED\n");
    }
    fclose(result);
    fclose(testSuite);
    return 0;
}