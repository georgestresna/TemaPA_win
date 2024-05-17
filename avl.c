#include "./headers/avl.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int nodeHeight(avlNode* root){
    if(root == NULL) return -1;
    else return root->height;
}


avlNode *RightRotation (avlNode *z){
    avlNode *y = z->left;
    avlNode *T3 = y->right;
    y->right = z;
    z->left = T3; // Modifica inaltimile pentru z si y
    z->height = max(nodeHeight(z->left), nodeHeight(z->right))+1;
    y->height = max(nodeHeight(y->left), nodeHeight(y->right))+1;
    return y; // noua radacina
}

avlNode *LeftRotation (avlNode *z){
    avlNode *y = z->right;
    avlNode *T2 = y->left;
    y->left = z;
    z->right = T2;
    z->height = max(nodeHeight(z->left), nodeHeight(z->right))+1;
    y->height = max(nodeHeight(y->left), nodeHeight(y->right))+1;
    return y;
}

avlNode* LRRotation(avlNode*Z){
    Z->left = LeftRotation(Z->left);
    return RightRotation(Z);
}

avlNode* RLRotation(avlNode*Z){
    Z->right = RightRotation(Z->right);
    return LeftRotation(Z);
}

int max(int a, int b){
    return((a>b)?a:b);
}

avlNode* insertAVL(avlNode* node, Team key){
    //1
    //printf("!!\n");
    if(node == NULL){
        node=(avlNode*)malloc(sizeof(avlNode));
        node->echipa = key;
        node->height = 0;
        node ->left = node->right = NULL;
        return node;
    }
    if (key.scorEchipa < node->echipa.scorEchipa)
        node->left = insertAVL(node->left, key);
    else if (key.scorEchipa > node->echipa.scorEchipa)
        node->right = insertAVL(node->right, key);
    else {
        if(strcmp(key.numeEchipa, node->echipa.numeEchipa)>0)
            node->right = insertAVL(node->right, key);
        else
            node->left = insertAVL(node->left, key);
    }

    node->height = 1 + max(nodeHeight (node->left),
                           nodeHeight (node->right));

    int k = (nodeHeight (node->left) - nodeHeight (node->right));

    if (k > 1 && (key.scorEchipa < node->left->echipa.scorEchipa || (key.scorEchipa == node->left->echipa.scorEchipa  && strcmp(key.numeEchipa, node->left->echipa.numeEchipa) < 0)))
        return RightRotation (node) ;

    if (k < -1 && (key.scorEchipa > node->right->echipa.scorEchipa || (key.scorEchipa == node->left->echipa.scorEchipa && strcmp(key.numeEchipa, node->left->echipa.numeEchipa) > 0)))
        return LeftRotation(node);

    if (k > 1 && (key.scorEchipa < node->left->echipa.scorEchipa || (key.scorEchipa == node->left->echipa.scorEchipa  && strcmp(key.numeEchipa, node->left->echipa.numeEchipa) < 0)))
        return RLRotation(node);

    if (k <-1 && (key.scorEchipa > node->right->echipa.scorEchipa || (key.scorEchipa == node->left->echipa.scorEchipa && strcmp(key.numeEchipa, node->left->echipa.numeEchipa) > 0)))
        return LRRotation(node);

    return node;
}