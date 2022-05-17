#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include "btree.h"

#define NULLITEM 0
#define COUNT 5

struct node {
    item value;
    struct node *left;
    struct node *right;
};

item getItem(struct node *N){
    if (N == NULL)  
        return NULLITEM;
    return N->value;
}

void setItem(struct node *N, item el){
    if (N==NULL) 
        return;
    N->value = el;
}         


Btree newBtree(void){
     return NULL;
}
 
int emptyBtree(Btree T){
     return T == NULL;
}

struct node *getRoot(Btree T){
    return T;
} 

Btree consBtree(item val, Btree sx, Btree dx){
    struct node *nuovo;
    nuovo = malloc (sizeof(struct node));
    if (nuovo != NULL) {
     	setItem(nuovo, val);
      	nuovo->left = sx;
 	    nuovo->right = dx;
    }
    return nuovo;
}

int addNode(Btree T, item daInserire){
    Btree newNode= consBtree(daInserire, NULL, NULL);
    
    if(T->left == NULL){
        T->left= newNode;
        return 1;
    }
    else if(T->right == NULL){
        T->right== newNode;
        return 1;
    }
    
    return 0;
}

Btree figlioSX(Btree T){
    if (T != NULL)    
	    return  T->left;
    else 
        return NULL;
}

Btree figlioDX(Btree T){
    if (T != NULL)    
	    return  T->right;
    else 
        return NULL;
}

void print2DUtil(struct node *root, int space)//L'ho copiata dal web
{
    // Base case
    if (root == NULL)
        return;
 
    // Increase distance between levels
    space += COUNT;
 
    // Process right child first
    print2DUtil(root->right, space);
 
    // Print current node after space
    // count
    printf("\n");
    for (int i = COUNT; i < space; i++)
        printf(" ");
    printf("%d\n", getValue(root->value));
 
    // Process left child
    print2DUtil(root->left, space);
}
 
// Wrapper over print2DUtil()
void print2D(struct node *root)
{
   // Pass initial space count as 0
   print2DUtil(root, 0);
}
