#include<stdio.h>
#include<string.h>
#include<stdint.h>


#define STB_DS_IMPLEMENTATION
#include "stb_ds.h"


typedef struct {
    uint32_t l, r;
} Pair;

typedef struct {
    Pair *items;
    size_t count, capacity;
} Pairs;

typedef struct {
    Pair key;
    size_t value;
} Freq;

typedef struct {
    Freq *items;
    size_t count, capacity;
} Freqs;

typedef struct {
    uint32_t *items;
    size_t count, capacity;
} Tokens;

Freq *freq = NULL;

void hmprint(const Freq *fred);
int compare_freq(const void *a, const void *b);
void hmcp(Freq *freq,Freqs *freqs);

int main(){
    
    const char *text = "legzkrbgz krlb gza gzabzeklgze lgzelkf";
    size_t text_size = strlen(text);
    Freqs sorted_freqs = {
        .items = NULL,
        .count = 0,
        .capacity = 0
    }; // ou Freqs sorted_freqs = {0}
    Pairs pairs = {0};
    Tokens tokens = {
        .items = NULL,
        .count = 0,
        .capacity = 0
    };

    for (uint32_t i = 0; i < 256; ++i) arrput(pairs.items,((Pair) { .l = i, .r = 0 }));
    pairs.count = 256;
    pairs.capacity = sizeof(Pair);

    for (size_t i = 0; i < text_size; ++i) arrput(tokens.items,text[i]);
    tokens.count = text_size;
    tokens.capacity = sizeof(text[0]);

    for (size_t i = 0; i < tokens.count - 1; ++i){
        Pair key = {
            .l = tokens.items[i], 
            .r = tokens.items[i + 1]
        };

        ptrdiff_t index = hmgeti(freq,key);
        if (index < 0) hmput(freq,key,1);
        else freq[index].value += 1;    
    }

    // hmcp(freq,&sorted_freqs);
    // sorted_freqs.count = hmlen(freq);
    // sorted_freqs.capacity = sizeof(freq[0]);
    // qsort(sorted_freqs.items,sorted_freqs.count,sorted_freqs.capacity,compare_freq);

    hmfree(freq);
    hmfree(sorted_freqs.items);
    arrfree(tokens.items);
    arrfree(pairs.items);
    return 0;
}

void hmprint(const Freq *freq){
    for (size_t i = 0;i < hmlen(freq); ++i){
        printf("(%u, %u) => %d\n",freq[i].key.l,freq[i].key.r,freq[i].value);
    }
}

int compare_freq(const void *a, const void *b){
    /*
    const Freq *freq_a = a;
    const Freq *freq_b = b;
    */
    return ((*(Freq *)b).value - (*(Freq *)a).value );
}

void hmcp(Freq *freq,Freqs *freqs){
    for (size_t i = 0;i < hmlen(freq); ++i){
        hmput((*(*(&freqs))).items,freq[i].key,freq[i].value);
    }
}
