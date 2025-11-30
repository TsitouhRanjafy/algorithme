#include <stdio.h>
#include <stdlib.h>

int *merge(int *tab1, int *tab2, int n, int m);


int main(){
    int t1[3] = {1,6,28};
    int t2[4] = {2,7,90,300};
    int *newTab = merge(t1, t2, sizeof(t1)/sizeof(t1[0]), sizeof(t2)/sizeof(t2[0]));
    for(int i = 0; i < 7; i++){
        printf("%d   ", newTab[i]);
    }
    free(newTab);
    return 0;
}

int *merge(int *tab1, int *tab2, int n, int m){
    int * tab = malloc((n + m) * sizeof(int));
    if (tab == NULL) exit(0);

    int i = 0,j = 0,k = 0;
    while (i < n && j < n) {
        if (tab1[i] < tab2[j]) {
            tab[k] = tab1[i];
            k++;
            i++;
        } else {
            tab[k] = tab2[j];
            k++;
            j++;
        }
    }

    while (i < n) {
        tab[k] = tab1[i];
        k++;
        i++;
    }

    while (j < m) {
        tab[k] = tab2[j];
        k++;
        j++;
    }
    return tab;
}
        