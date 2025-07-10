#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

char** findItinerary(char*** tickets, int ticketsSize, int* ticketsColSize, int* returnSize);
char smin(char *a, char *b, size_t l);
void print(char*** tickets, size_t s);
bool containe(size_t *array,size_t n ,size_t s);
size_t stri(char *str[], size_t s, size_t l);


char *t1[] = {"JFK", "SFO"};
char *t2[] = {"JFK", "ATL"};
char *t3[] = {"SFO", "JFK"};
char *t4[] = {"ATL", "AAA"};
char *t5[] = {"AAA", "ATL"};
char *t6[] = {"ATL", "BBB"};
char *t7[] = {"BBB", "ATL"};
char *t8[] = {"ATL", "CCC"};
char *t9[] = {"CCC", "ATL"};
char *t10[] = {"ATL", "DDD"};
char *t11[] = {"DDD", "ATL"};
char *t12[] = {"ATL", "EEE"};
char *t13[] = {"EEE", "ATL"};
char *t14[] = {"ATL", "FFF"};
char *t15[] = {"FFF", "ATL"};
char *t16[] = {"ATL", "GGG"};
char *t17[] = {"GGG", "ATL"};
char *t18[] = {"ATL", "HHH"};
char *t19[] = {"HHH", "ATL"};
char *t20[] = {"ATL", "III"};
char *t21[] = {"III", "ATL"};
char *t22[] = {"ATL", "JJJ"};
char *t23[] = {"JJJ", "ATL"};
char *t24[] = {"ATL", "KKK"};
char *t25[] = {"KKK", "ATL"};
char *t26[] = {"ATL", "LLL"};
char *t27[] = {"LLL", "ATL"};
char *t28[] = {"ATL", "MMM"};
char *t29[] = {"MMM", "ATL"};
char *t30[] = {"ATL", "NNN"};
char *t31[] = {"NNN", "ATL"};




int main(){
    // char *t1[] = {"JFK","SFO"};
    // char *t2[] = {"JFK","ATL"};
    // char *t3[] = {"SFO","ATL"};
    // char *t4[] = {"ATL","JFK"};
    // char *t5[] = {"ATL","SFO"};

    char **tickets[] = {
    t1, t2, t3, t4, t5, t6, t7, t8, t9, t10,
    t11, t12, t13, t14, t15, t16, t17, t18, t19, t20,
    t21, t22, t23, t24, t25, t26, t27, t28, t29, t30,
    t31 // Finir avec NULL si ta fonction de print dépend de ça
    };

    size_t len = sizeof(tickets) / sizeof(tickets[0]);
    int col = 2;
    int a = 3;
    int *returnSize = malloc(sizeof(int));
    print(tickets, len);
    char **result = findItinerary(tickets, len, &col, returnSize);
    
    
    printf("%u \n",returnSize);
    for (size_t i = 0; i < (*returnSize); i++){
        printf("%s ",result[i]);
    }
    free(result);
    free(returnSize);
    return 0;
}


void go(char*** tickets,int ticketsSize,size_t *outIndex, size_t *currentOutIndex, char** newTickets, int *currentNewTicketIndex, char **tmp, size_t *currentTmpIndex, size_t *indexTmp, size_t *parts, size_t *currentPartsIndex){
    
    while (*currentOutIndex != ticketsSize){
        for (size_t i = 0; i < ticketsSize; i++){
            if (containe(outIndex, i, *currentOutIndex)) continue;
            if (strcmp(tickets[i][0], newTickets[*currentNewTicketIndex - 1]) == 0){
                tmp[*currentTmpIndex] = tickets[i][1];
                indexTmp[*currentTmpIndex] = i;
                (*currentTmpIndex)++;
            }
        }
        if ((*currentTmpIndex == 0) ) {
            bool exist = 0;
            for (size_t i = 0; i < ticketsSize; ++i){
                if (containe(outIndex, i, *currentOutIndex)) continue;
                if (strcmp(tickets[i][0], "JFK") == 0) exist = 1;
            }
            if (exist == 1) {
                newTickets[*currentNewTicketIndex] = "JFK";
                parts[*currentPartsIndex] = *currentNewTicketIndex;
                (*currentNewTicketIndex)++;
                (*currentPartsIndex)++; 
            } else {
                break;
            };
        } else {
            size_t i_tmp = stri(tmp,*currentTmpIndex,3);
            outIndex[*currentOutIndex] = indexTmp[i_tmp];
            (*currentOutIndex)++;
            assert(*currentTmpIndex > 0);
            newTickets[*currentNewTicketIndex] = tmp[0];
            (*currentNewTicketIndex)++;
            *currentTmpIndex = 0;
        }
    };
}

