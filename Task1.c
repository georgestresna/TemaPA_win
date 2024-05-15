#include <stdio.h>
#include <stdlib.h>
#include "./headers/list.h"
#include <string.h>


void fileWrite(FILE* fout, Node* head){
    while(head){
        fputs(head->echipa.numeEchipa, fout);
        fprintf(fout, "\n");
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

    for(int i=0; i<nrEchipe; i++){
        Team newNode;
        fscanf(fin, "%d", &(newNode.nrPlayeri)); 
        getc(fin);//scot spatiu
        fgets(newNode.numeEchipa, sizeof(newNode.numeEchipa), fin);
        newNode.numeEchipa[strlen(newNode.numeEchipa)-1] = '\0';

        for(int j=0; j<newNode.nrPlayeri; j++){
            fscanf(fin, "%s %s %d", newNode.jucator[j].firstName,
                                    newNode.jucator[j].secondName,
                                    &(newNode.jucator[j].points));
            /*printf("%s %s %d ", newNode.jucator[j].firstName,
                                    newNode.jucator[j].secondName,
                                    newNode.jucator[j].points);*/
        }
        addAtBeginning(&head, newNode);
    }
    fileWrite(fout, head);
    return head;
}
