#include<stdio.h>
#include<string.h>
#include<stddef.h>

#define STB_DS_IMPLEMENTATION
#include "stb_ds.h"

typedef struct {
    char pair[2];
} Pair;

typedef struct {
    Pair key;
    size_t value;
} DICO;

DICO *freq = NULL;

int main(){

    const char *text = "Tsitohaina ispm";
    size_t text_size = strlen(text);

    for (size_t i = 0; i < text_size; ++i){
        Pair key = {
            {text[i], text[i + 1]}
        };

        ptrdiff_t index = hmgeti(freq,key);
        if (index < 0) hmput(freq,key,1);
        else freq[index].value += 1;    
    }

    for (size_t i = 0;i < hmlen(freq); ++i){
        printf("%s => %d\n",freq[i].key.pair,freq[i].value);
    }

    
    
    return 0;
}