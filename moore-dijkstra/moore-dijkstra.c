#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>

#define NOTFINI -1
#define INFINI INT_MAX
#define STB_DS_IMPLEMENTATION
#include "lib/stb_ds.h"

// INPUT
const size_t number_of_node = 4;
int graph[4][4] = {
        {0, 0,0,2},
        {10,0,4,0},
        {3, 2,0,8},
        {1, 0,0,0},
    };
char node[4] = {'A','C','D','X'};
const size_t originNodePos = 0;

// const size_t number_of_node = 7;
// int graph[7][7] = {
//         {0,0,4,3,0,0,0},
//         {3,0,0,0,0,0,0},
//         {0,4,0,0,2,0,6},
//         {2,0,0,0,0,0,0},
//         {0,0,0,1,0,0,0},
//         {0,0,0,6,4,0,0},
//         {0,0,5,0,3,3,0},
//     };
// char node[7] = {'A','B','C','D','E','F','G'};
// const size_t originNodePos = 0;

typedef struct {
    char *items;
    size_t count;
} Nodes;

typedef struct {
    char *key;
    size_t value;
} Pairs;

typedef struct {
    int key;
    int value;
} KV;


void printMatriceGraph(void *graph, char *node, char *nodeColumne, size_t node_n);
void printNodes(Nodes nodes);
size_t* min(void *graph, size_t line ,size_t node_n,Nodes leftNodeOrder, Pairs *nodeIndex, KV *indexToNode);
void checkSuccessors(void *graph,Nodes *successors, size_t posNodeInArray, KV *indexNode, size_t node_n);
int minOf(int a, int b);


int main(){
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
    int shorterPath[number_of_node][number_of_node] = {};
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
    printMatriceGraph(graph,node,node,number_of_node);
    printf("\n");
    
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
        checkSuccessors(graph,&successors,posInArrayAndInMatrice[1],indexToNode,number_of_node);
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

    
    printMatriceGraph(shorterPath,node,leftNodeOrder.items,number_of_node);
    printNodes(nodesNotVisited);
    printf("\n");
    

    arrfree(nodesNotVisited.items);
    arrfree(leftNodeOrder.items);
    arrfree(successors.items);
    for (size_t i = 0; i < shlen(nodesIndex); ++i) {
        free(nodesIndex[i].key);    
    }
    shfree(nodesIndex);
    hmfree(indexToNode);
    free(posInArrayAndInMatrice);
    return 0;
}



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
void checkSuccessors(void *graph,Nodes *successors, size_t posNodeInArray,KV *indexNode ,size_t node_n){
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

