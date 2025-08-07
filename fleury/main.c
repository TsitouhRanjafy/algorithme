#include<stdio.h>
#define DFS_IMPLEMENTATION
#include "graph.h"

void printGraph(KV_ITEM *adj, size_t *node, size_t node_n);


int main(){
    KV_ITEM *adj = NULL;
    size_t node[] = {0, 1, 2, 3, 4, 5, 6};
    // size_t node[] = {0,1,2,3,4};
    size_t node_n = sizeof(node) / sizeof(node[0]);
    
    
    size_t *item = NULL;

    item = NULL;
    arr_put(&item, 1);
    hm_put(&adj, 0, item);

    item = NULL;
    arr_put(&item, 0);
    arr_put(&item, 2);
    arr_put(&item, 5);
    hm_put(&adj, 1, item);

    item = NULL;
    arr_put(&item, 1);
    arr_put(&item, 3);
    arr_put(&item, 4);
    hm_put(&adj, 2, item);

    item = NULL;
    arr_put(&item, 2);
    hm_put(&adj, 3, item);

    item = NULL;
    arr_put(&item, 2);
    arr_put(&item, 5);
    arr_put(&item, 6);
    hm_put(&adj, 4, item);

    item = NULL;
    arr_put(&item, 1);
    arr_put(&item, 4);
    hm_put(&adj, 5, item);

    item = NULL;
    arr_put(&item, 4);
    hm_put(&adj, 6, item);



    printf(" adjacent: \n");
    printGraph(adj, node, node_n);
    printf("\n\n");

    
    size_t *euleur_chemin = EulerPathByFleury(adj, node, node_n);
    printf(" euler chemin/circuit: %u\n", arrlen(euleur_chemin));
    for (size_t i = 0; i < arr_len(euleur_chemin); i++){
        printf(" %u",euleur_chemin[i]);
    }
    
    size_t *hamiltonien_chemin = NULL;

    for (size_t origin_i = 0; origin_i < node_n; origin_i++){
        hamiltonien_chemin = HamiltonienPathByFleury(adj, node, node_n, origin_i);
        if (hamiltonien_chemin == NULL) continue;
        printf("\n hamiltonien chemin: %u\n",arrlen(hamiltonien_chemin));
        for (size_t i = 0; i < arr_len(hamiltonien_chemin); i++){
            printf(" %u",hamiltonien_chemin[i]);
        }
        printf("\n");
        arr_free(&hamiltonien_chemin);
        hamiltonien_chemin = NULL;
    }
    
    
    free_graph(&adj);
    arr_free(&euleur_chemin);
    arr_free(&hamiltonien_chemin);
    return 0;
}


void printGraph(KV_ITEM *adj, size_t *node, size_t node_n){
    for (size_t i = 0; i < hmlen(adj); i++){
        printf(" %u: ",node[i]);
        for (size_t j = 0; j < arrlen(hmget(adj,node[i])); j++){
            printf("%u",hmget(adj, node[i])[j]);
        }
        printf("\n");
    }
}