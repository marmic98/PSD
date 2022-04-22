typedef struct song* item;

item createItem(char* nome, char* artista, int durata);
void printItem (item i);
int sameArtist(char* a, char* b);
int getDurata(item i);
char* getArtista(item i);
char* getNome(item i);