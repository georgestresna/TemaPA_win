#include <stdio.h>
#include <stdlib.h>
#include "./headers/arbori.h"

void printDescending(treeNode* root, FILE* fout, Node**ranked8) {
    if (root == NULL) {
        return;
    }

    printDescending(root->right, fout, ranked8);
    fprintf(fout, "%-33s -  %.2f\n", root->echipa.numeEchipa, root->echipa.scorEchipa);
    
    Node* treeList=(Node*)malloc(sizeof(Node));
    treeList->echipa=root->echipa;
    treeList->next=*ranked8;
    *ranked8=treeList;
    
    printDescending(root->left, fout, ranked8);
}

void Task4(Node*head, FILE* fout, Node**ranked8){

    fprintf(fout, "\nTOP 8 TEAMS:\n");
    treeNode *root=NULL;
    while(head){
        //printf("%.2f\n", head->echipa.scorEchipa);
        root=insert(root, head->echipa);
        head=head->next;
    }

    printDescending(root, fout, ranked8);

}