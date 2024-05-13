#include <stdio.h>
#include <stdlib.h>
#include "./headers/list.h"


void fileWrite(FILE* fout, Node* head){
    while(head){
        fputs(head->echipa->numeEchipa, fout);
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
        Team* newNode=(Team*)malloc(sizeof(Team));
        fscanf(fin, "%d", &(newNode->nrPlayeri)); 
        getc(fin);//scot spatiu
        fgets(newNode->numeEchipa, sizeof(newNode->numeEchipa), fin);
        newNode->jucator=(Player*)malloc(sizeof(Player) * newNode->nrPlayeri);
        //jucatori
        for(int j=0; j<newNode->nrPlayeri; j++){
            newNode->jucator[j].firstName=(char*)malloc(sizeof(char)*50);
            newNode->jucator[j].secondName=(char*)malloc(sizeof(char)*50);
            fscanf(fin, "%s %s %d", newNode->jucator[j].firstName,
                                    newNode->jucator[j].secondName,
                                    &(newNode->jucator[j].points));
            /*printf("%s %s %d ", newNode->jucator[j].firstName,
                                    newNode->jucator[j].secondName,
                                    newNode->jucator[j].points);*/
        }
        //printf("\n");
        addAtBeginning(&head, newNode);
        //printf("%s %s %d", head->echipa->jucator->firstName, head->echipa->jucator->firstName, head->echipa->jucator->points);
        
    }
    fileWrite(fout, head);
    return head;
}
