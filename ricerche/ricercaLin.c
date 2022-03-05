#include <stdio.h>

#define N 8

int ricercaLineare(int* a, int len, int item){
    for (int i = 0; i < len; i++){
        if (a[i] == item)
            return i;
    }
    return -1;
}

int main(){
    int item;
    
    printf("Fornire elemento da ricercare: ");
    scanf("%d", &item);

    int a[N] = {0,5,10,15,91,115,215,366};
    int pos = ricercaLineare(a,N, item);	

    pos == -1 ? printf("L'elemento %d non è presente nell'array\n",item) : printf("L'elemento %d e' in posizione %d\n",item,pos);
}