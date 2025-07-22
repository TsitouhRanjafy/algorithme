#include<stdio.h>
#define DFS_IMPLEMENTATION
#include "dfs-graph.h"

int main(){
    KV_ITEM *adj = NULL;
    size_t node[] = {0,1,2,3,4,5,6};


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


    size_t *dfs_res = dfs(adj,node,arrlen(node),node[0]);
    for (size_t i = 0; i < arrlen(dfs_res); i++){
        printf("%d",dfs_res[i]);
    }
    

    for (size_t i = 0; i < hmlen(adj); i++){
        arrfree(adj[i].value);
    }
    hmfree(adj);
    arrfree(dfs_res);
    return 0;
}

