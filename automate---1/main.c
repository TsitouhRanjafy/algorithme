#include<stdio.h>
#include<stdlib.h>
#include "lib.h"
#include "temp.h"

int main(void){
    const signed char etat_final = 5 ;
    const signed char etat[5] = {0,2,3,4,5};
    
    signed char etat_verifier[4] = { 0,-1,-1,-1};
    signed char * etat_actuel;
    unsigned char cpt_etat_actuel = 1;
    char mot[50] = "";
    
    printf("49 caractère max >");scanf("%49s",mot);
    
    signed char init_etat[] = { 0, -1 };
    etat_actuel = init_etat;

    for (unsigned i = 0; mot[i] != 0;i++){
        for (unsigned j = 0; j < cpt_etat_actuel; j++){
            insert(transition(*(&etat_actuel[j]),mot[i],etat_verifier));
        }
        if (cpt == 0) {
            etat_verifier[0] = -1;
            break;
        }
        etat_actuel = temp;
        cpt_etat_actuel = cpt;
        reinitialise();
    }

    printf("\n final: %u\n",verifier(etat_verifier,etat_actuel,4,etat_final));

    return EXIT_SUCCESS;
}