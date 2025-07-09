#include<stdio.h>

// implementation
#define MOORE_DIJSKTRA_IMPEMENTATION
#include "moore-dijkstra.h"

int main(){
    const size_t number_of_node = 4;
    int graph[4][4] = {
            {0, 0,0,2},
            {10,0,4,0},
            {3, 2,0,8},
            {1, 0,0,0},
        };
    char node[4] = {'A','C','D','X'};
    const size_t originNodePos = 0;
    Pairs *pcc = NULL;

    // print the graph
    printMatriceGraph(graph,node,node,number_of_node);
    // usage of algo
    pcc = moore_dijstra(graph,node,originNodePos,number_of_node);
    // get the weight for A to C
    printf(" A -> C : %u",shget(pcc,"C")); 

    for (size_t i = 0; i < shlen(pcc); ++i) {
            free(pcc[i].key);    
    }
    shfree(pcc);
    return 0;
}


