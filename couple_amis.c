#include <stdio.h>
#include <stdlib.h>
#include<math.h>


int sommeDiv(int m){
    int p, q, i, somme = 1;
    // le nombre de  diviseurs de m est toujours superieur de la partie entiers de son ((sqrt() * 2) + 1)
    for (i= 2;i<=sqrt(m); i++){
        q = m % i ;
        if (q == 0){
            //si:   12 |2   alors,on a que 12 est divisible par 2 et 6
            //     -12 |--
            //         |6
            //      ___|
            //       0
            p = m/i;
            somme +=p;
            // p et i doivent different
            //comme si:   4  |2   on repete pas 2 dans l'ensemble de somme
            //           -4  |--
            //               |2
            //            ___|
            //             0
            if (p != i) somme +=i;
        }
    }
    return somme;
}

int main()
{
    //i et j donc couple donc:
    int n,i,j;
    printf(" Entrer n:");scanf("%d",&n);
    for (i=1;i<=n;i++){
        // si j est le somme de diviseurs i
        j = sommeDiv(i);
        if (j <= n ){
            // i doit être le somme de diviseurs le somme de j, mais i et j sont different
            if ((sommeDiv(j) == i) && (j != i)){
                printf(" %d - %d\n\n",i,j);
                i = j+1; // essayer de l'enlever
            }
        }
    }
    return 0;
}