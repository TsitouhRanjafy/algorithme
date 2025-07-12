/**
 * @file stri.h
 * @brief Utilities for case-insensitive sorting and comparison of strings.
 *
 * This header provides a set of functions to perform a case-insensitive
 * selection sort on an array of strings, comparing only the first `l` characters.
 *
 * Functions include:
 * - `swap`   : Swaps two strings in an array.
 * - `cmin`   : Case-insensitive character comparison (A-Z).
 * - `smin`   : Case-insensitive string comparison up to length `l`.
 * - `stri`   : Sorts an array of strings using selection sort and smin().
 * - `sprint` : Prints an array of strings in a formatted list.
*/


#ifndef STRI_H
#define STRI_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>


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
    assert((n <= 90));
    assert((m <= 90));
    assert((n >= 65));
    assert((m >= 65));
    return (n - m);
}


// return negatif if a < b,
// return positif if a > b,
// return 0 if a == b
char min(char *a, char *b, size_t i,size_t l){
    if (cmin(a[i], b[i]) < 0) return -1;
    if (cmin(a[i], b[i]) > 0) return 1;
    i++;
    if (i < l) min(a,b,i,l);
    else return 0;
}
char smin(char *a, char *b, size_t l){
   return min(a,b,0,l);
}


// tri the array of string
char *stri(char *str[], size_t s, size_t l){ 
    for (size_t i = 0; i < s; ++i){
        size_t i_min = i;
        for (size_t j = i + 1; j < s; ++j)
            if (smin(str[i_min], str[j], l) > 0) i_min = j;
        swap(str, i, i_min);
    }
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

#endif