typedef struct lbr* libro;

libro newLibro(char* titolo, char* editore, float prezzo, int anno);
char* titolo(libro l);
char* editore (libro l);
float prezzo(libro l);
int anno(libro l);
float scontaPrezzo(libro* l, float sconto);
void aggiornaAnno(libro* l, int annoNew);
void outputLibro(libro l);