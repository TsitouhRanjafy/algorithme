/**
 * For undirected graph only
 * Implemented: - DFS
 *              - Euler path or cycle by Fleury algo
 *              - ...    
 */

#ifndef DFS_GRAPH
#define DFS_GRAPH

#include<stdio.h>
#include<stdbool.h>
#define STB_DS_IMPLEMENTATION
#include "./lib/stb_ds.h"

typedef struct {
    size_t key;
    size_t *value;
} KV_ITEM;

typedef struct {
    size_t key;
    bool value;
} KV_BOOL;

size_t *dfs(KV_ITEM *adj, size_t *node, size_t node_n, size_t origin);
size_t *EulerPathByFleury(KV_ITEM *adj, size_t *node, size_t node_n);

#ifdef DFS_IMPLEMENTATION



// DFS GRAPH
void dfsRec(KV_ITEM *adj, KV_BOOL **visited, size_t *node, size_t node_n, size_t origin, size_t **res){
    
    hmput(*visited,origin,1);
    arrput(*res,origin);
    
    size_t *tmp = hmget(adj,origin);
    for (size_t j = 0; j < arrlen(tmp); j++){
        if (!hmget(*visited,tmp[j])){
            dfsRec(adj,visited,node,node_n,tmp[j],res);
        }
    }
}

size_t *dfs(KV_ITEM *adj, size_t *node, size_t node_n, size_t origin){
    KV_BOOL *visited = NULL;
    size_t *res = NULL;

    dfsRec(adj,&visited,node,node_n,origin,&res);
    hmfree(visited);
    return res;
}

// EULER CHEMIN BY FLEURY ALGO
void fleuryRec(KV_ITEM *adj, size_t *connexStatus, size_t *node, size_t node_n, size_t origin, size_t **c){;
    arrput(*c,origin); // notre chemin d'euler
    // printf("\n origin: %u, connex_status: %u\n",origin,*connexStatus);
    size_t *dfs_result = NULL;

    // tout l'adjacent du noeud
    size_t *sous_adj1 = hmget(adj,origin);
    size_t len_sous_adj1 = arrlen(sous_adj1);
    for (size_t i = 0; i < len_sous_adj1; i++){
        
        // essayer de suprimer l'arc
        size_t tmp1 = sous_adj1[i];
        size_t *sous_adj2 = hmget(adj,tmp1);
        arrdel(sous_adj1,i);
        size_t j = 0;
        int tmp2 = -1;
        while (j < arrlen(sous_adj2)){
            if (sous_adj2[j] == origin) {
                tmp2 = sous_adj2[j];
                arrdel(sous_adj2,j);
                break;
            }
            j++;
        }
        assert(tmp2 > -1);

        // tester si notre graph reste connex
        dfs_result = dfs(adj, node, node_n, origin);
        if (arrlen(dfs_result) == *connexStatus) {
            // passe au noeude suivant
            fleuryRec(adj,connexStatus,node,node_n,tmp1,c);
            break;

        // tester si c'est node dernier noeude à chosir
        // même le graph n'est pas connex
        } else if (i == (len_sous_adj1 - 1)){
            *connexStatus = *connexStatus - 1;
            assert(*connexStatus >= 0);
            // passe au noeude suivant
            fleuryRec(adj,connexStatus,node,node_n,tmp1,c);
            break;
        }

        // si non, rajoutons les arc qu'on avais suprimer
        arrins(sous_adj1,i,tmp1);
        arrins(sous_adj2,j,tmp2);
        arrfree(dfs_result);
        dfs_result = NULL;

        // et passe à l'adjacent suivant
    }
    arrfree(dfs_result);
}

size_t *EulerPathByFleury(KV_ITEM *adj, size_t *node, size_t node_n){
    size_t impair_count = 0;
    int impair_pos = 0;
    for (size_t i = 0; i < node_n; i++){
        if ((arrlen(hmget(adj,node[i])) % 2) == 1) {
            impair_count += 1;
            impair_pos = i;
        }
    }
    if ((impair_count != 2) && (impair_count != 0)) return NULL;

    size_t *c = NULL;
    size_t connexStatus = node_n;
    size_t origin = node[impair_pos];
    fleuryRec(adj, &connexStatus, node, node_n, origin, &c);

    if (impair_count == 0) assert(c[0] == c[arrlen(c) - 1]);
    if (impair_count == 2) assert(c[0] != c[arrlen(c) - 1]);
    return c;
}

#endif
#endif