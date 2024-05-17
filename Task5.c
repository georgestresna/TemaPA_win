#include <stdio.h>
#include <stdlib.h>
#include "./headers/avl.h"


void printLevel(avlNode* root, int level, FILE*fout) {
    if (root == NULL)
        return;
    if (level == 1)
        {fprintf(fout, "%s\n", root->echipa.numeEchipa, fout);
        //printf("%s %.2f\n", root->echipa.numeEchipa, root->echipa.scorEchipa);
        }
    else if (level > 1) {
        printLevel(root->right, level - 1, fout);
        printLevel(root->left, level - 1, fout);
    }
}

void Task5(Node* head, FILE* fout){
    fprintf(fout, "\nTHE LEVEL 2 TEAMS ARE: \n");

    avlNode*root=NULL;
    while(head){
        root=insertAVL(root, head->echipa);
        //printf("%s\n", head->echipa.numeEchipa);
        head=head->next;
    }
    printLevel(root, 3, fout);


    //lista primita e in ordine crescatoare, mic mare
}