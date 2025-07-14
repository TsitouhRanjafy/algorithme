#include<stdio.h>
#include<stdlib.h>


// binary tree node
struct node {
    int data;
    struct node* left;
    struct node* right;
};

// Helper function that add a new node with the given data and NULL for left and right pointers
struct node* newNode(int data){
    struct node* node = malloc(sizeof(struct node));
    (*(*(&node))).data = data;
    (*(*(&node))).left = NULL;
    (*(*(&node))).right = NULL;
    
    return node;
}

// print the nodes in inorder
void printInorder(struct node* node){
    if (node == NULL) return;

    printInorder((*(*(&node))).left);

    printf(" %d",(*(*(&node))).data);

    printInorder((*(*(&node))).right);
}

// print the nodes in preorder
void printPreoder(struct node* node){
    if (node == NULL) return;

    printf(" %d",(*(*(&node))).data);

    printPreoder((*(*(&node))).left);
    printPreoder((*(*(&node))).right);
}

// print the nodes in postorder
void printPostorder(struct node* node){
    if (node == NULL) return;

    printPostorder((*(*(&node))).left);
    printPostorder((*(*(&node))).right);
    printf(" %d",(*(*(&node))).data);
}

int main(){
    struct node* tree = NULL;
    tree = newNode(1);
    (*tree).left = newNode(2);
    (*(*tree).left).left = newNode(4);
    (*(*tree).left).right = newNode(5);
    (*tree).right = newNode(3);
    (*(*tree).right).right = newNode(6);
     
    printInorder(tree);
    printf("\n");
    printPreoder(tree);
    printf("\n");
    printPostorder(tree);

    free((*(*tree).left).right);
    free((*(*tree).left).left);
    free((*(*tree).right).right);
    free((*tree).left);
    free((*tree).right);
    free(tree);
    return 0;
}