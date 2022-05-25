#include <stdio.h>
#include <stdlib.h>
#include "btree.h"
#include "BST.h"
#include "list.h"
#include "item.h"

BST insertFromArray(int *a, int n){
    BST b = newBST();
    for (int i = 0; i < n; i++)
        b = insert(b, createItem(a[i]));
    return b;
}

Btree inputBtreeFromArray(int *a, int i, int n){
    if (i < n)
        return consBtree(createItem(a[i]), inputBtreeFromArray(a, 2 * i + 1, n), inputBtreeFromArray(a, 2 * i + 2, n));
    else
        return newBtree();
}

void printBTree(Btree b, int i, int h){
    if (i < h)
    {
        for (int j = 0; j < i; j++)
            printf("   ");
        if (emptyBtree(b))
        {
            printf("[ ]\n");
            return;
        }
        printItem(getItem(getRoot(b)));
        printf("\n");
        printBTree(figlioSX(b), i + 1, h);
        printBTree(figlioDX(b), i + 1, h);
    }
    else
        return;
}

void printBST(BST b, int i, int h){
    if (i < h)
    {
        for (int j = 0; j < i; j++)
            printf("   ");
        if (emptyBST(b))
        {
            printf("[ ]\n");
            return;
        }

        printItem(getItem(getRoot(b)));
        printf("\n");
        printBST(figlioSX(b), i + 1, h);
        printBST(figlioDX(b), i + 1, h);
    }
    else
        return;
}

void nodiAltezzaK(BST b, list *a, int k, int j){
    if (emptyBST(b))
        return;
    if (k == j)
    {
        *a = consList(getItem(getRoot(b)), *a);
        return;
    }
    else
    {
        nodiAltezzaK(figlioDX(b), a, k, j + 1);
        nodiAltezzaK(figlioSX(b), a, k, j + 1);
    }
}

int isBst(Btree t){
    if (emptyBtree(t))
        return 1;
    if (!emptyBtree(figlioSX(t)))
    {
        if (cmp(getItem(getRoot(t)), getItem(getRoot(figlioSX(t)))) == 1)
            return 0;
    }
    if (!emptyBtree(figlioDX(t)))
    {
        if (cmp(getItem(getRoot(t)), getItem(getRoot(figlioDX(t)))) == -1)
            return 0;
    }
    return (isBst(figlioSX(t)) && isBst(figlioDX(t)));
}

// precondizione
// n elementi = (2^k)-1
// array ordinato in mod crescente
BST bilanciato(int *a, int i, int f){
    if (i > f)
        return newBST();
    int mid = (i + f) / 2;
    return consBtree(createItem(a[mid]), bilanciato(a, i, mid - 1), bilanciato(a, mid + 1, f));
}

void printInterval(BST root, int a, int b){
    if (emptyBST(root))
    {
        return;
    }
    if (a < getValue(getItem(getRoot(root))))
        printInterval(figlioSX(root), a, b); // prima di effettuare la stampa arrivo all'elemento più piccolo. Stampa a ritroso
    if ((a <= getValue(getItem(getRoot(root)))) && b >= getValue(getItem(getRoot(root))))
    { // se è compreso tra a e b allora lo stampa in modo crescente
        printItem(getItem(getRoot(root)));
        printf("-->");
    }
    printInterval(figlioDX(root), a, b); // controlliamo l'albero destro. li stamperemo progressivamente poichè la chiamata esegue la riga 101 ed effettuare lo stesso contorllo che permette di partitre dal piu piccolo
}

int altezza(Btree b){
    if (emptyBtree(b))
        return 0;
    else
    {
        int l = altezza(figlioSX(b));
        int r = altezza(figlioDX(b));
        if (l > r)
            return l + 1;
        else
            return r + 1;
    }
}

int mediano(BST b, int u, int *i){
    printf("nodes: %d\n", nodeCounter(b));
    if ((*i) = (nodeCounter(b) + 1) / 2)
    {
        if (getValue(getItem(getRoot(b))) == u)
            return 1;
        else
            return 0;
    }
    else
        *i = *i + 1;
    mediano(figlioDX(b), u, i);
    mediano(figlioSX(b), u, i);
}

int nodeCounter(BST b){
    if (emptyBST(b))
        return 0;
    return nodeCounter(figlioSX(b)) + nodeCounter(figlioDX(b)) + 1;
}

int oneChild(BST b){
    if (emptyBST(b))
        return 0;
    else if ((emptyBST(figlioDX(b)) && (!emptyBST(figlioSX(b)))) || (!emptyBST(figlioDX(b)) && (emptyBST(figlioSX(b)))))
        return 1;
    else
        return oneChild(figlioSX(b)) + oneChild(figlioDX(b));
}

int distanceFromLCA(BST b, int x){
    if (emptyBST(b) || getValue(getItem(getRoot(b))) == x)
        return 0;
    else 
        return distanceFromLCA(figlioDX(b), x) + 1;
}

BST LCA(BST b, int x, int y){
    // if (emptyBST(b))
    //     return b;
    if (getValue(getItem(getRoot(b))) > y)
        return LCA(figlioSX(b), x, y);
    if (getValue(getItem(getRoot(b))) < x)
        return LCA(figlioDX(b), x, y);
        
    return b;
}

//trovo antenato comune
//distanza = (distanza x - antenato) + (distanza y - antenato)
int distanceFromNodes(BST b, int x, int y){
    if (emptyBST(b))
        return 0;
    printf("pepe\n");
    BST p = LCA(b, x, y);
    printf("pepe\n");
    printBST(p, 0, altezza(p));
    return distanceFromLCA(b, x) + distanceFromLCA(b, y);
}

int main()
{
    int a[7] = {0, 1, 2, 3, 4, 5, 6};
    // Btree b = newBtree();
    // BST b = inputBtreeFromArray(a, 0, 8);
    // printf("b altezza =  %d\n", altezza(b));
    // printBTree(b, 0, altezza(b));
    // printf("b e' un BST? %d\n", isBst(b));

    // BST b = insertFromArray(a, 7);
    BST b = newBST();
    b = bilanciato(a, 0, 6);
    // printBST(b, 0, altezza(b));
    // printf("is BST? %d\n", isBst(b));
    // // print2D(b);
    // list onLevK = newList();
    // int i = 0;
    // printf("nodi ad altezza 3\n");
    // nodiAltezzaK(b, &onLevK, 3, 1);
    // outputList(onLevK);
    // printf("\n");
    // printf("nodi nell'intervallo 1 - 10 contenuti nel bst\n");
    // printInterval(b, 1, 10);
    // printf("\n");
    // int med = 3;
    // int lv = 0;
    // printf("%d is mediano? %s\n", med, mediano(b, med, &lv) ? "si" : "no");
    int x = 5;
    int y = 6;
    printf("o\n");
    printf("distance (%d, %d) = %d\n", x, y, distanceFromNodes(b, x, y));
    //printf("LCA (%d, %d) = %d\n", x, y, LCA(b, x, y));
    //printf("figli unici: %d\n", oneChild(b));
}