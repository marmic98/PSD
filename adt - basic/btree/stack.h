#include "item.h"

typedef struct cStack* stack;

stack newStack();
int sizeStack(stack s);
int emptyList(stack s);
int push(item e, stack s);
int pop(stack s);
item top(stack s);

void printStack(stack s);
stack reverseStack(stack s);
stack cloneStack(stack s);

//tipi dato di riferimento: stack "sequenza di elementi gestiti con politica FIFO". Gli elementi dello stack sono di tipo generico item
//Specifica sintattica: inputStack(unsigned) -> stack
//Specifica semantica: inputStack(n) -> s
	//pre: n > 0
	//post: s = <a1, a2, a3, ..., an>
//La funzione prende in input il numero di elementi da voler inserire nello stack il quale deve essere >= 0. Viene restituita una stack valorizzato con i valori presi in input da tastiera
stack inputStack(unsigned int n);

//tipi dato di riferimento: stack "sequenza di elementi gestiti con politica FIFO". Gli elementi dello stack sono di tipo generico item
//Specifica sintattica: reverseStack(stack) -> stack
//Specifica semantica: inputStack(s) -> s1
	//pre: s deve esistere
	//post: s = <a1, a2, a3, ..., an> && s1 = <an, ..., a3, a2, a1>
//La funzione prende in input una stack, già inizializzata, e restituisce uno stack s1 pari all'inverso di s. La funzione non altera s
stack reverseStack(stack s);
//idea progettuale: prendere tutti gli item di s e collocarli in due stack, una è la stack che verrà restituita mentre l'altra sarà di appoggio e servirà a rivalorizzare s dopo averla scandita poichè la visita di uno stack prevede la modifica permante di essa

//tipi dato di riferimento: stack "sequenza di elementi gestiti con politica FIFO". Gli elementi dello stack sono di tipo generico item
//Specifica sintattica: merge(stack, stack) -> stack
//Specifica semantica: merge(s1, s2) -> s3
	//pre: s1 e s2 devono esistere
	//post: se una delle due stack è vuota allora s3 = s non vuota
	//		se s1 e s2 sono vuote allora s3 vuota anche essa
	// 		s1 = <a1, a2, a3, ..., an> && s2 = <b1, ...,bn> avrò s3 = <a1,...,an,b1,...,bn>
//La funzione prende in input una stack, già inizializzata, e restituisce uno stack s1 pari all'inverso di s. La funzione non altera s
stack merge(stack s1, stack s2);
//idea progettuale: Facciamo i controlli sullo stato di riempimento di s1 e s2 nel rispetto delle post condizioni
//					Viene effettuata l'append di s2 a s1 quindi progettualemtne andiamo a inserire gli elementi di s1 in s2 avendo cura di ottenre prima s1 invertita in modo da preservare l'ordine di inseriemnto nello stack

//tipi dato di riferimento: stack "sequenza di elementi gestiti con politica FIFO". Gli elementi dello stack sono di tipo generico item
//Specifica sintattica: toDelete(stack, stack) -> stack
//Specifica semantica: toDelete(s1, s2) -> s3
	//pre: s1 e s2 devono esistere
	//post: se una delle due stack è vuota allora s3 = s non vuota
	//		se s1 e s2 sono vuote allora s3 vuota anche essa
	// 		s1 = <a1, a2, a3, ..., an> && s2 = <b1, ...,bn> avrò s3 = <a1,...,an,b1,...,bn>
void deleteItem(stack s, item toDelete);
