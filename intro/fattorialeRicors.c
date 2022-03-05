#include <stdio.h>

int fattoriale(int n){
    if (n <= 1)
        return 1;
    else return n * fattoriale(n - 1);
}

int main(void){
    int n;
    do{
        printf("Fornisci numero non negativo: ");
        scanf("%d", &n);
    }while (n < 0);
    printf("Il fattoriale di %d e' %d\n",n, fattoriale(n));
}