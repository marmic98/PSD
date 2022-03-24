#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN 50

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

void bubbleSort(char** strCollection, int counter){
    for (int i = 0; i < counter - 1; i++){
        for(int j = i + 1; j < counter; j++){
            if(strcmp(strCollection[i], strCollection[j]) > 0){
                char *temp = strCollection[i];
                strCollection[i] = strCollection[j];
                strCollection[j] = temp;
            }
        }
    }
}
    
int occurences (char* fInName, char* str){
    int len = strlen(str);
    FILE* fin = fopen(fInName, "r");
    int occ = 0;
    char* strFromFile = xmalloc(sizeof(char*));
    while(fscanf(fin, "%s", strFromFile) == 1){
        int lenFromFile = strlen(strFromFile);
        for (int i = 0; i < lenFromFile; i++){
            strncmp(strFromFile+i, str, len) == 0 ? occ++ : occ;
        }

    }
    fclose(fin);
    return occ;
}

char** sort (char * fInName, char* fOutName){
    char* temp = xmalloc(LEN);
    int counter = 0;

    FILE* fin = fopen(fInName, "r");
    if (fin){
        while(fscanf(fin, "%s", temp) == 1)  
            counter++;
        fclose(fin);
    }
    else 
        exit(-1);

    char** strCollection = xmalloc(sizeof(char*) * counter);
    fin = fopen(fInName, "r");
    if (fin){
        for (int i = 0; i < counter; i++){
            fscanf(fin, "%s", temp);
            strCollection[i] = xmalloc(strlen(temp));
            strcpy(strCollection[i], temp); 
        }
        fclose(fin);
        free(temp);
    }
    else
        exit(-1);
    
    bubbleSort(strCollection, counter);

    FILE* sortedFile = fopen(fOutName, "w");
    if(sortedFile){
        for(int i = 0; i < counter; i++)
            fprintf(sortedFile, "%s\n", strCollection[i]);
        fclose(sortedFile);
    }
    else
        exit(-1);
    return strCollection;
}

int confrontoStr(char* ss1[], char* ss2[], int num){
    int i = 0;
    while(i < num){
        if (strcmp(ss1[i], ss2[i]) != 0)
            return 0;
        i++;
    }
    return 1;
}

int runTestCase(char* tcId, int num){
    char inputFileName[LEN];
    strcpy(inputFileName, tcId);
    strcat(inputFileName, "_input.txt");

    char oracleFileName[LEN];
    strcpy(oracleFileName, tcId);
    strcat(oracleFileName, "_oracle.txt");

    char outputFileName[LEN];
    strcpy(outputFileName, tcId);
    strcat(outputFileName, "_output.txt");


    char** strs = xmalloc(sizeof(char*) * num);
    strs = sort(inputFileName, outputFileName);

    FILE* oracle = fopen(oracleFileName, "r");
    char temp[LEN];

    char** oracleStrs = xmalloc(sizeof(char*) * num);
    if (oracle){
        for (int i = 0; i < num; i++){
            fscanf(oracle, "%s", temp);
            oracleStrs[i] = xmalloc(strlen(temp));
            strcpy(oracleStrs[i], temp); 
        }
        fclose(oracle);
    }
    else
        exit(-1);
    
    return confrontoStr(strs, oracleStrs, num);

}

int main(int argc, char* argv[]){
    char mode = argv[1][0];
    char* fInName = argv[2];
    char* str = argv[3];
    char tcId[LEN];
    // if (mode == 'o'){
    //     printf("Le occorrenze della stringa %s sono %d\n", str, occurences(fInName, str));
    // }
    
    FILE* testSuite = fopen(fInName, "r");
    FILE* result = fopen("result.txt", "w");

    if (!result || !testSuite){
        printf("file di test mancanti\n");
        exit(-1);
    }
    else{
        int num = 0;
        while(fscanf(testSuite, "%s%d", tcId, &num) == 2){
            fprintf(result, "%s ", tcId);
            runTestCase(tcId, num) ? fprintf(result, "PASS\n") : fprintf(result, "FAILED\n");
        }
        fclose(result);
        fclose(testSuite);
    }
}