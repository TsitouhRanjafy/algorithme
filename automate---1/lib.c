#include<stdio.h>

signed char* transition(unsigned char i,char s){
    
    static signed char etat[] = { -1,-1 };
    switch (s){
    case 'm':
        switch (i){
        case 0:
            etat[0] = 2;
            break;
        case 3:
            etat[0] = 4;
            etat[1] = 5;
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
            break;
        case 4:
            etat[0] = 3;
            etat[1] = 5;
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

void afficheTransition(void){
    char alphabet[2] = {'m', 'a'};
    signed char etat[] = { 0,2,3,4,5 };
    
    for (unsigned i = 0;i <= 1;i++){
        for (unsigned j = 0; j <= 4;j++){
            signed char* etat_suivant; 
            etat_suivant = transition(etat[j],alphabet[i]);

            if (*(&etat_suivant[0]) != -1){
                printf("\t%d---%c",etat[j],alphabet[i]);
                printf("--->%d\n",*(&etat_suivant[0]));
            };
            if (*(&etat_suivant[1]) != -1){
                printf("\t%d---%c",etat[j],alphabet[i]);
                printf("--->%d\n",*(&etat_suivant[1]));
            };
        }
    }
}
