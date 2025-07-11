#ifndef MOORE_DIJSKTRA_H
#define MOORE_DIJSKTRA_H

/* moore-dijkstra v0.1 

    This is a single-header-file library to use algo of MOORE-DIJSKTRA

    To use this librairy:
        - download the stb_ds.h and moore-dijkstra.h file, 
        Structure of directory: lib/stb_ds.h
                                moore-dijkstra.h
        
        - do this in *one* your C file:
            #define MOORE_DIJSKTRA_IMPEMENTATION
            #include "moore-dijkstra.h"
        
    DOCUMENTATION

        Declare an empty dynamic array of type Pairs
            Pairs* foo = NULL;
        
        Access the short weight of graph:
            shget(foo, char *T);
                e.g: shget(foo, "D"); // Get the short weight in node origin to node "D"

        Function

            moore_dijstra:
                Pairs *moore_dijstra(void *matrice_graph, char *node, size_t originNodePos, size_t number_of_node);
                    - matrice_graph: A pointer to a 2D adjacency matrix representing the graph 
                                    (weights of directed edges, weights > 0, 0 if not defined).
                    - node: An array of characters representing the node names 
                            (e.g., {'A', 'B', 'C'}).
                    - originNodePos: The index of the origin node in the node[] array.
                    - number_of_node: Total number of nodes in the graph.
                
            printMatriceGraph:
                void printMatriceGraph(void *graph, char *nodeLine, char *nodeColumne, size_t node_n)
                    Print the matrice (graph)
            
            The returned pointer must be freed manually:
                for (int i = 0; i < shlen(foo); ++i) {
                    free(foo[i].key);
                }
                shfree(foo);

*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>

#define NOTFINI -1
#define INFINI INT_MAX
#define STB_DS_IMPLEMENTATION
#include "lib/stb_ds.h"


typedef struct {
    char *key;
    size_t value;
} Pairs;

Pairs *moore_dijstra(void *matrice_graph, char *node, size_t originNodePos, size_t number_of_node);
void printMatriceGraph(void *graph, char *nodeLine, char *nodeColumne, size_t node_n);


#ifdef MOORE_DIJSKTRA_IMPEMENTATION

/*************** GLOBAL VARIABLE DECLARATION ********************/

typedef struct {
    char *items;
    size_t count;
} Nodes;


typedef struct {
    int key;
    int value;
} KV;

/****************************************************************/


/*************** HELPER FUNCTION ********************/
// print the graph in matrice
void printMatriceGraph(void *graph, char *nodeLine, char *nodeColumne, size_t node_n){
    int (*array)[node_n] = graph;

    printf("\t  ");
    for (size_t i = 0; i < node_n; ++i){
        printf("%3c ",nodeLine[i]);
    }
    printf("\n");
    for (size_t i = 0; i < node_n; ++i){
        printf("\t %c",nodeColumne[i]);
        for (size_t j = 0; j < node_n; ++j)
            printf("%3d ", array[j][i]);
        printf("\n");
    }
}

// return the post of min pcc 
size_t *min(void *graph, size_t line ,size_t node_n,Nodes leftNodeOrder, Pairs *nodeIndex,KV *indexToNode){
    int (*array)[node_n] = graph;
    int tmp = INFINI; 
    ptrdiff_t minIndex = NOTFINI;
    for (size_t i = 0; i < node_n; ++i){
        if (hmget(indexToNode,i) > 0) continue;
        if ((array[i][line] < tmp) && (array[i][line] != 0) && (array[i][line] != -1)){
            tmp = array[i][line];
            minIndex = i;
        }
    }
    tmp = 0;
    for (size_t j = 0; j < leftNodeOrder.count; ++j){
        char s[2];
        snprintf(s,2,"%c",leftNodeOrder.items[j]);
        if (shget(nodeIndex,s) < minIndex) tmp++;
    }
    size_t *posInArrayAndInMatrice = malloc(sizeof(size_t) * 2);
    posInArrayAndInMatrice[0] = (minIndex - tmp);
    posInArrayAndInMatrice[1] = minIndex;
    assert(posInArrayAndInMatrice[0] >= 0 );
    assert(posInArrayAndInMatrice[1] < node_n);
    return posInArrayAndInMatrice;
}

// check the successors
void checkSuccessors(void *graph,Nodes *successors, size_t posNodeInArray,KV *indexNode ,size_t node_n, char *node){
    int (*matrice)[node_n] = graph;
    for (size_t i = 0; i < node_n; ++i){
        if ((matrice[i][posNodeInArray] > 0) && (hmget(indexNode,i)) == 0 ) {
            arrput(successors->items,node[i]);
            successors->count++;
        }
    }
}

// compare and return the min
int minOf(int a, int b){
    if (a == NOTFINI) return b;
    if (b == NOTFINI) return a; 
    return (a < b) ? a : b;
}

// print node
void printNodes(Nodes nodes){
    for (size_t i = 0; i < nodes.count; ++i){
        printf("%3c",nodes.items[i]);
    }
}
/****************************************************/


