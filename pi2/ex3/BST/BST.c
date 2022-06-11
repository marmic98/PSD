#include <stdio.h>
#include <stdlib.h>
#include "item.h"
#include "BST.h"

#define NULLITEM 0

struct node {
    item value;
    struct node *left;
    struct node *right;
};

// BST figlioSX(BST T){
//     if (T)
//         return T->left;
//     else 
//         return NULL;
// }

// BST figlioDX(BST T){
//     if (T)
//         return T->right;
//     else 
//         return NULL;
// }

// item getItem(struct node *N){
//     if (N == NULL)  return NULLITEM;
//     return N->value;
// }

// void setItem(struct node *N, item el){
//     if (N==NULL) 
//         return;
//     N->value = el;  // correttezza di =
// }                             // dipende dal tipo item

// BST getRoot(BST T){
//     return T;
// }

BST newBST (void){
    return NULL;
}
 
int emptyBST (BST T){
    return T == NULL;
}

int contains(BST T, item val){
    if (T == NULL)  return 0;
    if (cmp(val, getItem(T)) == 0)  return 1;
    if (cmp(val, getItem(T)) == 1)
        return (contains(figlioSX(T), val));
    else
        return (contains(figlioDX(T), val));
}

BST insert(BST T, item elem){       
    if (T==NULL)    
        return creaFoglia(elem);
    else if (cmp(elem, getItem(T)) == 1)
        T->left = insert(T->left, elem);
    else if (cmp(getItem(T), elem) == 1)
        T->right = insert(T->right, elem);
    return T;
}
//  deve essere usata sempre nel modo
//   bst = insert(bst, elem);

BST creaFoglia(item elem){       
    struct node *N;
    N = malloc (sizeof(struct node));
    if (N == NULL)   return NULL;
    setItem (N, elem);
    N -> left = NULL;
    N -> right = NULL;
    return N;
}

struct node * minValue(struct node* node){
    struct node* current = node;
    while (current->left != NULL)
        current = current->left;
    return current;
}


struct node* deleteNode(struct node* root, item key){
    if (root == NULL) return root;
 
    if (cmp(key, root->value) == 1)
        root->left = deleteNode(root->left, key);
    else if (cmp(root->value, key) == 1)
        root->right = deleteNode(root->right, key);
 
    else{
        if (root->left == NULL){
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL){
            struct node *temp = root->left;
            free(root);
            return temp;
        }
        struct node* temp = minValue(root->right);
        root->value = temp->value;
 
        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->value);
    }
    return root;
}
