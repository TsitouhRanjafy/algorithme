#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

#define INF -1
#define MAX_NODE 10
#define STB_DS_IMPLEMENTATION
#include "lib/stb_ds.h"


const size_t number_of_node = 7;
int graph[7][7] = {
        {0,0,4,3,0,0,0},
        {3,0,0,0,0,0,0},
        {0,4,0,0,2,0,6},
        {2,0,0,0,0,0,0},
        {0,0,0,1,0,0,0},
        {0,0,0,6,4,0,0},
        {0,0,5,0,3,3,0},
    };
char node[7] = {'A','B','C','D','E','F','G'};
const char originNodePos = 0;

typedef struct {
    char *items;
    size_t count;
} Nodes;



void graphVizInMatrice(void *graph, char *node, size_t node_n);
void printNodesNotVisited(Nodes nodes);



int main(){
    Nodes nodesNotVisited = {
        .items = NULL,
        .count = 0
    };
    Nodes leftNodeOrder = {
        .items = NULL,
        .count = 0,
    };
    int pcc[number_of_node][number_of_node] = {};
    
    // init node not visited
    for (size_t i = 0; i < number_of_node; ++i){
        arrput(nodesNotVisited.items,node[i]);
    }
    nodesNotVisited.count = number_of_node;

    graphVizInMatrice(graph,node,number_of_node);
    printf("\n");
    
    arrdel(nodesNotVisited.items,0);
    nodesNotVisited.count--;
    pcc[originNodePos][originNodePos] = 0;
    arrput(leftNodeOrder.items,node[originNodePos]);
    for (size_t i = 1; i <= nodesNotVisited.count; ++i){
        if (graph[i][0] > 0){
            pcc[i][0] = graph[i][0];
        } else {
            pcc[i][0] = INF;
        }
    }
    graphVizInMatrice(pcc,node,number_of_node);
    // printNodesNotVisited(nodesNotVisited);


    // graphVizInMatrice(pcc,node,7);

    arrfree(nodesNotVisited.items);
    arrfree(leftNodeOrder.items);
    return 0;
}



// print the graph in matrice
void graphVizInMatrice(void *graph, char *node, size_t node_n){
    int (*array)[node_n] = graph;

    printf("\t  ");
    for (size_t i = 0; i < node_n; ++i){
        printf("%3c ",node[i]);
    }
    printf("\n");
    for (size_t i = 0; i < node_n; ++i){
        printf("\t %c",node[i]);
        for (size_t j = 0; j < node_n; ++j)
            printf("%3d ", array[j][i]);
        printf("\n");
    }
}

void printNodesNotVisited(Nodes nodes){
    for (size_t i = 0; i < nodes.count; ++i){
        printf("%c",nodes.items[i]);
    }
}