/******************* PRINCIPAL FUNCTION *************/
Pairs* moore_dijstra(void *matrice_graph, char *node, size_t originNodePos, size_t number_of_node){
    int (*graph)[number_of_node] = matrice_graph;

    Nodes nodesNotVisited = {
        .items = NULL,
        .count = 0
    };
    Nodes leftNodeOrder = {
        .items = NULL,
        .count = 0
    };
    Nodes successors = {
        .items = NULL,
        .count = 0
    };
    KV *indexToNode = NULL;
    Pairs *nodesIndex = NULL;
    int shorterPath[number_of_node][number_of_node];
    char tmp_key[2];
    
    // init node not visited
    for (size_t i = 0; i < number_of_node; ++i){
        arrput(nodesNotVisited.items,node[i]);
    }
    nodesNotVisited.count = number_of_node;

    // init nodesIndex
    for (size_t i = 0;i < number_of_node; ++i){
        snprintf(tmp_key,sizeof(tmp_key),"%c",node[i]);
        shput(nodesIndex,strdup(tmp_key),i);
    }
    // printMatriceGraph(graph,node,node,number_of_node);
    // printf("\n");
    
    // STEP 1
    arrput(leftNodeOrder.items,nodesNotVisited.items[originNodePos]);
    leftNodeOrder.count++;
    hmput(indexToNode,originNodePos,nodesNotVisited.items[originNodePos]);
    arrdel(nodesNotVisited.items,originNodePos);
    nodesNotVisited.count--;

    shorterPath[originNodePos][originNodePos] = 0;
    for (size_t i = 1; i <= nodesNotVisited.count; ++i){
        if (graph[i][0] > 0)
            shorterPath[i][0] = graph[i][0];
        else
            shorterPath[i][0] = NOTFINI;
    };
    /*--------------------*/

    size_t *posInArrayAndInMatrice = NULL;
    int cpt = 0;
    while (1){
        // STEP 2
        if (posInArrayAndInMatrice != NULL) free(posInArrayAndInMatrice);
        posInArrayAndInMatrice = min(shorterPath, leftNodeOrder.count - 1, number_of_node, leftNodeOrder, nodesIndex, indexToNode);
        arrput(leftNodeOrder.items, nodesNotVisited.items[posInArrayAndInMatrice[0]]);
        leftNodeOrder.count++;
        hmput(indexToNode, posInArrayAndInMatrice[1], nodesNotVisited.items[posInArrayAndInMatrice[0]]);
        arrdel(nodesNotVisited.items,posInArrayAndInMatrice[0]);
        nodesNotVisited.count--;
        if (nodesNotVisited.count == 0) break;; // STOP
        shorterPath[posInArrayAndInMatrice[1]][leftNodeOrder.count - 1] = shorterPath[posInArrayAndInMatrice[1]][leftNodeOrder.count - 2];
        /*---------------------*/
    
        // STEP 3
        arrfree(successors.items);
        successors.count = 0;
        checkSuccessors(graph,&successors,posInArrayAndInMatrice[1],indexToNode,number_of_node,node);
        for (size_t i = 0; i < successors.count; ++i){
            snprintf(tmp_key,2,"%c",successors.items[i]);
            size_t posI = shget(nodesIndex,tmp_key);
            size_t posJ = posInArrayAndInMatrice[1];
            shorterPath[posI][leftNodeOrder.count - 1] = minOf(shorterPath[posI][leftNodeOrder.count - 2], (shorterPath[posJ][leftNodeOrder.count - 2] + graph[posI][posJ]));
        }
        for (size_t i = 0; i < number_of_node; ++i){
            if (hmget(indexToNode,i) > 0) {
                shorterPath[i][leftNodeOrder.count - 1] = shorterPath[i][leftNodeOrder.count - 2];
                continue;
            };
            if ((shorterPath[i][leftNodeOrder.count - 2] == -1) && (shorterPath[i][leftNodeOrder.count - 1] != 0)) continue;
            if ((shorterPath[i][leftNodeOrder.count - 2] != -1) && (shorterPath[i][leftNodeOrder.count - 1] != 0)) continue;
            shorterPath[i][leftNodeOrder.count - 1] = shorterPath[i][leftNodeOrder.count - 2];
        }
        /*-----------------------*/
    }


    for (size_t i = 0; i < number_of_node; ++i) {
        shorterPath[i][leftNodeOrder.count - 1] = shorterPath[i][leftNodeOrder.count -2];
        snprintf(tmp_key,sizeof(tmp_key),"%c",node[i]);
        shput(nodesIndex,tmp_key,shorterPath[i][leftNodeOrder.count - 1]);
    }
    
    // printMatriceGraph(shorterPath,node,leftNodeOrder.items,number_of_node);
    // printNodes(nodesNotVisited);
    // printf("\n");
    
    arrfree(nodesNotVisited.items);
    arrfree(leftNodeOrder.items);
    arrfree(successors.items);
    hmfree(indexToNode);    
    free(posInArrayAndInMatrice);
    return nodesIndex;
}

/**************************************************/

#endif

#endif