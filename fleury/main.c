#include<stdio.h>
#define DFS_IMPLEMENTATION
#include "graph.h"

void printGraph(KV_ITEM *adj, size_t *node, size_t node_n);


int main(){
    KV_ITEM *adj = NULL;
    size_t node[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19};
    // size_t node[] = {0,1,2,3,4};
    size_t node_n = sizeof(node) / sizeof(node[0]);
    
    
    // // init graph
    // size_t *item = NULL;
    // arr_put(&item,1);
    // hm_put(&adj, 0, item);

    // item = NULL;
    // arr_put(&item,0);
    // hm_put(&adj, 1, item);

    // init graph
    size_t *item = NULL;

    item = NULL;
    arr_put(&item, 1);
    hm_put(&adj, 0, item);

    item = NULL;
    arr_put(&item, 0);
    arr_put(&item, 2);
    hm_put(&adj, 1, item);

    item = NULL;
    arr_put(&item, 1);
    arr_put(&item, 3);
    hm_put(&adj, 2, item);

    item = NULL;
    arr_put(&item, 2);
    arr_put(&item, 4);
    hm_put(&adj, 3, item);

    item = NULL;
    arr_put(&item, 3);
    arr_put(&item, 5);
    hm_put(&adj, 4, item);

    item = NULL;
    arr_put(&item, 4);
    arr_put(&item, 6);
    arr_put(&item, 9);
    hm_put(&adj, 5, item);

    item = NULL;
    arr_put(&item, 5);
    arr_put(&item, 7);
    arr_put(&item, 10);
    hm_put(&adj, 6, item);

    item = NULL;
    arr_put(&item, 6);
    arr_put(&item, 8);
    arr_put(&item, 11);
    hm_put(&adj, 7, item);

    item = NULL;
    arr_put(&item, 7);
    hm_put(&adj, 8, item);

    item = NULL;
    arr_put(&item, 5);
    arr_put(&item, 12);
    arr_put(&item, 10);
    hm_put(&adj, 9, item);

    item = NULL;
    arr_put(&item, 9);
    arr_put(&item, 6);
    arr_put(&item, 11);
    arr_put(&item, 13);
    hm_put(&adj, 10, item);

    item = NULL;
    arr_put(&item, 7);
    arr_put(&item, 14);
    arr_put(&item, 10);
    hm_put(&adj, 11, item);

    item = NULL;
    arr_put(&item, 9);
    arr_put(&item, 13);
    arr_put(&item, 16);
    hm_put(&adj, 12, item);

    item = NULL;
    arr_put(&item, 10);
    arr_put(&item, 12);
    arr_put(&item, 17);
    arr_put(&item, 14);
    hm_put(&adj, 13, item);

    item = NULL;
    arr_put(&item, 11);
    arr_put(&item, 13);
    arr_put(&item, 18);
    arr_put(&item, 15);
    hm_put(&adj, 14, item);

    item = NULL;
    arr_put(&item, 14);
    arr_put(&item, 19);
    hm_put(&adj, 15, item);

    item = NULL;
    arr_put(&item, 12);
    arr_put(&item, 17);
    hm_put(&adj, 16, item);

    item = NULL;
    arr_put(&item, 18);
    arr_put(&item, 13);
    arr_put(&item, 16);
    hm_put(&adj, 17, item);

    item = NULL;
    arr_put(&item, 14);
    arr_put(&item, 17);
    arr_put(&item, 19);
    hm_put(&adj, 18, item);

    item = NULL;
    arr_put(&item, 15);
    arr_put(&item, 18);
    hm_put(&adj, 19, item);



    printf(" adjacent: \n");
    printGraph(adj, node, node_n);
    printf("\n\n");

    
    size_t *euleur_chemin = EulerPathByFleury(adj, node, node_n);
    printf(" euler chemin/circuit: %u\n", arrlen(euleur_chemin));
    for (size_t i = 0; i < arr_len(euleur_chemin); i++){
        printf(" %u",euleur_chemin[i]);
    }
    
    
    for (size_t i = 0; i <= 19; i++){
        size_t *hamiltonien_chemin = HamiltonienPathByFleury(adj, node, node_n, i);
        printf("\n hamiltonien chemin: %u\n",arrlen(hamiltonien_chemin));
        for (size_t i = 0; i < arr_len(hamiltonien_chemin); i++){
            printf(" %u",hamiltonien_chemin[i]);
        }
        arr_free(&hamiltonien_chemin);
        printf("\n");
    }
    

    free_graph(&adj);
    arr_free(&euleur_chemin);
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