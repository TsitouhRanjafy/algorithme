#include<stdio.h>
#include<stdlib.h>
#include "header.h"

int main(void){
    const signed char etat_initial[] = { 0 };
    const signed char etat_final[] = { 5 };
    const signed char etat[5] = {0,2,3,4,5};
    const char alphabet[2] = {'m', 'a'};

    signed char * etat_actuel;
    char mot[] = "";

    
    printf("-------------- Ensemble d'etat----------------\n");
    printf("------------------ Alphabet ------------------\n");
    printf("----------  Ensemble d'etat initial ----------\n");
    printf("------------ Ensemble d'etat final -----------\n");
    printf("------------Ensemble de transition -----------\n");
    afficheTransition();

    printf("\nEntrer le mot>");scanf("%s",&mot);
    printf("%s",mot);


    

    return EXIT_SUCCESS;
}