#include <stdio.h>

#define GREEN "\033[0;32m"
#define RESET "\033[0;37m"

int sommaRicorsiva(int m, int n){
    if (n == 0)
        return m;
    return  1 + sommaRicorsiva(m, n - 1);
}



int main(){
    int n,m, sum;
    printf("SOMMATORE INCREDIBILE RICORSIVO\nFornisci il primo addendo: ");
    scanf("%d", &n);
    printf("Fornisci il secondo addendo: ");
    scanf("%d", &m);
    sum = sommaRicorsiva(n, m);
    printf("la SOMMA e' %d + %d = %s%d%s\n", n,m,GREEN,sum, RESET);
}