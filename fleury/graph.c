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

size_t* cp_sousadj(size_t *_item, size_t _item_n){
    size_t *item = NULL;
    for (size_t i = 0; i < _item_n; i++){
        arrput(item, _item[i]);
    }
    return item;
}

KV_ITEM * cp_graph(KV_ITEM *adj, size_t *node, size_t node_n){
    KV_ITEM *adj_graph = NULL;
    for (size_t i = 0; i < node_n; i++){
        size_t *item = NULL;
        size_t *sous_adj = hmget(adj, node[i]);
        for (size_t j = 0; j < arrlen(sous_adj); j++){
            arrput(item, sous_adj[j]);
        }
        hmput(adj_graph, node[i], item);
    }
    return adj_graph;
}

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

// DFS 
size_t *dfs(KV_ITEM *adj, size_t *node, size_t node_n, size_t origin){
    KV_BOOL *visited = NULL;
    size_t *res = NULL;
    
    dfsRec(adj,&visited,node,node_n,origin,&res);
    hmfree(visited);
    return res;
}


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

// EULER PATH 
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

    KV_ITEM *adj_graph = cp_graph(adj, node, node_n);
    size_t *c = NULL;
    size_t connexStatus = node_n;
    size_t origin = node[impair_pos];
    fleuryRec(adj_graph, &connexStatus, node, node_n, origin, &c);

    if (impair_count == 0) assert(c[0] == c[arrlen(c) - 1]);
    if (impair_count == 2) assert(c[0] != c[arrlen(c) - 1]);

    for (size_t i = 0; i < hmlen(adj_graph); i++){
        arrfree(adj_graph[i].value);
    }
    hmfree(adj_graph);
    return c;
}

void fleuryRecNode(KV_ITEM *adj_graph, size_t *connexStatus, size_t *node, size_t node_n, size_t origin, size_t **c){;
    KV_ITEM *adj = cp_graph(adj_graph, node, node_n);

    arrput(*c,origin); // notre chemin d'euler
    // printf("\n origin: %u, connex_status: %u\n",origin,*connexStatus);
    size_t *dfs_result = NULL;

    // tout l'adjacent du noeud
    size_t len_sous_adj = arrlen(hmget(adj, origin));
    size_t *sous_adj = cp_sousadj(hmget(adj, origin), len_sous_adj);
    
    for (size_t i = 0; i < len_sous_adj; i++){
        
        // essayer de suprimer cette noeud
        size_t tmp = sous_adj[i];
        size_t tmp_len_sous_adj = arrlen(hmget(adj, tmp));
        size_t *tmp_sous_adj = cp_sousadj(hmget(adj, tmp), tmp_len_sous_adj);
        arrfree(hmget(adj, tmp));
        hmdel(adj, tmp);
        for (size_t j = 0; j < tmp_len_sous_adj; j++){
            size_t *tmp_sous_sous_adj = hmget(adj, tmp_sous_adj[j]);
            for (size_t k = 0; k < arrlen(tmp_sous_sous_adj); k++){
                if (tmp_sous_sous_adj[k] == tmp) {
                    arrdel(tmp_sous_sous_adj, k);
                    break;
                }
            }
        }

        // tester si notre graph reste connex
        dfs_result = dfs(adj, node, node_n, origin);
        if ((arrlen(dfs_result) == *connexStatus) || (i == (len_sous_adj - 1))) {
            // remotons le node qu'on avais suprimer avant
            hmput(adj, tmp, tmp_sous_adj);
            for (size_t j = 0; j < tmp_len_sous_adj; j++){
                arrput(hmget(adj, tmp_sous_adj[j]), tmp);
            }
            
            // suprimer le noeud origin
            for (size_t j = 0; j < len_sous_adj; j++){
                size_t *tmp_sous_sous_adj = hmget(adj, sous_adj[j]);
                for (size_t k = 0; k < arrlen(tmp_sous_sous_adj); k++){
                    if (tmp_sous_sous_adj[k] == origin) {
                        arrdel(tmp_sous_sous_adj, k);
                        break;
                    }
                }
            }
            arrfree(hmget(adj, origin));
            hmdel(adj, origin);

            // passe au noeud suivant
            *connexStatus = *connexStatus - 1;
            fleuryRecNode(adj, connexStatus, node, node_n, tmp, c);
            break;
        } 

        // remotons le node qu'on avais suprimer avant
        hmput(adj, tmp, tmp_sous_adj);
        for (size_t j = 0; j < tmp_len_sous_adj; j++){
            arrput(hmget(adj, tmp_sous_adj[j]), tmp);
        }
    
        // et passe à l'adjacent suivant
        arrfree(dfs_result);
    }

    arrfree(dfs_result);
    for (size_t i = 0; i < hmlen(adj); i++){
        arrfree(adj[i].value);
    }
    hmfree(adj);
    arrfree(sous_adj);
    adj = NULL;
}

// HAMILTONIEN PATH
size_t *HamiltonienPathByFleury(KV_ITEM *adj, size_t *node,size_t node_n){
    KV_ITEM *adj_graph = cp_graph(adj, node, node_n);
    size_t *c = NULL;
    size_t connexStatus = node_n - 1;
    size_t origin = node[0];
    fleuryRecNode(adj_graph, &connexStatus, node, node_n, origin, &c);

    for (size_t i = 0; i < hmlen(adj_graph); i++){
        arrfree(adj_graph[i].value);
    }
    hmfree(adj_graph);
    return c;
}

// JUST FOR TEST
int somme(int a, int b){
    return a+b;
}

// REFUNCTION 
void hm_put(KV_ITEM **adj, size_t key, size_t *item){
    hmput(*adj, key, item);
}
void arr_put(size_t **item, size_t v){
    arrput(*item,v);
}
size_t arr_get(size_t **item, size_t i){
    return (*item)[i];
}
size_t arr_len(size_t *item){
    return arrlen(item);
}

// FREE FUNCTION
void free_graph(KV_ITEM **adj){
    for (size_t i = 0; i < hmlen(*adj); i++){
        arrfree((*adj)[i].value);
    }
    hmfree(*adj);
}
void arr_free(size_t **item){
    arrfree(*item);
}