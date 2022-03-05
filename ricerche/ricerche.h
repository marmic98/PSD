int ricercaBinaria(int* a,int item, int len){
    int inizio=0,fine=len-1,centro;
    while(inizio <= fine){
        centro = (inizio+inizio)/2;
        if (a[centro]==item){
            return centro;
        }
         else if (item > a[centro]){
            inizio = centro+1;
        }
        else {
            fine = centro-1;
        }
    }
    return -1;
}

int ricercaLineare(int* a, int len, int item){
    for (int i = 0; i < len; i++){
        if (a[i] == item)
            return i;
    }
    return -1;
}

int ricercaLineareOrd(int* a, int len, int item){
    for (int i = 0; a[i] <= item; i++){
        if (a[i] == item)
            return i;
    }
    return -1;
}