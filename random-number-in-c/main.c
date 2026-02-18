#include<stdio.h>
#include<stdlib.h>
#include<time.h>


int generateRandomNumber(int min, int max);

int main(){

    // printf("%d",time(NULL)); // time now, in timestamp
    printf("%d",generateRandomNumber(600,800));
    return EXIT_SUCCESS;
}

int generateRandomNumber(int min, int max){
    if (min > max) {
        min += max;
        max = min - max;
        min -= max;
    }
    srand(time(NULL));
    return (rand() % (max - min + 1)) + min; // formule 
}