#include<stdio.h>
#include<stdlib.h>

#define STB_DS_IMPLEMENTATION
#include "lib/stb_ds.h"

void cs_append(char *c,char *new_string,size_t limit);

int main(){

    char c[12] = {'T', 'h', 'e', ' ', 'o', 'r', 'i', 'g', 'i', 'n', 'a', 'l'};

    char *newString = NULL;
    cs_append(c,newString,12);
    return 0;
}

void cs_append(char *c,char *new_string,size_t limit){
    new_string = NULL;
    new_string = malloc(sizeof(char) * (limit + 1));
    if (new_string == NULL) exit(1);

    for (size_t i = 0; i < limit; ++i){
        *(*(&new_string) + i) = c[i];
    }
    *(*(&new_string) + limit) = '\0';
    printf("\n%s",new_string);
    free(new_string);
}