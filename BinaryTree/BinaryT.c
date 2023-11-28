#include <stdio.h>
#include <stdlib.h> 

typedef struct BTree {
    int value;
    struct BTree* left; 
    struct BTree* right;
} BTree;

BTree* createTree(){
    BTree *b = (BTree*)malloc(sizeof(BTree));
    b->left = NULL;
    b->right = NULL;
    return b;
}

int len(char tree[]){
    int length = 0;
    while (tree[length] != '\0') {
        length++;
    }
    return length;
}
int c= 0;

void fillTree(BTree** b, char treeCode[]){
    if(treeCode[c] == '\0'){
        return;
    }
    if(treeCode[c] == 'x'){
        c++;
        return;
    }
    if(*b == NULL){
        *b = (BTree*)malloc(sizeof(BTree));
        (*b)->left = NULL;
        (*b)->right = NULL;
    }
    char a = treeCode[c];
    (*b)->value = atoi(&a);
    c++;
    fillTree(&(*b)->left, treeCode);
    fillTree(&(*b)->right, treeCode);
}
void printTree(BTree* b, int l){
    if(b == NULL){
        for (int i = 0; i <= l; i++)
        {
            printf("---");
        }
        printf("( )\n");
        return;
    }
    for (int i = 0; i <= l; i++)
    {
        printf("---");
    }
    
    printf("(%d)\n",b->value);
    printTree(b->left, l+1);
    printTree(b->right, l+1);
}

void main(){
    BTree* b = NULL;
    fillTree(&b,"543xx8xx6xx");
    printTree(b, 0);
}