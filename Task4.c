#include <stdio.h>
#include <stdlib.h>
#include "./headers/arbori.h"

void printDescending(treeNode* root, FILE* fout) {
    if (root == NULL) {
        return;
    }

    printDescending(root->right, fout);
    fprintf(fout, "%-33s -  %.2f\n", root->echipa.numeEchipa, root->echipa.scorEchipa);
    printDescending(root->left, fout);
}

void Task4(Node*head, FILE* fout){

    fprintf(fout, "\nTOP 8 TEAMS:\n");
    treeNode *root=NULL;
    while(head){
        //printf("%.2f\n", head->echipa.scorEchipa);
        root=insert(root, head->echipa);
        head=head->next;
    }
    printDescending(root, fout);

}