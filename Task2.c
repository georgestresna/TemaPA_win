#include <stdio.h>
#include <stdlib.h>
#include "./headers/list.h"

void calcScor(Node** head){
    while(*head){
        (*head)->echipa->scorEchipa=0;
        for(int i=0; i<(*head)->echipa->nrPlayeri; i++){
            //punctaj echipa
            (*head)->echipa->scorEchipa += (*head)->echipa->jucator[i].points;
        }
        (*head)=(*head)->next;
    }
}

void writeTask2(FILE* fout, Node* head){
    while(head){
        fputs(head->echipa->numeEchipa, fout);
        head=head->next;
    }
}

Node* Task2(FILE* fin, FILE* fout, Node* head){

    Node* headCopy = head;
    calcScor(&head);
    head = headCopy;

    int nrEchipe;
    fscanf(fin, "%d", &nrEchipe);
    getc(fin);//skip linia cu nrEchipe

    int echipeRamase=1;
    if(nrEchipe <= 2) echipeRamase=nrEchipe;
    else while(echipeRamase*2 <= nrEchipe) echipeRamase*=2;

    while(nrEchipe > echipeRamase){
        headCopy= head;

        float scorMinim=9999;
        while(headCopy){
            if(headCopy->echipa->scorEchipa < scorMinim) scorMinim = headCopy->echipa->scorEchipa;
            headCopy=headCopy->next;
        }

        deleteNode(&head, scorMinim);
        nrEchipe--;
    }
    writeTask2(fout, head);
    /*while(head){
        printf("%s", head->echipa->numeEchipa);
        head=head->next;
    }*/
    return head;
}
