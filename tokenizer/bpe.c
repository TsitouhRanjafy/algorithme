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
void render_tokens(Pairs pairs, Tokens tokens);

int main(){
    
    const char *text = "aaabdaaabac";
    const char *TOKEN_V ="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    size_t TOKEN_V_AVAILABLE = strlen(TOKEN_V);
    size_t text_size = strlen(text);
    Freqs sorted_freqs = {
        .items = NULL,
        .count = 0,
        .capacity = 0
    }; // ou Freqs sorted_freqs = {0}
    Pairs pairs = {0};
    Tokens tokens_in = {0};
    Tokens tokens_out = {0};

    // append default pairing
    for (uint32_t i = 0; i < 126; ++i) 
        arrput(pairs.items,((Pair) { .l = i, .r = 0 }));
    pairs.count = 126;
    pairs.capacity = sizeof(Pair);   

    // append text[i] in tokens_in
    for (size_t i = 0; i < text_size; ++i) 
        arrput(tokens_in.items,text[i]);
    tokens_in.count = text_size;
    tokens_in.capacity = sizeof(text[0]);


    printf("\t %0.9zu :",tokens_in.count);
    render_tokens(pairs,tokens_in);
    printf("\n");
    for (size_t i = 0; i < 2; ++i){
        // append all pairing freqency to freq
        for (size_t i = 0; i < tokens_in.count - 1; ++i){
            Pair key = {
                .l = tokens_in.items[i], 
                .r = tokens_in.items[i + 1]
            };
    
            ptrdiff_t index = hmgeti(freq,key);
            if (index < 0) hmput(freq,key,1);
            else freq[index].value += 1;    
        }

        // search the index of most freqency pairing
        size_t max_index = 0;
        for (size_t i = 1; i < hmlen(freq); ++i)
            if (freq[i].value > freq[max_index].value)
                max_index = i;
        printf(" most freq: (%u, %u) => %zu\n",freq[max_index].key.l,freq[max_index].key.r,freq[max_index].value);

        // append the tokens_out by tokens_in with replce the most freqency token to TOKEN_V
        for (size_t i = 0; i < tokens_in.count;){
            tokens_out.count += 1;
            if ((i + 1) >= tokens_in.count - 1){
                arrput(tokens_out.items,tokens_in.items[i]);
                i += 1;
                continue;
            }
            Pair pair = { .l = tokens_in.items[i], .r = tokens_in.items[i + 1]};
            if (memcmp(&pair,&freq[max_index].key,sizeof(Pair)) == 0) {
                arrput(tokens_out.items,(uint32_t)TOKEN_V[TOKEN_V_AVAILABLE - 1]);
                pairs.items[(uint32_t)TOKEN_V[TOKEN_V_AVAILABLE - 1]] = pair;
                i += 2;
                continue;
            }
            arrput(tokens_out.items,(uint32_t)tokens_in.items[i]);
            i += 1;
        } 

        // print the text tokenized
        printf("\t %0.9zu :",tokens_out.count);
        render_tokens(pairs,tokens_out);
        TOKEN_V_AVAILABLE -= 1;

        // print the dico
        printf("\t DICO: {");
        for (size_t i = strlen(TOKEN_V) - 1; i > TOKEN_V_AVAILABLE - 1; --i){
            printf("(%c,%c) => %c,",pairs.items[(uint32_t)TOKEN_V[i]].l,pairs.items[(uint32_t)TOKEN_V[i]].r,(uint32_t)TOKEN_V[i]);
        }
        printf("}");

        arrfree(tokens_in.items);
        for (size_t i = 0; i < tokens_out.count; ++i){
            arrput(tokens_in.items,tokens_out.items[i]);
        }
        tokens_in.count = tokens_out.count;
        arrfree(tokens_out.items);
        hmfree(freq);
    }

    hmfree(freq);
    hmfree(sorted_freqs.items);
    arrfree(tokens_in.items);
    arrfree(pairs.items);
    arrfree(tokens_out.items);
    return 0;
}

void hmprint(const Freq *freq){
    for (size_t i = 0;i < hmlen(freq); ++i){
        printf("(%u, %u) => %zu\n",freq[i].key.l,freq[i].key.r,freq[i].value);
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

void render_tokens(Pairs pairs, Tokens tokens){
    for (size_t i = 0; i < tokens.count; ++i){
        uint32_t token = tokens.items[i];
        if (token < 32 || token >= 126){
            printf("\n\nerreur ici: token = %u, ce qui doit être `32 <= token && token < 126'\n",token);
        }
        assert(32 <= token && token < 126);
        printf("%c",token);
        // if (pairs.items[token].l == token){
        // } else {
        //     printf("[%u]",token);
        // }
    }
    printf("\n");
}