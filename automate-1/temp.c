#include<stdio.h>

signed char temp[] = { -1 };
unsigned cpt = 0;


void insert(signed char* etat){
    for (unsigned i = 0; (*(&etat[i]) != -1) && (i < 2);i++){
        temp[cpt++] = *(&etat[i]);
    }
}

void reinitialise(){
    cpt = 0;
}



