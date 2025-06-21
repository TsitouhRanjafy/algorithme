#include<stdio.h>
#include<string.h>
#include<stdint.h>
#include<stdbool.h>


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
void swap(Tokens *a, Tokens *b);


int main(){
    
    const char *text = "aaabdaaabac";
    uint32_t CURRENT_AVAILABLE_TOKEN_RENDER = 126;
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
    for (uint32_t i = 0; i < 256; ++i) 
        arrput(pairs.items,((Pair) { .l = i, .r = 0 }));
    pairs.count = 256;
    pairs.capacity = sizeof(Pair);   

    // append text[i] in tokens_in
    for (size_t i = 0; i < text_size; ++i) 
        arrput(tokens_in.items,text[i]);
    tokens_in.count = text_size;
    tokens_in.capacity = sizeof(text[0]);


    printf("\t %0.4zu :",tokens_in.count);
    render_tokens(pairs,tokens_in);
    printf("\n");
    for (bool i = true; i == 1;){
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
        if (freq[max_index].value <= 1) {
            printf("\n\t!Compression is done!");
            break;
        }

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
                arrput(tokens_out.items,CURRENT_AVAILABLE_TOKEN_RENDER);
                pairs.items[CURRENT_AVAILABLE_TOKEN_RENDER] = pair;
                i += 2;
                continue;
            }
            arrput(tokens_out.items,(uint32_t)tokens_in.items[i]);
            i += 1;
        } 

        // print the text tokenized
        printf("\t %0.4zu :",tokens_out.count);
        render_tokens(pairs,tokens_out);     
        
        // print the dico
        printf("\t DICO: {\n");
        for (size_t i = 126; i <= CURRENT_AVAILABLE_TOKEN_RENDER; ++i){
            printf("\t\t%u => (%u,%u),\n",i,pairs.items[i].l,pairs.items[i].r);
        }
        printf("\t       }\n\n");
        
        swap(&tokens_in,&tokens_out);
        hmfree(freq);
        CURRENT_AVAILABLE_TOKEN_RENDER += 1;
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
        if (token < 32 || token > 256)
            printf("\nError: token = %u, except `token >= 32 && token <= 256`\n",token);
        assert(token >= 32 && token <= 256);
        if (pairs.items[token].l == token){
            printf("%c",token);
        } else {
            printf("[%u]",token);
        }
    }
    printf("\n");
}

void swap(Tokens *a, Tokens *b){
    arrfree((*(*(&a))).items);
    (*(*(&a))).items = NULL;
    for (size_t i = 0; i < (*(*(&b))).count; ++i)
        arrput((*(*(&a))).items,(*(*(&b))).items[i]);
    (*(*(&a))).count = (*(*(&b))).count;
    arrfree((*(*(&b))).items);
    (*(*(&b))).items = NULL;
    (*(*(&b))).count = 0;
}