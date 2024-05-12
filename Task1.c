#include <stdio.h>
#include <stdlib.h>
#include "./headers/list.h"

void fileWrite(FILE* fout, Node* head){
    while(head){
        fputs(head->val, fout);
        head=head->next;
    }
}

Node* Task1(FILE* fin, FILE* fout){

    //nr echipe
    int nrEchipe;
    fscanf(fin, "%d", &nrEchipe);
    getc(fin);//skip linia cu nrEchipe

    //initializare lista
    Node *head;
    head=NULL;

    char buffer[100];
    for(int i=0; i<nrEchipe; i++){
        int nrPlayeri;
        fscanf(fin, "%d", &nrPlayeri);
        getc(fin);//scot spatiu
        fgets(buffer, sizeof(buffer), fin);
        addAtBeginning(&head, buffer);
        //skip jucatori
        for(int j=0; j<nrPlayeri; j++){
            fgets(buffer, sizeof(buffer), fin);
        }
    }
    fileWrite(fout, head);
    return head;
}
