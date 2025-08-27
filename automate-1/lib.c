#include<stdio.h>


signed char* transition(unsigned char i,char s,signed char* etat_verifier){
    
    static signed char etat[] = { -1,-1 };

    switch (s){
    case 'm':
        switch (i){
        case 0:
            etat[0] = 2;
            etat_verifier[0] = 0;
            break;
        case 3:
            etat[0] = 4;
            etat[1] = 5;
            etat_verifier[2] = 0;
            break;
        default:
            etat[0] = -1;
            etat[1] = -1;
            break;
        }
        break;
    case 'a':
        switch (i){
        case 2:
            etat[0] = 3;
            etat_verifier[1] = 0;
            break;
        case 4:
            etat[0] = 3;
            etat[1] = 5;
            etat_verifier[3] = 0;
            break;
        default:
            etat[0] = -1;
            etat[1] = -1;
            break;
        }
        break;
    default:
        etat[0] = -1;
        etat[1] = -1;
        break;
    }
    return etat;
}


unsigned char verified(signed char * etat_verifier,int cpt){
    for (unsigned i = 0; i < cpt;i++){
        if (etat_verifier[i] == -1){
            return 0;
        }
    }
    return 1;
}

unsigned char verifier(signed char * etat_verifier,signed char * etat_actuel,int cpt,int etat_final){
    if (verified(etat_verifier,cpt) != 1) return 0;

    for (unsigned i = 0; i < 2; i ++){
        if (etat_actuel[i] == etat_final) return 1;
    }
    return 0;
}

