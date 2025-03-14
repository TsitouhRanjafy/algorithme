#include<stdio.h>
#include<stdlib.h>
#include "header.h"

int main(void){
    signed char * etat_actuel;
    etat_actuel = transition(3,'a');
    
    printf("-------------- Ensemble d'etat----------------\n");
    printf("------------------ Alphabet ------------------\n");
    printf("----------  Ensemble d'etat initial ----------\n");
    printf("------------ Ensemble d'etat final -----------\n");
    printf("------------Ensemble de transition -----------\n");
    afficheTransition();


    

    return EXIT_SUCCESS;
}