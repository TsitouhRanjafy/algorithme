/**
 * dfs for undirected graph
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

#endif