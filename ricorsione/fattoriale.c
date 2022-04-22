#include <stdio.h>

#define GREEN "\033[0;32m"
#define RESET "\033[0;37m"

int fattoriale(int n){
    if (n == 0)
        return 1;
    return n * fattoriale(n - 1);
}

int main(){
    int n;
    printf("FATTORIALE INCREDIBILE RICORSIVO\nFornisci numero: ");
    scanf("%d", &n);
    printf("il FATTORIALE di %d e' = %s%d%s\n",n,GREEN, fattoriale(n) ,RESET);
}