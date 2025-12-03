#include <stdio.h>
#include <stdlib.h>


int *merge(int *tab1, int tab1Size, int n, int *tab2, int tab2Size, int m);


int main(){
    int t1[3] = {1, 8, 5};
    int n = 3, m = 0;
    int t2[1] = {9};
    int *newTab = merge(t1, sizeof(t1)/sizeof(t1[0]), n, t2, sizeof(t2)/sizeof(t2[0]), m);
    for(int i = 0; i < n+m; i++) printf("%d   ", newTab[i]);
    free(newTab);
    return 0;
}

int *merge(int *tab1, int tab1Size, int n, int *tab2, int tab2Size, int m){
    if (n > tab1Size || m > tab2Size || n < 0 || m < 0) return NULL;
    
    int * tab = malloc((n + m) * sizeof(int));
    if (tab == NULL) return NULL;
    
    int i = 0,j = 0,k = 0;
    while (i < n && j < m) {
        if (tab1[i] < tab2[j])
            tab[k++] = tab1[i++];
        else
            tab[k++] = tab2[j++];
    }

    while (i < n) tab[k++] = tab1[i++];
    while (j < m) tab[k++] = tab2[j++];
    
    return tab;
}

