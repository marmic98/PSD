#include <stdio.h>

#define N 8

int ricercaBinaria(int a[],int item, int inizio, int fine){
    if(inizio >= fine){
        return -1;
    }else{
        int centro = (inizio+fine)/2;
        if(a[centro]==item){
            return centro;
        }
         else if (item > a[centro]){
            return ricercaBinaria(a, item, centro + 1, fine);
        }
        else {
            return ricercaBinaria(a, item, inizio, centro - 1);
        }
    }
}

int main(){
    int item;
    
    printf("Fornire elemento da ricercare: ");
    scanf("%d", &item);

    int a[N] = {0,5,10,15,91,115,215,366};
    int pos = ricercaBinaria(a,item, 0, N-1);	

    pos == -1 ? printf("L'elemento %d non è presente nell'array\n",item) : printf("L'elemento %d e' in posizione %d\n",item,pos);
}