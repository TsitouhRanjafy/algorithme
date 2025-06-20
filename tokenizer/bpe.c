#include<stdio.h>
#include<string.h>
#include<stddef.h>
#include<stdlib.h>
#include<stdbool.h>

#define STB_DS_IMPLEMENTATION
#include "stb_ds.h"


typedef struct {
    char pair[2];
} Pair;

typedef struct {
    Pair key;
    size_t value;
} Freq;

typedef struct {
    Freq *items;
    size_t count;
    size_t capacity;
} Freqs;

Freq *freq = NULL;

void hmprint(const Freq *fred);
int compare_freq(const void *a, const void *b);

int main(){

    const char *text = "lorem ispmm lorem blabldfz zp mdecmmvvr cv d dhze dblabl dla df a mmd ak";
    size_t text_size = strlen(text);

    for (size_t i = 0; i < text_size; ++i){
        Pair key = {
            {text[i], text[i + 1]}
        };

        ptrdiff_t index = hmgeti(freq,key);
        if (index < 0) hmput(freq,key,1);
        else freq[index].value += 1;    
    }

    Freqs sorted_freqs = {
        .items = NULL,
        .count = 0,
        .capacity = 0
    }; // ou Freqs sorted_freqs = 0
    sorted_freqs.items = freq;    
    sorted_freqs.count = hmlen(freq);
    sorted_freqs.capacity = sizeof(freq[0]);
    
    qsort(sorted_freqs.items,sorted_freqs.count,sorted_freqs.capacity,compare_freq);
    hmprint(sorted_freqs.items);

    return 0;
}

void hmprint(const Freq *fred){
    for (size_t i = 0;i < hmlen(freq); ++i){
        printf("%s => %d\n",freq[i].key.pair,freq[i].value);
    }
}

int compare_freq(const void *a, const void *b){
    /*
    const Freq *freq_a = a;
    const Freq *freq_b = b;
    */
    return ((*(Freq *)b).value - (*(Freq *)a).value );
}
