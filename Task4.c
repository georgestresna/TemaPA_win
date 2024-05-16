#include <stdio.h>
#include <stdlib.h>
#include "./headers/arbori.h"


void Task4(Node*head, FILE* fout){

    fprintf(fout, "TOP 8 TEAMS:\n");
    treeNode *root=NULL;
    while(head){
        printf("%.2f\n", head->echipa.scorEchipa);
        //root=insert(root, head->echipa);
        head=head->next;
    }
}