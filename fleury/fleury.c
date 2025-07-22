#include<stdio.h>
#define DFS_IMPLEMENTATION
#include "dfs-graph.h"


void fleuryRec(KV_ITEM *adj, KV_BOOL **visited_node ,size_t *node, size_t node_n, size_t origin, size_t **c);

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
    for (size_t i = 0; i < node_n; i++){
        printf("%u: ",node[i]);
        for (size_t j = 0; j < arrlen(hmget(adj,node[i])); j++){
            printf("%d",hmget(adj,node[i])[j]);
        }
        printf("\n");
    }
    size_t *dfs_result = dfs(adj, node, node_n, 0);
    printf(" this graph is connex if length of dfs result = node_n = %d\n",arrlen(dfs_result));
    printf("\n\n");


    size_t *c = NULL;
    KV_BOOL *visited_node = NULL;
    fleuryRec(adj, &visited_node, node, node_n, 4, &c);
    
    

    for (size_t i = 0; i < hmlen(adj); i++){
        arrfree(adj[i].value);
    }
    hmfree(adj);
    arrfree(c);
    arrfree(dfs_result);
    hmfree(visited_node);
    return 0;
}

size_t *cp_item(size_t *_item,size_t n){
    size_t *item = NULL;
    for (size_t i = 0; i < n; i++){
        arrput(item,_item[i]);
    }
    return item;
}

void fleuryRec(KV_ITEM *adj, KV_BOOL **visited_node,size_t *node, size_t node_n, size_t origin, size_t **c){
    arrput(*c,origin);
    hmput(*visited_node,origin, 1);
    size_t *dfs_result = NULL;

    size_t *sous_adj = hmget(adj,origin);
    for (size_t i = 0; i < arrlen(sous_adj); i++){
        size_t *tmp_item = cp_item(hmget(adj,sous_adj[i]), arrlen(hmget(adj,sous_adj[i])));
        arrfree(hmget(adj,sous_adj[i]));
        hmdel(adj,sous_adj[i]);

        dfs_result = dfs(adj, node, node_n, origin);
        if (arrlen(dfs_result) != node_n) {
            printf("\n%d",arrlen(dfs_result));
            continue;
        }
        hmput(adj,sous_adj[i],tmp_item);
        
        if (hmget(*visited_node,origin) != 1) {
            arrput(*c,sous_adj[i]);
        }
        if (arrlen(*c) != node_n) {
            printf("\n %d",origin);
            fleuryRec(adj, visited_node, node, node_n, sous_adj[i],c);
        }
        break;
    }

    arrfree(dfs_result);

}
