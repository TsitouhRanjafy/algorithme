
#include "stri.h"

int main(){

    char *string[] = {"ofg","ofg", "ofz","ofa", "oca"};
    char *string2[] = {
    "alpha", "zulu", "delta", "bravo", "echo",
    "foxtrot", "golf", "hotel", "india", "juliet",
    "kilo", "lima", "mike", "november", "oscar",
    "papa", "quebec", "romeo", "sierra", "tango"
    };

    sprint(string,sizeof(string) / sizeof(string[0]));
    stri(string,sizeof(string) / sizeof(string[0]),3);
    sprint(string,sizeof(string) / sizeof(string[0]));

    printf("\n");

    sprint(string2,(sizeof(string2) / sizeof(string2[0])));
    stri(string2,(sizeof(string2) / sizeof(string2[0])),4);
    sprint(string2,(sizeof(string2) / sizeof(string2[0])));
    
    return 0;
}




