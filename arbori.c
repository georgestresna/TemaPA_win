#include "./headers/arbori.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void initTree(treeNode **root, Team d){
    *root=(treeNode*)malloc(sizeof(treeNode));
    (*root)->left=(*root)->right = NULL;
    (*root)->echipa = d;
}

int isEmpty (treeNode *root){
    return (root==NULL);
}

int isInterior(treeNode*n){
    return (n->left != NULL || n->right != NULL);
}

int isLeaf(treeNode*n){
    return(n->left == NULL && n->right == NULL);
}

treeNode* newNode(Team v){
    treeNode* node =(treeNode*)malloc(sizeof(treeNode));
    node->echipa = v;
    node->left = node->right = NULL;
    return node;
}

treeNode* insert(treeNode* node, Team v){
    if ( node == NULL ) return newNode(v);
    if ( v.scorEchipa < node->echipa.scorEchipa)
        node -> left = insert (node ->left , v );
    else if (v.scorEchipa > node ->echipa.scorEchipa)
        node -> right = insert (node ->right , v );
    else if (v.scorEchipa == node ->echipa.scorEchipa){
        if(strcmp(v.numeEchipa, node ->echipa.numeEchipa) > 0)
            node -> right = insert (node ->right , v );
        else
            node -> left = insert (node ->left , v );
    }

    return node;
}