#include<stdio.h>
#define DFS_IMPLEMENTATION
#include "graph.h"

void printGraph(KV_ITEM *adj, size_t *node, size_t node_n);
void fleuryRecNode(KV_ITEM *adj_graph, size_t *connexStatus, size_t *node, size_t node_n, size_t origin, size_t **c);


int main(){
    KV_ITEM *adj = NULL;
    size_t node[] = {0,1,2,3,4,5,6};
    size_t node_n = sizeof(node) / sizeof(node[0]);
    
    
    // init graph
    // adj for 3
    size_t *item = NULL;
    arrput(item,0);
    arrput(item,1);
    hmput(adj,3,item);

    // adj for 0
    item = NULL;
    arrput(item,3);
    arrput(item,4);
    hmput(adj,0,item);
    
    // adj for 1
    item = NULL;
    arrput(item,3);
    arrput(item,4);
    hmput(adj,1,item);
    
    // adj for 4
    item = NULL;
    arrput(item,0);
    arrput(item,1);
    arrput(item,2);
    arrput(item,6);
    hmput(adj,4,item);
    
    // adj for 2
    item = NULL;
    arrput(item,4);
    arrput(item,5);
    hmput(adj,2,item);

    // adj for 6
    item = NULL;
    arrput(item,4);
    arrput(item,5);
    hmput(adj,6,item);

    // adj for 5
    item = NULL;
    arrput(item,2);
    arrput(item,6);
    hmput(adj,5,item);


    printf(" adjacent: \n");
    printGraph(adj, node, node_n);
    printf("\n\n");

    
    size_t *euleur_chemin = EulerPathByFleury(adj, node, node_n);
    printf(" euler chemin/circuit: \n");
    for (size_t i = 0; i < arrlen(euleur_chemin); i++){
        printf(" %u",euleur_chemin[i]);
    }
    
    size_t *hamiltonien_chemin = HamiltonienPathByFleury(adj, node, node_n);
    printf("\n hamiltonien chemin: \n");
    for (size_t i = 0; i < arrlen(hamiltonien_chemin); i++){
        printf(" %u",hamiltonien_chemin[i]);
    }

    for (size_t i = 0; i < hmlen(adj); i++){
        arrfree(adj[i].value);
    }

    hmfree(adj);
    arrfree(euleur_chemin);
    arrfree(hamiltonien_chemin);
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