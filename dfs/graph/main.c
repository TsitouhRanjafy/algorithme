#include<stdio.h>
#include<stdbool.h>
#define DFS_IMPLEMENTATION
#include "../dfs-graph.h"

int main(){
    KV_ITEM *adj = NULL;
    size_t node[5] = {0,1,2,3,4};
    
    
    // input graph (1) adj a key value
    size_t *item = NULL;
    arrput(item,1);
    arrput(item,2);
    hmput(adj,0,item);

    item= NULL;
    arrput(item,0);
    arrput(item,2);
    hmput(adj,1,item);

    item = NULL;
    arrput(item,0);
    arrput(item,1);
    arrput(item,3);
    arrput(item,4);
    hmput(adj,2,item);
    
    item = NULL;
    arrput(item,2);
    hmput(adj,3,item);
    
    item = NULL;
    arrput(item,2);
    hmput(adj,4,item);
    
    
    
    // input graph 2
    // arrput(item,2);
    // arrput(item,3);
    // arrput(item,1);
    // hmput(adj,0,item);
    
    // item= NULL;
    // arrput(item,0);
    // hmput(adj,1,item);

    // item = NULL;
    // arrput(item,0);
    // arrput(item,4);
    // hmput(adj,2,item);
    
    // item = NULL;
    // arrput(item,0);
    // hmput(adj,3,item);
    
    // item = NULL;
    // arrput(item,2);
    // hmput(adj,4,item);
    
    
    size_t *res = dfs(adj,node,5,node[0]);

    for (size_t i = 0; i < arrlen(res); i++){
        printf(" %d ->",res[i]);
    }
    

    for (size_t i = 0; i < hmlen(adj); i++){
        arrfree(adj[i].value);
    }
    
    hmfree(adj);
    arrfree(res);
    return 0;
}