
#include "stri.h"

int main(){

    char *string[] = {"ofg", "ofz","ofa", "oca"};
    char *string2[] = {
    "alpha", "zulu", "delta", "bravo", "echo",
    "foxtrot", "golf", "hotel", "india", "juliet",
    "kilo", "lima", "mike", "november", "oscar",
    "papa", "quebec", "romeo", "sierra", "tango"
    };

    sprint(string,4);
    stri(string,4,3);
    sprint(string,4);

    printf("\n");

    sprint(string2,(sizeof(string2) / sizeof(string2[0])));
    stri(string2,(sizeof(string2) / sizeof(string2[0])),4);
    sprint(string2,(sizeof(string2) / sizeof(string2[0])));
    
    return 0;
}




