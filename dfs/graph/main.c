#include<stdio.h>
#include<stdbool.h>
#include "../dfs-graph.h"

int main(){
    KV_BOOL *visited = NULL;
    KV_ITEM *adj = NULL;
    size_t node[5] = {0,1,2,3,4};
    size_t *res = NULL; 


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


    dfsRec(adj,&visited,node,5,node[0],&res);

    printf("\n%d",arrlen(res));

    for (size_t i = 0; i < hmlen(adj); i++){
        arrfree(adj[i].value);
    }
    
    hmfree(adj);
    hmfree(visited);
    arrfree(res);
    return 0;
}