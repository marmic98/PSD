#include <stdio.h>

#define GREEN "\033[0;32m"
#define RESET "\033[0;37m"

int fattoriale(int n, int f, int i){
    if (i <= n){
        f = i*f;
        i = i + 1;
        return fattoriale(n, f, i);
    }
    return f;
}

int fattIt (int n){
    return fattoriale (n, 1, 1);
}

int main(){
    int n;
    printf("FATTORIALE INCREDIBILE RICORSIVO\nFornisci numero: ");
    scanf("%d", &n);
    printf("fatt: %d\n", fattIt(n));
    //printf("il FATTORIALE di %d e' = %s%d%s\n",n,GREEN, fattIt(n) ,RESET);
}