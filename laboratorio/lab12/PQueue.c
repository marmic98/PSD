#include <stdio.h>
#include <stdlib.h>
#include "PQueue.h"
#include "item.h"
#define MAXPQ 50

struct c_PQ {
    item vet[MAXPQ];
    int numel;
};

static void scendi (PQueue q);
static void sali (PQueue q);

PQueue newPQ(void){
    PQueue q;
    q = malloc (sizeof(struct c_PQ));
    if (q == NULL) return NULL;
    q->numel = 0;
    return q;
}

int emptyPQ(PQueue q){
    if (!q)  return 1;
    return q->numel == 0;
}

item getMax(PQueue q){
    return q->vet[1];
    // NON VERIFICA LA
    // PRECONDIZIONE
    // LA CODA NON PUO’
	// ESSERE VUOTA
}

item getMin(PQueue q){
    return q->vet[q->numel];
    // NON VERIFICA LA
    // PRECONDIZIONE
    // LA CODA NON PUO’
	// ESSERE VUOTA
}

int deleteMax(PQueue q){
    if (!q || q->numel==0) 
		return 0;   // CODA VUOTA

    q->vet[1] = q->vet[q->numel];  //SPOSTO L’ULTIMO ELEMENTO
    q->numel --;                               // IN POSIZIONE 1

    scendi(q);      // RIAGGIUSTO LO HEAP SCENDENDO

    return 1;
} 


static void scendi (PQueue q){
	int temp, n=q->numel, i=1, pos;

	while (1){
		if (2*i+1 <= n)               // IL NODO CORRENTE HA 2 FIGLI
			pos =  (q->vet[i*2] > q->vet[i*2+1])  ?   i*2  :   i*2+1;

		else  if (2*i <= n)          // IL NODO CORRENTE HA 1 FIGLIO
			pos = 2*i;
		else  
			break;                  // IL NODO CORRENTE NON HA FIGLI
			
		if (q->vet[pos] > q->vet[i]){     // SCAMBIO LE CHIAVI E PROSEGUO 
			temp = q->vet[i];
			q->vet[i] = q->vet[pos];
			q->vet[pos] = temp;
			i = pos;
		}
		else
			break;   // NON CI SONO PIU’ SCAMBI DA FARE, MI FERMO 
	}
}

int insert (PQueue q, item i){

    if (!q || q->numel==MAXPQ) return 0; // CODA PIENA 

    q->numel++;
    q->vet[q->numel] = i;   // INSERISCI IN ULTIMA POSIZIONE
     
    sali(q);     // AGGIUSTA LO HEAP RISALENDO

    return 1;
}

static void sali (PQueue q){
	int temp, pos=q->numel, i=pos/2;

	while (pos>1){
		if (q->vet[pos] > q->vet[i]){
		temp = q->vet[i];
		q->vet[i] = q->vet[pos];
		q->vet[pos] = temp;
		pos = i;
		i = pos/2;
		}
		
		else
			break;
	}
}

