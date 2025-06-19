#ifndef LIB_H
#define LIB_H


extern unsigned char verifier(signed char * etat_verifier,signed char * etat_actuel,int cpt,int etat_final);
extern signed char* transition(unsigned char i,char s,signed char* etat_verifier);

#endif