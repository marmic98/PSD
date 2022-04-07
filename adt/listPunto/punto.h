typedef struct pnt* punto;

punto creaPunto(float x, float y);
float ascissa(punto p);
float ordinata(punto p);
float distanza(punto p1, punto p2);
void printPunto(punto p);
int equal(punto p1, punto p2);
int lessx(punto p1, punto p2);
int lessy(punto p1, punto p2);
void swapPunto(punto* a, punto* b);