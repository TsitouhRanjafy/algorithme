#include<stdio.h>
#include<stdlib.h>

// GRAPH 2

struct node {
    int data;
    struct node* adj1;
    struct node* adj2;
    struct node* adj3;
    struct node* adj4;
};

struct node* createNode(int data);
void printPosOrder(struct node* tree);
void freeTree(struct node* tree);

int main(){
    struct node* tree = NULL;
    tree = createNode('A');
    tree->adj1 = createNode('B');
    tree->adj1->adj1 = createNode('D');
    tree->adj1->adj2 = createNode('E');
    tree->adj1->adj3 = createNode('F');
    tree->adj2 = createNode('C');
    tree->adj2->adj1 = createNode('G');
    tree->adj2->adj2 = createNode('K');
    tree->adj3 = createNode('L');

    printPosOrder(tree);

    freeTree(tree);
    return 0;
}

// function to create a new node
struct node* createNode(int data) {
    struct node* nodes = malloc(sizeof(struct node));
    if (nodes == NULL) exit;
    nodes->data = data;
    nodes->adj1 = NULL;
    nodes->adj2 = NULL;
    nodes->adj3 = NULL;
    nodes->adj4 = NULL;

    return  nodes;
}

// Depth-First Search traversal of a tree
void printPosOrder(struct node* tree){
    if (tree == NULL) return;
    printPosOrder(tree->adj1);
    printPosOrder(tree->adj2);
    printPosOrder(tree->adj3);
    printPosOrder(tree->adj4);
    printf("%c ",tree->data);
}

// free the tree
void freeTree(struct node* tree){
    if (tree == NULL) return;
    freeTree(tree->adj4);
    freeTree(tree->adj3);
    freeTree(tree->adj2);
    freeTree(tree->adj1);
    free(tree);
}