char** findItinerary(char*** tickets, int ticketsSize, int* ticketsColSize, int* returnSize) {
    size_t outIndex[ticketsSize];
    size_t currentOutIndex = 0;
    char *newTickets[ticketsSize * 2];
    newTickets[0] = "JFK";
    int currentNewTicketIndex = 1;
    char *tmp[ticketsSize];
    size_t indexTmp[ticketsSize];
    size_t currentTmpIndex = 0;
    size_t parts[ticketsSize];
    size_t currentPartsIndex = 0;

    go(tickets,ticketsSize,outIndex,&currentOutIndex,newTickets,&currentNewTicketIndex,tmp,&currentTmpIndex,indexTmp,parts,&currentPartsIndex);

    char **result = malloc(sizeof(char *) * currentNewTicketIndex);
    if (currentPartsIndex == 1){
        if (strcmp(newTickets[0], newTickets[currentNewTicketIndex - 1]) == 0){
            printf("\n parts two: %u\n",parts[0]);
            for (size_t i = 0, j = parts[0]; j < currentNewTicketIndex - 1;++i, ++j){
                result[i] = newTickets[j];
            }
            for (size_t i = 0, j = currentNewTicketIndex - parts[0] - 1; i < parts[0];++j, ++i){
                result[j] = newTickets[i];
            }
            *returnSize = currentNewTicketIndex - 1;
        }
    } else {
        for (size_t i = 0; i < currentNewTicketIndex; ++i){
            result[i] = newTickets[i];
        }
        *returnSize = currentNewTicketIndex;
    }

    return result;  
}




bool containe(size_t *array,size_t n ,size_t s){
    for (size_t i = 0; i < s; i++) if (array[i] == n) return true;
    return false;
}

void print(char ***tickets, size_t s){
    printf("[");
    for (size_t i = 0; i < s; i++){
        if (i != (s - 1)) printf("[\"%s\", \"%s\"],",tickets[i][0], tickets[i][1]);
        else printf("[\"%s\", \"%s\"]",tickets[i][0], tickets[i][1]);
    }
    printf("]\n");
}

void swap(char *s[], size_t a, size_t b){
    char *tmp = s[a];
    s[a] = s[b];
    s[b] = tmp;
}

// if a < b, return negatif
// if a > b, return positif
// if a == b, return 0
char cmin(char a, char b){
    unsigned char n = (a >= 97) ? (a - 32) : a; 
    unsigned char m = (b >= 97) ? (b - 32) : b;
    assert((n <= 90) && (n >= 65));
    assert((m <= 90) && (m >= 65));
    return (n - m);
}


// return negatif if a < b,
// return positif if a > b,
// return 0 if a == b
char smin(char *a, char *b, size_t l){
    for (size_t i = 0; i < l; ++i){
        if (cmin(a[i], b[i]) < 0) return -1;
        if (cmin(a[i], b[i]) > 0) return 1;
    }
    return 0;
}


// tri the array of string and return the index of min element in the input array
size_t stri(char *str[], size_t s, size_t l){ 
    size_t lastIndexOfMin = 0;
    if (s == 1) return lastIndexOfMin; 
    for (size_t i = 0; i < s; ++i){
        size_t i_min = i;
        for (size_t j = i + 1; j < s; ++j){
            if (smin(str[i_min], str[j], l) > 0) {
                i_min = j;
                if (i == 0) lastIndexOfMin = i_min;
            }
        }
        swap(str, i, i_min);
    }
    return lastIndexOfMin;
}


// print array of string
void sprint(char *str[], size_t s){
    printf("\n [");
    for (size_t i = 0; i < s; ++i){
        if (i != (s - 1)) printf(" \"%s\",",str[i]);
        else printf(" \"%s\"",str[i]);
    }
    printf("]\n");
}

